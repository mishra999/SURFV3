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
module TURF_Processor_ANITA4(
		// Raw tunnel diode inputs, non-inverted side.
		// We have 32 of these. We don't use them all.
		input [7:0] A1,
		input [7:0] A2,
		input [7:0] A3,
		input [7:0] A4,
		// Master (33 MHz) clock.
		input mclk_i,
		// Quick (250 MHz) clock.
		input clk_i,
		// Scaler (100 MHz) clock.
		input clk100_i,
		// Raw tunnel diode inputs, inverted side.
		// These are for scalers.
		input [7:0] A1_B,
		input [7:0] A2_B,
		input [7:0] A3_B,
		input [7:0] A4_B,
		// Input masks. 32 of these, we don't use them all.
		input [31:0] mask_i,
		// Reference pulse from the TURF. For masked scalers.
		input REF_PULSE,
		// Trigger outputs, to the TURF. 4 of these.
		output [3:0] TRIG,
		// Scaler outputs, to the scaler block.
		output [31:0] scal_o,
		// Monitoring outputs.
		output [2:0] MON
    );

	// Mapped triggers.
	//% Top antennas, left circular.
	wire [1:0] top_lcp;
	//% Top antennas, left circular, scaler inputs.
	wire [1:0] top_lcp_scaler;
	
	//% Top antennas, right circular.
	wire [1:0] top_rcp;
	//% Top antennas, right circular, scaler inputs.
	wire [1:0] top_rcp_scaler;
	
	//% Mid antennas, left circular.
	wire [1:0] mid_lcp;
	//% Mid antennas, left circular, scaler inputs.
	wire [1:0] mid_lcp_scaler;
	
	//% Mid antennas, right circular.
	wire [1:0] mid_rcp;
	//% Mid antennas, right circular, scaler inputs.
	wire [1:0] mid_rcp_scaler;

	//% Bot antennas, left circular.
	wire [1:0] bot_lcp;
	//% Bot antennas, left circular, scaler inputs.
	wire [1:0] bot_lcp_scaler;
	
	//% Bot antennas, right circular.
	wire [1:0] bot_rcp;
	//% Bot antennas, right circular, scaler inputs.
	wire [1:0] bot_rcp_scaler;
	
	//% Mapper to convert the 32 inputs into the 12 real outputs.
	ANITA4_Trigger_Map u_trigger_map(.A1(A1),.A2(A2),.A3(A3),.A4(A4),
												.A1_B(A1_B),.A2_B(A2_B),.A3_B(A3_B),.A4_B(A4_B),
												.top_lcp_o(top_lcp),.top_lcp_scaler_o(top_lcp_scaler),
												.top_rcp_o(top_rcp),.top_rcp_scaler_o(top_rcp_scaler),
												.mid_lcp_o(mid_lcp),.mid_lcp_scaler_o(mid_lcp_scaler),
												.mid_rcp_o(mid_rcp),.mid_rcp_scaler_o(mid_rcp_scaler),
												.bot_lcp_o(bot_lcp),.bot_lcp_scaler_o(bot_lcp_scaler),
												.bot_rcp_o(bot_rcp),.bot_rcp_scaler_o(bot_rcp_scaler));

	ANITA_L0_scalers u_scalers(.mclk_i(mclk_i),
										.clk100_i(clk100_i),
										 .top_lcp_i(top_lcp_scaler),
										 .top_rcp_i(top_rcp_scaler),
										 .mid_lcp_i(mid_lcp_scaler),
										 .mid_rcp_i(mid_rcp_scaler),
										 .bot_lcp_i(bot_lcp_scaler),
										 .bot_rcp_i(bot_rcp_scaler),
										 .scaler_o(scal_o[0 +: 12]));

	// Phi0 trigger. The name of this is legacy: it actually generates L1s and L2s.
	// Note: we're retaining single-channel trigger masks, but because all triggers require both LCP and RCP,
	// masking any single channel *or* its polarization pair is identical.
	// We don't use channel masking anyway.
	ANITA4_dual_L1_trigger u_trig_phi0(.clk_i(clk_i),.mclk_i(mclk_i),
												  .TOP_LCP(top_lcp),
												  .TOP_RCP(top_rcp),
												  .MID_LCP(mid_lcp),
												  .MID_RCP(mid_rcp),
												  .BOT_LCP(bot_lcp),
												  .BOT_RCP(bot_rcp),
												  .mask_i(mask_i[0 +: 12]),
												  .force_i(mask_i[16 +: 12]),
												  .L1_scaler_o(scal_o[12 +: 6]),
												  .L2_scaler_o(scal_o[18 +: 2]),
												  // scalers later
												  .trig_o(TRIG));
	reg ref_pulse_registered = 0;
	always @(posedge mclk_i) begin
		ref_pulse_registered <= REF_PULSE;
	end
	assign scal_o[21] = ref_pulse_registered;

endmodule
