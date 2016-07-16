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
module ANITA4_L1_TRIGGER_PIPE(
		input         REF_PULSE,
		input         CLK,
		input   [1:0] BOTTOM,  //1:L - 0:R for BOTTOM, MIDDLE, TOP
		input   [1:0] MIDDLE,
		input   [1:0] TOP,
		input   [2:0] MASK,  //Indices = top-middle-bottom : 2-1-0
		output  [5:0] ANT_HITS, //indiv. l+r, from sync'ed trig. Indices= top_l, top_r, mid_l,... 
		output  [2:0] L1,   //L+R coincidence. Indices = top-middle-bottom : 2-1-0 
		output  [2:0] ONESHOTS_DEBUG, // 0: mid-bot, 1: bot-top, 2: mid-top
		output        L2 //L2 trigger for single phi-sector
		);

	wire LCLK = CLK;
	
	//antenna-level trigger L + R 
	wire [2:0] trig_sync_bottom_r; //bit 0 on all of these is meta-stable 
	wire [2:0] trig_sync_bottom_l;
	
	wire [2:0] trig_sync_middle_r;
	wire [2:0] trig_sync_middle_l;
	
	wire [2:0] trig_sync_top_r;
	wire [2:0] trig_sync_top_l;
	
	localparam SYNC_RESET_BIT = 2; //bit in above registers used to clear
	localparam SYNC_COINC_BIT = 1; //bit in above registers used in downstream trigger

	//I/O's: (antenna trigger [falling edge], clock, reset, 2-bit trig sync register)
	ANITA4_trig_single_pol bot_r(BOTTOM[0], LCLK, trig_sync_bottom_r[SYNC_RESET_BIT], trig_sync_bottom_r); 
	ANITA4_trig_single_pol bot_l(BOTTOM[1], LCLK, trig_sync_bottom_l[SYNC_RESET_BIT], trig_sync_bottom_l); 

	 ANITA4_trig_single_pol mid_r(MIDDLE[0], LCLK, trig_sync_middle_r[SYNC_RESET_BIT], trig_sync_middle_r); 
	ANITA4_trig_single_pol mid_l(MIDDLE[1], LCLK, trig_sync_middle_l[SYNC_RESET_BIT], trig_sync_middle_l); 

	ANITA4_trig_single_pol top_r(TOP[0], LCLK, trig_sync_top_r[SYNC_RESET_BIT], trig_sync_top_r); 
	ANITA4_trig_single_pol top_l(TOP[1], LCLK, trig_sync_top_l[SYNC_RESET_BIT], trig_sync_top_l); 

	//antenna-level trigger logic
	wire bottom_lr;
	wire middle_lr;
	wire top_lr;
	
	//form L1 triggers here: L-R coincidence at each antenna
	assign bottom_lr = ((trig_sync_bottom_r[SYNC_COINC_BIT] && trig_sync_bottom_l[SYNC_COINC_BIT]) ||
							 (trig_sync_bottom_r[SYNC_COINC_BIT] && trig_sync_bottom_l[SYNC_COINC_BIT+1]) ||
							 (trig_sync_bottom_r[SYNC_COINC_BIT+1] && trig_sync_bottom_l[SYNC_COINC_BIT]));
	
	assign middle_lr = ((trig_sync_middle_r[SYNC_COINC_BIT] && trig_sync_middle_l[SYNC_COINC_BIT]) ||
							 (trig_sync_middle_r[SYNC_COINC_BIT] && trig_sync_middle_l[SYNC_COINC_BIT+1]) ||
							 (trig_sync_middle_r[SYNC_COINC_BIT+1] && trig_sync_middle_l[SYNC_COINC_BIT]));
 
	assign top_lr    = ((trig_sync_top_r[SYNC_COINC_BIT] && trig_sync_top_l[SYNC_COINC_BIT]) ||
							 (trig_sync_top_r[SYNC_COINC_BIT] && trig_sync_top_l[SYNC_COINC_BIT+1]) ||
							 (trig_sync_top_r[SYNC_COINC_BIT+1] && trig_sync_top_l[SYNC_COINC_BIT]));

	assign L1 = {top_lr, middle_lr, bottom_lr};
	
	assign ANT_HITS = {	trig_sync_top_l[SYNC_COINC_BIT], trig_sync_top_r[SYNC_COINC_BIT],
								trig_sync_middle_l[SYNC_COINC_BIT], trig_sync_middle_r[SYNC_COINC_BIT],
								trig_sync_bottom_l[SYNC_COINC_BIT], trig_sync_bottom_r[SYNC_COINC_BIT]};
	
	//phi-sector, L2 trigger 
	localparam MID_TOP_WINDOW = 3;  //clock cycles for middle-top ring trig window (3 * 4 ns = 12ns)
	localparam BOT_TOP_WINDOW = 4;  //clock cycles for bottom-top ring trig window (4 * 4 ns = 16ns)

	localparam MID_TOP_SR_LENGTH = MID_TOP_WINDOW+1; //add 1 clock cycle for 'synchronous slop'
	localparam BOT_TOP_SR_LENGTH = BOT_TOP_WINDOW+1; //add 1 clock cycle for 'synchronous slop'

	localparam MID_SR_TAP_BIT = 1; //tap on s.r. to start middle-top window
	localparam BOT_SR_TAP_BIT = 1; //tap on s.r. to start bottom-top window
	
 	reg [MID_TOP_SR_LENGTH-1:0] mid_top_sr = {MID_TOP_SR_LENGTH{1'b0}}; //shift register for mid-top
	reg [BOT_TOP_SR_LENGTH-1:0] bot_top_sr = {BOT_TOP_SR_LENGTH{1'b0}}; //shift register for bot-top
	
	reg L2_mb     = 1'b0; //L2 mid-bottom coincidence
	reg reset_mid = 1'b0;
	reg reset_bot = 1'b0;
	
	always @(posedge LCLK) begin
		
		//bottom-top window:
		//(sr is reset when last bit in sr goes high)
		reset_bot <= bot_top_sr[BOT_TOP_SR_LENGTH-2] || ~MASK[0];

		if (reset_bot)
			bot_top_sr[0] <= 1'b0;
		else if (bottom_lr)  //toggle zeroth bit on bottom antenna l-r coinc.
			bot_top_sr[0] <= 1'b1;
			
		if (reset_bot)
			bot_top_sr[BOT_TOP_SR_LENGTH-1:1]  <= {(BOT_TOP_SR_LENGTH-1){1'b0}};
		else
			bot_top_sr[BOT_TOP_SR_LENGTH-1:1]  <= bot_top_sr[BOT_TOP_SR_LENGTH-2:0];

		//middle-top window:
		reset_mid <= mid_top_sr[MID_TOP_SR_LENGTH-2] || ~MASK[1];

		if (reset_mid)
			mid_top_sr[0] <= 1'b0;
		else if (middle_lr) //toggle zeroth bit on middle antenna l-r coinc.
			mid_top_sr[0] <= 1'b1;
			
		if (reset_mid)
			mid_top_sr[MID_TOP_SR_LENGTH-1:1]  <= {(MID_TOP_SR_LENGTH-1){1'b0}};
		else
			mid_top_sr[MID_TOP_SR_LENGTH-1:1]  <= mid_top_sr[MID_TOP_SR_LENGTH-2:0];

		//L2 mid + bottom one-clock-cycle coincidence 
		L2_mb <= ((bot_top_sr[BOT_TOP_SR_LENGTH-2] && mid_top_sr[MID_TOP_SR_LENGTH-2]) ||
					 (bot_top_sr[BOT_TOP_SR_LENGTH-2] && mid_top_sr[MID_TOP_SR_LENGTH-1]) ||
					 (bot_top_sr[BOT_TOP_SR_LENGTH-1] && mid_top_sr[MID_TOP_SR_LENGTH-2]));

	end

	assign ONESHOTS_DEBUG[0] = L2_mb;
	assign ONESHOTS_DEBUG[1] = bot_top_sr[BOT_SR_TAP_BIT];
	assign ONESHOTS_DEBUG[2] = mid_top_sr[MID_SR_TAP_BIT];	
	//form L2 trigger here
	
	//L2 defined as 2 outta 3 of the oneshots:
	//(top l-r coincidence) AND ( (middleLR one-shot window) OR (bottomLR one-shot window) )
	// OR (middleLR + bottomLR tight coincidence)
	
	//wire L2;   
	assign L2 = top_lr && (bot_top_sr[BOT_SR_TAP_BIT] || mid_top_sr[MID_SR_TAP_BIT]) || L2_mb;

endmodule 