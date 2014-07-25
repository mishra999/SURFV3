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
module TOP_v38(
		input nADS,
		input WnR,
		input nRD,
		inout [31:0] LD,
		input [7:2] LA,
		input nCS2,
		input nCS3,
		output nREADY,
		output nBTERM,
		
		input BCLKO,
		output LCLK,
		input CLK125_P,
		input CLK125_N,
		input CMD_P,
		input CMD_N,
		input [3:0] HOLD_P,
		input [3:0] HOLD_N,
		
		// LAB innputs.
		output 		 A_GCK,
		output		 A_GCCLR,
		output		 A_RAMP,
		output [3:0] A_CS,
		output [7:0] A_S,
		output 		 A_SELMAIN,
		output 		 A_SELTAIL,
		output 		 A_NRUN,
		input 		 A_HITBUS,
		input 		 A_RCO,
		input [11:0] A_DAT,
		output		 A_TREF_P,
		output		 A_TREF_N,
		
		output 		 B_GCK,
		output		 B_GCCLR,
		output		 B_RAMP,
		output [3:0] B_CS,
		output [7:0] B_S,
		output 		 B_SELMAIN,
		output 		 B_SELTAIL,
		output 		 B_NRUN,
		input 		 B_HITBUS,
		input 		 B_RCO,
		input [11:0] B_DAT,
		output		 B_TREF_P,
		output		 B_TREF_N,

		output 		 C_GCK,
		output		 C_GCCLR,
		output		 C_RAMP,
		output [3:0] C_CS,
		output [7:0] C_S,
		output 		 C_SELMAIN,
		output 		 C_SELTAIL,
		output 		 C_NRUN,
		input 		 C_HITBUS,
		input 		 C_RCO,
		input [11:0] C_DAT,
		output		 C_TREF_P,
		output		 C_TREF_N,

		output 		 D_GCK,
		output		 D_GCCLR,
		output		 D_RAMP,
		output [3:0] D_CS,
		output [7:0] D_S,
		output 		 D_SELMAIN,
		output 		 D_SELTAIL,
		output 		 D_NRUN,
		input 		 D_HITBUS,
		input 		 D_RCO,
		input [11:0] D_DAT,
		output		 D_TREF_P,
		output		 D_TREF_N,
		
		// Unuseds.
		output [3:0] CALSNH,
		output [3:0] TCS,
		output [3:0] RSS		
    );

	// Global clocks.
	
	wire clk33;
	wire clk100;
	wire clk125;

	// Clock output.
	wire [3:0] TREF_P;
	wire [3:0] TREF_N;
	assign A_TREF_P = TREF_P[0]; assign A_TREF_N = TREF_N[0];
	assign B_TREF_P = TREF_P[1]; assign B_TREF_N = TREF_N[1];
	assign C_TREF_P = TREF_P[2]; assign C_TREF_N = TREF_N[2];
	assign D_TREF_P = TREF_P[3]; assign D_TREF_N = TREF_N[3];
	
	// TURF HOLD inputs
	wire [3:0] HOLD;

	// Global reset.
	
	wire clr_all;

	// MESSv2 <-> LAB_TOPv2 interface.
	wire [3:0] 		lab_digitize;
	wire [12:0] 	lab_addr;
	wire [31:0] 	lab_dat;
	wire 				lab_ready;


	SURF_infrastructure #(.REF_CLOCK("125MHZ")) u_infrastructure( .clk33_o(clk33),
																					 .clk100_o(clk100),
																					 .clk125_o(clk125),
																					 .CLK125_P(CLK125_P),.CLK125_N(CLK125_N),
																					 .LCLK(LCLK),
																					 .BCLKO(BCLKO),
																					 .CMD_P(CMD_P),.CMD_N(CMD_N),.CMD(command),
																					 .HOLD_P(HOLD_P),.HOLD_N(HOLD_N),.HOLD(HOLD),
																					 .TREF_P(TREF_P),.TREF_N(TREF_N));
	

	wire [34:0] lab_debug;

	// LAB readout and memory.
	LAB_TOPv2 u_labtop( .clk_i(clk33),
							  .clk100_i(clk100),
							  .rst_i(clr_all),
							  .hold_i(HOLD),
							  .digitize_i(lab_digitize),
							  .addr_i(lab_addr),
							  .dat_o(lab_dat),
							  .done_o(lab_ready),
							  .A_SELTAIL(A_SELTAIL),
							  .A_SELMAIN(A_SELMAIN),
							  .A_GCK(A_GCK),
							  .A_RAMP(A_RAMP),
							  .A_GCCLR(A_GCCLR),
							  .A_NRUN(A_NRUN),
							  .A_CS(A_CS),
							  .A_S(A_S),
							  .A_HITBUS(A_HITBUS),
							  .A_RCO(A_RCO),
							  .A_DAT(A_DAT),
							  
							  .B_SELTAIL(B_SELTAIL),
							  .B_SELMAIN(B_SELMAIN),
							  .B_GCK(B_GCK),
							  .B_RAMP(B_RAMP),
							  .B_GCCLR(B_GCCLR),
							  .B_NRUN(B_NRUN),
							  .B_CS(B_CS),
							  .B_S(B_S),
							  .B_HITBUS(B_HITBUS),
							  .B_RCO(B_RCO),
							  .B_DAT(B_DAT),

							  .C_SELTAIL(C_SELTAIL),
							  .C_SELMAIN(C_SELMAIN),
							  .C_GCK(C_GCK),
							  .C_RAMP(C_RAMP),
							  .C_GCCLR(C_GCCLR),
							  .C_NRUN(C_NRUN),
							  .C_CS(C_CS),
							  .C_S(C_S),
							  .C_HITBUS(C_HITBUS),
							  .C_RCO(C_RCO),
							  .C_DAT(C_DAT),

							  .D_SELTAIL(D_SELTAIL),
							  .D_SELMAIN(D_SELMAIN),
							  .D_GCK(D_GCK),
							  .D_RAMP(D_RAMP),
							  .D_GCCLR(D_GCCLR),
							  .D_NRUN(D_NRUN),
							  .D_CS(D_CS),
							  .D_S(D_S),
							  .D_HITBUS(D_HITBUS),
							  .D_RCO(D_RCO),
							  .D_DAT(D_DAT),
							  .debug_o(lab_debug)
		);

	// MESS debugging.
	wire [34:0] debug;
	wire [4:0] rfp_addr;
	// PLX/register interface
	MESSv2 u_mess(		  .clk_i(clk33),
							  .cmd_i(command),
							  .lab_dat_i(lab_dat),
							  .lab_ready_i(lab_ready),
							  .lab_addr_o(lab_addr),
							  .lab_digitize_o(lab_digitize),

							  .rfp_dat_i(rfp_addr),
							  .rfp_addr_o(rfp_addr),
							  .clr_all_o(clr_all),
							  
							  .nADS(nADS),
							  .WnR(WnR),
							  .LA(LA),
							  .LD(LD),
							  .nCS2(nCS2),
							  .nCS3(nCS3),
							  .nRD(nRD),
							  .nREADY(nREADY),
							  .nBTERM(nBTERM),
							  .debug_o(debug)
	);
	
	// ChipScope debugging cores.
	wire [35:0] ila_control;
	cs_icon u_icon(.CONTROL0(ila_control));
	cs_ila u_ila(.CONTROL(ila_control),.CLK(clk33),.TRIG0(debug));

	// Unused LAB test crap.
	// CALSNH = VCC
	// RSS = VCC
	// TCS = GND
	assign CALSNH = {4{1'b1}};
	assign RSS = {4{1'b1}};
	assign TCS = {4{1'b0}};
	
endmodule
