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
module ANITA4_dual_L1_trigger(
		input [1:0] TOP_LCP,
		input [1:0] TOP_RCP,
		input [1:0] MID_LCP,
		input [1:0] MID_RCP,
		input [1:0] BOT_LCP,
		input [1:0] BOT_RCP,
		input [11:0] mask_i,
		input [11:0] force_i,
		output [5:0] L1_scaler_o,
		output [1:0] L2_scaler_o,
		
		input clk_i,
		input mclk_i,
		output [3:0] trig_o
    );

	// Bit 0 on these is the oneshot.
	// Bit 1 indicates the last clock in the oneshot. This is used to hold off the
//	// coincidence to its proper length when the two are timed right.
	wire [1:0] trig_sync_bottom_r[1:0]; //bit 0 on all of these is meta-stable 
	wire [1:0] trig_sync_bottom_l[1:0];
	
	wire [1:0] trig_sync_middle_r[1:0];
	wire [1:0] trig_sync_middle_l[1:0];
	
	wire [1:0] trig_sync_top_r[1:0];
	wire [1:0] trig_sync_top_l[1:0];
	
	wire [2:0] L1_logic[1:0];
	
	localparam L0_ONESHOT_LENGTH = 1;

	localparam TOP = 2;
	localparam MID = 1;
	localparam BOT = 0;

	//I/O's: (antenna trigger [falling edge], clock, reset, 2-bit trig sync register)
	generate
		genvar i;
		for (i=0;i<2;i=i+1) begin : PHI_L0
			ANITA4_trig_single_pol_fast_retrig #(.ONESHOT(L0_ONESHOT_LENGTH)) 
					u_bot_r(.CLK(clk_i),.MASK(mask_i[6*i+0]),.FORCE(force_i[6*i+0]),
							  .TRIG(BOT_RCP[i]),.TRIG_SYNC(trig_sync_bottom_r[i]));													 
			ANITA4_trig_single_pol_fast_retrig #(.ONESHOT(L0_ONESHOT_LENGTH)) 
					u_bot_l(.CLK(clk_i),.MASK(mask_i[6*i+1]),.FORCE(force_i[6*i+1]),
							  .TRIG(BOT_LCP[i]),.TRIG_SYNC(trig_sync_bottom_l[i]));													 
			ANITA4_trig_single_pol_fast_retrig #(.ONESHOT(L0_ONESHOT_LENGTH)) 
					u_mid_r(.CLK(clk_i),.MASK(mask_i[6*i+2]),.FORCE(force_i[6*i+2]),
							  .TRIG(MID_RCP[i]),.TRIG_SYNC(trig_sync_middle_r[i]));													 
			ANITA4_trig_single_pol_fast_retrig #(.ONESHOT(L0_ONESHOT_LENGTH)) 
					u_mid_l(.CLK(clk_i),.MASK(mask_i[6*i+3]),.FORCE(force_i[6*i+3]),
							  .TRIG(MID_LCP[i]),.TRIG_SYNC(trig_sync_middle_l[i]));													 
			ANITA4_trig_single_pol_fast_retrig #(.ONESHOT(L0_ONESHOT_LENGTH)) 
					u_top_r(.CLK(clk_i),.MASK(mask_i[6*i+4]),.FORCE(force_i[6*i+4]),
							  .TRIG(TOP_RCP[i]),.TRIG_SYNC(trig_sync_top_r[i]));													 
			ANITA4_trig_single_pol_fast_retrig #(.ONESHOT(L0_ONESHOT_LENGTH)) 
					u_top_l(.CLK(clk_i),.MASK(mask_i[6*i+5]),.FORCE(force_i[6*i+5]),
							  .TRIG(TOP_LCP[i]),.TRIG_SYNC(trig_sync_top_l[i]));													 
			// The single pol outputs are 2 clocks: bit 0 is the oneshot, and bit 1 indicates
			// the last bit in the oneshot. The oneshots are 1 clock longer than their nominal
			// length to allow for coincidences across a clock boundary.
			//
			// A "4 ns oneshot" therefore means that any 2 signals within 4 ns of each other
			// will meet this coincidence. Signals separated by 6 ns will meet this coincidence
			// 50% of the time. Signals separated by 8 ns will essentially never meet this
			// coincidence.
			//
			// True comparator/clock jitter will smooth things out a bit more.
			//
			// Bit 1 allows for truncating the oneshot to always be 4 ns max.
			assign L1_logic[i][BOT] = (trig_sync_bottom_r[i][0] && trig_sync_bottom_l[i][0]) &&
											 !(trig_sync_bottom_r[i][1] && trig_sync_bottom_l[i][1]);
			assign L1_logic[i][MID] = (trig_sync_middle_r[i][0] && trig_sync_middle_l[i][0]) &&
											 !(trig_sync_middle_r[i][1] && trig_sync_middle_l[i][1]);
			assign L1_logic[i][TOP] = (trig_sync_top_r[i][0] && trig_sync_top_l[i][0]) &&
											 !(trig_sync_top_r[i][1] && trig_sync_top_l[i][1]);											 											 
		end
	endgenerate
	
	//% L2 Pipelines.
	//%
	//% Middle/bottom are first delayed relative to top by 1 cycle.
	//% A middle trigger followed by a top within 8 ns causes a trigger. So we generate an 8 ns oneshot for middle/top.
	//% plus 1 clock cycle extra for clock slop.
	//%
	//% A bottom trigger followed by a top within 12 ns causes a trigger. So we generate a 12 ns oneshot for top/bottom.
	//% plus 1 clock cycle extra for clock slop.
	//%
	//% Middle/bottom are coincidenced with a 4 ns window. This is done using the delay register and the oneshot:
	//% if (mid_delay & bot_delay || mid_delay & bot_oneshot || mid_oneshot & bot_delay).
	//%
	//% An L2 trigger then outputs a 12 ns oneshot to coincidence with adjacent phi sectors.
	
	//% Coincidence window, in 4 ns chunks, between mid & top.
	localparam MID_TOP_WINDOW = 2;
	//% Shift register length. Add 1 for slop.
	localparam MID_TOP_SR_LENGTH = MID_TOP_WINDOW + 1;
	
	//% Coincidence window, in 4 ns chunks, between bot & top.
	localparam BOT_TOP_WINDOW = 3;
	//% Shift register length. Add 1 for slop.
	localparam BOT_TOP_SR_LENGTH = BOT_TOP_WINDOW + 1;

	reg [1:0] L1_top = {2{1'b0}};
	
	reg [MID_TOP_SR_LENGTH-1:0] mid_top_sr_0 = {MID_TOP_SR_LENGTH{1'b0}};
	(* EQUIVALENT_REGISTER_REMOVAL = "FALSE" *)
	reg mid_top_coincidence_0 = 0;

	reg [MID_TOP_SR_LENGTH-1:0] mid_top_sr_1 = {MID_TOP_SR_LENGTH{1'b0}};
	(* EQUIVALENT_REGISTER_REMOVAL = "FALSE" *)
	reg mid_top_coincidence_1 = 0;
	
	reg [BOT_TOP_SR_LENGTH-1:0] bot_top_sr_0 = {BOT_TOP_SR_LENGTH{1'b0}};
	(* EQUIVALENT_REGISTER_REMOVAL = "FALSE" *)
	reg bot_top_coincidence_0 = 0;
	
	reg [BOT_TOP_SR_LENGTH-1:0] bot_top_sr_1 = {BOT_TOP_SR_LENGTH{1'b0}};
	(* EQUIVALENT_REGISTER_REMOVAL = "FALSE" *)
	reg bot_top_coincidence_1 = 0;
	
	// Delay registers.
	reg [1:0] mid_delay_0 = 2'b00;
	reg [1:0] mid_delay_1 = 2'b00;
	reg [1:0] bot_delay_0 = 2'b00;
	reg [1:0] bot_delay_1 = 2'b00;
	
	//% Oneshots!
	//% The first bit goes high when a trigger occurs, and then resets when the oneshot
	//% closes. The mid/bottom coincidence is picked off as a rising edge of the first
	//% step in the oneshot.
	always @(posedge clk_i) begin
		// Tops just get reregistered, so we can compare
		// a registered top to the mid and bottom oneshots.
		L1_top[0] <= L1_logic[0][TOP];
		L1_top[1] <= L1_logic[1][TOP];

		// Middle/top delays.
		// 2-clock oneshot (8 ns).
		// clk	L1_logic	delay[0]	delay[1]
		// 0     1        0			0
		// 1     0        1			0
		// 2		0			1			1
		// 3		0			0			0

		if (mid_delay_0[1]) mid_delay_0 <= {2{1'b0}};
		else begin
			if (L1_logic[0][MID]) mid_delay_0[0] <= 1;
			mid_delay_0[1] <= mid_delay_0[0];
		end
		if (mid_delay_1[1]) mid_delay_1 <= {2{1'b0}};
		else begin
			if (L1_logic[1][MID]) mid_delay_1[0] <= 1;
			mid_delay_1[1] <= mid_delay_1[0];
		end

		if (bot_delay_0[1]) bot_delay_0 <= {2{1'b0}};
		else begin
			if (L1_logic[0][BOT]) bot_delay_0[0] <= 1;
			bot_delay_0[1] <= bot_delay_0[0];
		end
		if (bot_delay_1[1]) bot_delay_1 <= {2{1'b0}};
		else begin
			if (L1_logic[1][BOT]) bot_delay_1[0] <= 1;
			bot_delay_1[1] <= bot_delay_1[0];
		end


		// Oneshot shift registers. When L1_logic goes high, it sets the
		// first oneshot, and it propagates down the line, until it resets the whole shebang.
		if (mid_top_sr_0[MID_TOP_SR_LENGTH-1])
			mid_top_sr_0 <= {MID_TOP_SR_LENGTH{1'b0}};
		else if (mid_delay_0[0]) begin
			mid_top_sr_0[0] <= 1;
			mid_top_sr_0[MID_TOP_SR_LENGTH-1:1] <= mid_top_sr_0[MID_TOP_SR_LENGTH-2:0];
		end else
			mid_top_sr_0[MID_TOP_SR_LENGTH-1:1] <= mid_top_sr_0[MID_TOP_SR_LENGTH-2:0];

		if (mid_top_sr_0[MID_TOP_SR_LENGTH-1])
			mid_top_coincidence_0 <= 0;
		else if (mid_delay_0[0])
			mid_top_coincidence_0 <= 1;

		if (mid_top_sr_1[MID_TOP_SR_LENGTH-1])
			mid_top_sr_1 <= {MID_TOP_SR_LENGTH{1'b0}};
		else if (mid_delay_1[0]) begin
			mid_top_sr_1[0] <= 1;
			mid_top_sr_1[MID_TOP_SR_LENGTH-1:1] <= mid_top_sr_1[MID_TOP_SR_LENGTH-2:0];
		end else
			mid_top_sr_1[MID_TOP_SR_LENGTH-1:1] <= mid_top_sr_1[MID_TOP_SR_LENGTH-2:0];

		if (mid_top_sr_1[MID_TOP_SR_LENGTH-1])
			mid_top_coincidence_1 <= 0;
		else if (mid_delay_1[0])
			mid_top_coincidence_1 <= 1;



		// Ditto for bottom/top.
		if (bot_top_sr_0[BOT_TOP_SR_LENGTH-1])
			bot_top_sr_0 <= {BOT_TOP_SR_LENGTH{1'b0}};
		else if (bot_delay_0[0]) begin
			bot_top_sr_0[0] <= 1;
			bot_top_sr_0[BOT_TOP_SR_LENGTH-1:1] <= bot_top_sr_0[BOT_TOP_SR_LENGTH-2:0];
		end else
			bot_top_sr_0[BOT_TOP_SR_LENGTH-1:1] <= bot_top_sr_0[BOT_TOP_SR_LENGTH-2:0];

		if (bot_top_sr_0[BOT_TOP_SR_LENGTH-1])
			bot_top_coincidence_0 <= 0;
		else if (bot_delay_0[0])
			bot_top_coincidence_0 <= 1;



		if (bot_top_sr_1[BOT_TOP_SR_LENGTH-1])
			bot_top_sr_1 <= {BOT_TOP_SR_LENGTH{1'b0}};
		else if (bot_delay_1[0]) begin
			bot_top_sr_1[0] <= 1;
			bot_top_sr_1[BOT_TOP_SR_LENGTH-1:1] <= bot_top_sr_1[BOT_TOP_SR_LENGTH-2:0];
		end else
			bot_top_sr_1[BOT_TOP_SR_LENGTH-1:1] <= bot_top_sr_1[BOT_TOP_SR_LENGTH-2:0];		

		if (bot_top_sr_1[BOT_TOP_SR_LENGTH-1])
			bot_top_coincidence_1 <= 0;
		else if (bot_delay_1[0])
			bot_top_coincidence_1 <= 1;
		
	end
		
	// The registered versions of the L1 flags are:
	// L1_top[0], L1_top[1]
	// mid_delay_0, mid_delay_1
	// bot_delay_0, bot_delay_1
	// We'll put those into the scalers as
	// top, middle, bottom for phi 0
	// top, middle, bottom for phi 1
	wire [5:0] L1_flags = { L1_top[0], mid_delay_0[0], bot_delay_0[0], L1_top[1], mid_delay_1[0], bot_delay_1[0] };
	generate
		genvar L1_i;
		for (L1_i=0;L1_i<6;L1_i=L1_i+1) begin : L1_SCALER_LOOP
			flag_sync u_scaler_sync(.in_clkA(L1_flags[L1_i]), .clkA(clk_i),
											.out_clkB(L1_scaler_o[L1_i]),.clkB(mclk_i));
		end
	endgenerate
		
		
	// L2s.
	reg [1:0] L2_bot_mid = {2{1'b0}};
	wire [1:0] L2_top_bot;
	wire [1:0] L2_top_mid;

	wire [1:0] L2_all;

	// Merge the shift registers.
	wire [1:0] bot_sr[1:0];
	assign bot_sr[0] = bot_delay_0;
	assign bot_sr[1] = bot_delay_1;
	// Merge the shift registers.
	wire [1:0] mid_sr[1:0];
	assign mid_sr[0] = mid_delay_0;
	assign mid_sr[1] = mid_delay_1;
	
	wire [1:0] mid_coincidence_with_top = {mid_top_coincidence_1,
														mid_top_coincidence_0};
	wire [1:0] bot_coincidence_with_top = {bot_top_coincidence_1,
														bot_top_coincidence_0};
	reg [1:0] L2_all_reg = 2'b00;
	// (* IOB = "FORCE" *) //by me
	reg [1:0] L2 = {2{1'b0}};
	wire [1:0] L2_reset;
	
	generate
		genvar L2_i;
		for (L2_i=0;L2_i<2;L2_i=L2_i+1) begin : L2_PHI
			reg [2:0] L2_reset_sr = {3{1'b0}};
			
			always @(posedge clk_i) begin : L2_BOT_MID_REG
				L2_bot_mid[L2_i] <= (mid_sr[L2_i][0] && bot_sr[L2_i][0]);
			end
			assign L2_top_mid[L2_i] = (mid_coincidence_with_top[L2_i] && L1_top[L2_i]);
			assign L2_top_bot[L2_i] = (bot_coincidence_with_top[L2_i] && L1_top[L2_i]);
			
			assign L2_all[L2_i] = L2_bot_mid[L2_i] || L2_top_mid[L2_i] || L2_top_bot[L2_i];
			always @(posedge clk_i) begin : L2_PHI_REG
				L2_all_reg[L2_i] <= L2_all[L2_i];
			
				if (L2_reset_sr[2]) L2[L2_i] <= 0;
				else if (L2_all_reg[L2_i]) L2[L2_i] <= 1;
				
				if (L2_reset_sr[2]) L2_reset_sr <= {3{1'b0}};
				else L2_reset_sr <= {L2_reset_sr[1:0],L2_all_reg[L2_i]};
			end
			flag_sync u_L2_scaler(.in_clkA(L2_reset_sr[2]),.clkA(clk_i),
										 .out_clkB(L2_scaler_o[L2_i]),.clkB(mclk_i));
		end
	endgenerate
	
	assign trig_o[0] = L2[0];
	assign trig_o[1] = 0;
	assign trig_o[2] = L2[1];
	assign trig_o[3] = 0;
endmodule
