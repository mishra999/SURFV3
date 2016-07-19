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
//////////////////////////////////////////////////////////////////////////////////
module ANITA4_Trigger_Map(
		input [7:0] A1, input [7:0] A1_B,
		input [7:0] A2, input [7:0] A2_B,
		input [7:0] A3, input [7:0] A3_B,
		input [7:0] A4, input [7:0] A4_B,
		output [1:0] top_lcp_o, output [1:0] top_lcp_scaler_o,
		output [1:0] top_rcp_o, output [1:0] top_rcp_scaler_o,
		output [1:0] mid_lcp_o, output [1:0] mid_lcp_scaler_o,
		output [1:0] mid_rcp_o, output [1:0] mid_rcp_scaler_o,
		output [1:0] bot_lcp_o, output [1:0] bot_lcp_scaler_o,
		output [1:0] bot_rcp_o, output [1:0] bot_rcp_scaler_o
    );

	assign top_rcp_o[0] = A2[0]; assign top_rcp_scaler_o[0] = A2_B[0];
	assign top_lcp_o[0] = A2[1]; assign top_lcp_scaler_o[0] = A2_B[1];
	assign mid_rcp_o[0] = A2[4]; assign mid_rcp_scaler_o[0] = A2_B[4];
	assign mid_lcp_o[0] = A2[5]; assign mid_lcp_scaler_o[0] = A2_B[5];
	assign bot_rcp_o[0] = A2[6]; assign bot_rcp_scaler_o[0] = A2_B[6];
	assign bot_lcp_o[0] = A2[7]; assign bot_lcp_scaler_o[0] = A2_B[7];

	assign top_rcp_o[1] = A3[0]; assign top_rcp_scaler_o[1] = A3_B[0];
	assign top_lcp_o[1] = A3[1]; assign top_lcp_scaler_o[1] = A3_B[1];
	assign mid_rcp_o[1] = A3[4]; assign mid_rcp_scaler_o[1] = A3_B[4];
	assign mid_lcp_o[1] = A3[5]; assign mid_lcp_scaler_o[1] = A3_B[5];
	assign bot_rcp_o[1] = A3[6]; assign bot_rcp_scaler_o[1] = A3_B[6];
	assign bot_lcp_o[1] = A3[7]; assign bot_lcp_scaler_o[1] = A3_B[7];

endmodule
