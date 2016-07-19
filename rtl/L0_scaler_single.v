`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////
// This file is a part of the Antarctic Impulsive Transient Antenna (ANITA)
// project, a collaborative scientific effort between multiple institutions. For
// more information, contact Peter Gorham (gorham@phys.hawaii.edu).
//
// All rights reserved.
//
// Author: Patrick Allison, Ohio State University (allison.122@osu.edu)
// Author: Eric Oberla, univ of chicago
// Author:
////////////////////////////////////////////////////////////////////////////////
module L0_scaler_single(
		input  	    clk100_i,
		input   		 mclk_i,
		input        trig_i,
		output       pulse_o,
		output       stuck_o
    );
	 
	wire pulse_async;
	reg [1:0] pulse_sync  = 2'b00; //pulse_sync[0] metastable
	reg [1:0] phase       = 2'b00;	
	reg [3:0] pulse_abcd  = 4'b0000;	 
	
	//latch on rising edge of trig
	//(* IOB = "TRUE" *)
	FDCE #(
      .INIT(1'b0)       // Initial value of register (1'b0 or 1'b1)
   ) FDCE_scaler_latch (
      .Q(pulse_async),  // Data output
      .C(trig_i),        // Clock input
      .CE(1'b1),        // Clock enable input
      .CLR(pulse_sync[1]),       // Asynchronous clear input
      .D(1'b1)         // Data input
   );	
	
	always @(posedge clk100_i) begin
	
		if(pulse_sync[1])
			pulse_sync[0] <= 0;
		else if (pulse_async)
			pulse_sync[0] <= 1;
	
		//pulse_sync[1] is a flag on one 100Mhz clk cycle
		if(pulse_sync[1])
			pulse_sync[1] <= 0;
		else
			pulse_sync[1] <=  pulse_sync[0];

		if(pulse_sync[1])
			phase <= phase + 1;
			
		pulse_abcd[0] <= pulse_sync[1] && (phase == 0); //phase == a
		pulse_abcd[1] <= pulse_sync[1] && (phase == 1); //phase == b
		pulse_abcd[2] <= pulse_sync[1] && (phase == 2); //phase == c
		pulse_abcd[3] <= pulse_sync[1] && (phase == 3); //phase == d

	end
		
	//transfer pulse_abcd[...] from 100Mhz to 33 Mhz domain
	wire [3:0] pulse_abcd_on_33MHz;
	
	generate
		genvar i;
		for (i=0;i<4;i=i+1) begin : L0_SCALER_LOOP
			flag_sync u_scaler_sync(.in_clkA(pulse_abcd[i]), .clkA(clk100_i),
											.out_clkB(pulse_abcd_on_33MHz[i]), .clkB(mclk_i));
		end
	endgenerate
	
	//check if SHORT trig is stuck
	localparam STUCK_CHECK_LENGTH = 8;
	localparam STUCK_CHECK_TAP = 7;
	reg [STUCK_CHECK_LENGTH-1:0] stuck_check = {STUCK_CHECK_LENGTH{1'b0}};
	reg trig_reg = 1'b0;
	
	always @(posedge mclk_i) begin
		trig_reg <= trig_i;
		if (~trig_reg)
			stuck_check <=  {STUCK_CHECK_LENGTH{1'b0}};
		else
			stuck_check <= {stuck_check[STUCK_CHECK_LENGTH-2:0], trig_reg};	
	end
	
	assign stuck_o = stuck_check[STUCK_CHECK_TAP];
	//************************/
	//make the OR of 4 pulse phases makes the scaler pulse to be counted
	assign pulse_o = pulse_abcd_on_33MHz[0] || pulse_abcd_on_33MHz[1] || 
						  pulse_abcd_on_33MHz[2] || pulse_abcd_on_33MHz[3] ||
						  stuck_check[STUCK_CHECK_TAP];
endmodule
