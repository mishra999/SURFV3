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

module ANITA_L0_scalers(
		input mclk_i,
		input clk100_i,
		input [1:0] top_lcp_i,
		input [1:0] top_rcp_i,
		input [1:0] mid_lcp_i,
		input [1:0] mid_rcp_i,
		input [1:0] bot_lcp_i,
		input [1:0] bot_rcp_i,
		output [11:0] scaler_o
    );

	// The scalers, like the DACs, went
	// TV, MV, BV, TV, MV, BV, TH, MH, BH, TH, MH, BH.
	// That is, they went:
	// ANT_B 0,4,6
	// ANT_C 0,4,6
	// ANT_B 1,5,7
	// ANT_C 1,5,7
	// So that's what we're doing again.
	// The new mapping is
	// TR, MR, BR, TR, MR, BR, TL, ML, BL, TL, ML, BL.
	
	wire [11:0] L0_all;

	assign L0_all[0] = top_rcp_i[0];
	assign L0_all[1] = mid_rcp_i[0];
	assign L0_all[2] = bot_rcp_i[0];
	assign L0_all[3] = top_rcp_i[1];
	assign L0_all[4] = mid_rcp_i[1];
	assign L0_all[5] = bot_rcp_i[1];
	assign L0_all[6] = top_lcp_i[0];
	assign L0_all[7] = mid_lcp_i[0];
	assign L0_all[8] = bot_lcp_i[0];
	assign L0_all[9] = top_lcp_i[1];
	assign L0_all[10]= mid_lcp_i[1];
	assign L0_all[11]= bot_lcp_i[1];
	
	generate
		genvar i;
		for (i=0;i<12;i=i+1) begin : L0_SCALERS
			L0_scaler_single u_scaler_100Mhz(.clk100_i(clk100_i),
														.mclk_i(mclk_i),
														.trig_i(L0_all[i]),
														.pulse_o(scaler_o[i]));
		end
	endgenerate
	
endmodule
