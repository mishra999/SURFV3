`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////
// This file is a part of the Antarctic Impulsive Transient Antenna (ANITA)
// project, a collaborative scientific effort between multiple institutions. For
// more information, contact Peter Gorham (gorham@phys.hawaii.edu).
//
// All rights reserved.
//
// Author: Patrick Allison, Ohio State University (allison.122@osu.edu)
// Author:
// Author:
////////////////////////////////////////////////////////////////////////////////
module SURF_infrastructure(
		output LCLK,
		input BCLKO,
		input CLK125_P,
		input CLK125_N,
		input CMD_P,
		input CMD_N,
		input [3:0] HOLD_P,
		input [3:0] HOLD_N,
		output [3:0] TREF_P,
		output [3:0] TREF_N,
		
		output clk33_o,
		output clk100_o,
		output clk125_o,
		
		output [3:0] HOLD,
		output CMD
    );

	// The clk125 should be shoved through a DCM at 
	// some point relatively soon.

	reg [3:0] reset = 4'b0111;
	always @(posedge clk33_o) reset <= {reset[2:0],1'b0};
	
	clk100_wizard u_clk100(.CLKIN_IN(clk33_o),.RST_IN(reset[3]),.CLKFX_OUT(clk100_o));

	parameter REF_CLOCK = "33MHZ";
	wire [3:0] TREF;
	wire clk125_to_bufg;
	IBUFDS u_ibufds_clk125(.I(CLK125_P),.IB(CLK125_N),.O(clk125_to_bufg));
	BUFG u_bufg_clk125(.I(clk125_to_bufg),.O(clk125_o));
	BUFG u_bufg_clk33(.I(BCLKO),.O(clk33_o));
	// 33 MHz clock output back to the PLX.
	OFDDRRSE u_lclk_out(.C0(clk33_o),.C1(~clk33_o),
							  .D0(1'b1),.D1(1'b0),
							  .CE(1'b1),.R(1'b0),.S(1'b0),
							  .Q(LCLK));
	IBUFDS u_cmd_ibufds(.I(CMD_P),.IB(CMD_N),.O(CMD));
	
	
	generate
		genvar i;
		for (i=0;i<4;i=i+1) begin : LAB		
			if (REF_CLOCK == "33MHZ") begin : CLK33
				FDDRRSE u_refp(.C0(clk33_o),.C1(~clk33_o),
									.D0(1'b1),.D1(1'b0),
									.CE(1'b1),.R(1'b0),.S(1'b0),
									.Q(TREF[i]));
			end else begin : CLK125
				FDDRRSE u_refp(.C0(clk125_o),.C1(~clk125_o),
									.D0(1'b1),.D1(1'b0),
									.CE(1'b1),.R(1'b0),.S(1'b0),
									.Q(TREF[i]));
			end
			OBUFDS u_refp_obufds(.I(TREF[i]),.O(TREF_P[i]),			
										.OB(TREF_N[i]));
			IBUFDS u_hold_ibufds(.I(HOLD_P[i]),.IB(HOLD_N[i]),
										.O(HOLD[i]));
		end
	endgenerate
	
endmodule
