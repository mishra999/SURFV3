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
module SCALER_TOPv2 #(parameter NUM_SCALERS=22) (
		// 33 MHz clock
		input clk33_i,
		// 'CR' output from trigger module
		input [NUM_SCALERS-1:0] scal_i,
		// Address from MESSv2
		input [4:0] scal_addr_i,
		input scal_rd_i,
		// Data to MESSv2
		output [15:0] scal_dat_o,
		// Reference pulse counter.
		output [15:0] refpulse_cnt_o
    );

	localparam REF_PULSE_INDEX = NUM_SCALERS-1;

	wire update_scalers;
	SCALER_CLOCK_v2 u_clk(.clk33_i(clk33_i),
								 .khz_clk_o(update_scalers));
	wire [15:0] scaler_data_out[31:0];
	reg [1:0] ref_pulse_reg = {2{1'b0}};
	reg [15:0] ref_pulse_counter = {16{1'b0}};
	reg [15:0] ref_pulse_count = {16{1'b0}};
	reg [NUM_SCALERS-2:0] gated_scaler = {NUM_SCALERS-1{1'b0}};
	wire [NUM_SCALERS-2:0] ref_pulse_in = {NUM_SCALERS-1{scal_i[REF_PULSE_INDEX]}};
	always @(posedge clk33_i) begin
		gated_scaler <= ref_pulse_in & scal_i[0 +: NUM_SCALERS-1];
		ref_pulse_reg <= {ref_pulse_reg[0],scal_i[REF_PULSE_INDEX]};

		if (update_scalers) ref_pulse_counter <= {16{1'b0}};
		else if (ref_pulse_reg[0] && !ref_pulse_reg[1]) ref_pulse_counter <= ref_pulse_counter + 1;

		if (update_scalers) ref_pulse_count <= ref_pulse_counter;
	end
	
	// ANITA4 Mapping:
	// Scaler 0-11 are the L0 scalers (as before).
	// Scaler 12-17 are the L1 scalers (new).
	// Scaler 18-19 are the L2 scalers (new).
	// Scaler 20 is the L3 scaler (new).
	// Scaler 21 is unused (it's the refpulse).
	// Scaler 22-27 are the gated L1 scalers (new).
	// Scaler 28-29 are the gated L2 scalers (new).
	// Scaler 30 is the gated L3 scaler (new).
	// Scaler 31 is unused.
	localparam L0_START = 0;
	localparam NUM_L0 = 12;
	localparam L1_START = 12;
	localparam L1_GATED_START = 22;
	localparam NUM_L1 = 6;
	localparam L2_START = 18;
	localparam L2_GATED_START = 28;
	localparam NUM_L2 = 2;
	localparam L3_START = 20;
	localparam L3_GATED_START = 30;
	localparam NUM_L3 = 1;
	generate
		genvar trig, ant, trig2;
		for (trig=0;trig<NUM_L1;trig=trig+1) begin : L1
			ANITA3_scaler #(.WIDTH(16),.PRESCALE(0)) u_l1_scaler(.clk_i(clk33_i),
																				  .pps_i(update_scalers),
																				  .count_i(scal_i[L1_START+trig]),
																				  .scaler_o(scaler_data_out[L1_START+trig]));
			ANITA3_scaler #(.WIDTH(16),.PRESCALE(0)) u_l1_mon_scaler(.clk_i(clk33_i),
																				  .pps_i(update_scalers),
																				  .count_i(gated_scaler[L1_START+trig]),
																				  .scaler_o(scaler_data_out[L1_GATED_START+trig]));
		end
		for (ant=0;ant<NUM_L0;ant=ant+1) begin : ANT
			ANITA3_scaler #(.WIDTH(16),.PRESCALE(0)) u_ant_scaler(.clk_i(clk33_i),
																					.pps_i(update_scalers),
																					.count_i(scal_i[L0_START+ant]),
																					.scaler_o(scaler_data_out[L0_START+ant]));
		end
		for (trig2=0;trig2<NUM_L2;trig2=trig2+1) begin : L2
			ANITA3_scaler #(.WIDTH(16),.PRESCALE(0)) u_L2_scaler(.clk_i(clk33_i),
																				  .pps_i(update_scalers),
																				  .count_i(scal_i[L2_START+trig2]),
																				  .scaler_o(scaler_data_out[L2_START+trig2]));
			ANITA3_scaler #(.WIDTH(16),.PRESCALE(0)) u_L2_mon_scaler(.clk_i(clk33_i),
																						.pps_i(update_scalers),
																						.count_i(gated_scaler[L2_START+trig2]),
																						.scaler_o(scaler_data_out[L2_GATED_START+trig2]));
		end
		ANITA3_scaler #(.WIDTH(16),.PRESCALE(0)) u_L3_scaler(.clk_i(clk33_i),
																			  .pps_i(update_scalers),
																			  .count_i(scal_i[L3_START]),
																			  .scaler_o(scaler_data_out[L3_START]));
		ANITA3_scaler #(.WIDTH(16),.PRESCALE(0)) u_L3_mon_scaler(.clk_i(clk33_i),
																			  .pps_i(update_scalers),
																			  .count_i(gated_scaler[L3_START]),
																			  .scaler_o(scaler_data_out[L3_GATED_START]));
	endgenerate
	reg scaler_bank = 0;
	reg [31:0] scaler_ram[63:0];
	reg [31:0] scaler_out;
	
	integer i;
	initial begin
		for (i=0;i<64;i=i+1) begin
			scaler_ram[i] <= {32{1'b0}};
		end
	end
	
	reg reading = 0;
	reg updating = 0;
	reg was_updating = 0;
	reg maybe_reading_too_slow = 0;
	
	reg [4:0] scaler_addr_count = {5{1'b0}};
	wire [5:0] scaler_addr_count_plus_one = scaler_addr_count + 1;
	always @(posedge clk33_i) begin	
		if (update_scalers) updating <= 1;
		else if (scaler_addr_count_plus_one[5]) updating <= 0;
		
		if (updating) scaler_addr_count <= scaler_addr_count_plus_one;
		
		if (updating) 
			scaler_ram[{scaler_bank,scaler_addr_count}] <= {ref_pulse_count,scaler_data_out[scaler_addr_count]};
		scaler_out <= scaler_ram[{!scaler_bank,scal_addr_i}];


		// Once we start reading, we won't switch banks to present
		// until we stop. If we take more than 1 ms to read out,
		// we just go ahead and do it anyway.

		// So if we have:
		// (1 ms) bank 1 -> bank 0
		// start reading from bank 1   (reading = 1)
		// (1 ms tick) ... (maybe_reading_too_slow = 1)
		// stays in bank 1 (overwrite bank 0)
		// reading finishes (maybe_reading_too_slow = 0, reading = 0)
		// (1 ms tick) bank 0 -> bank 1
		//
		// But if we get:
		// (1 ms) bank 1 -> bank 0
		// start reading from bank 1 (reading = 1)
		// (1 ms tick) ... (maybe_reading_too_slow = 1)
		// stays in bank 1 (overwrite bank 0)
		// (1 ms tick)  (reading = 0, overwrite bank 0)
		// (1 ms tick)  bank 1 -> bank 0
		//  finish reading (maybe_reading_too_slow = 0)

		if ((scal_addr_i == {5{1'b0}}) && scal_rd_i)
			reading <= 1;
		else if ((scal_addr_i == {5{1'b1}}) && scal_rd_i) 
			reading <= 0;
		else if (update_scalers && maybe_reading_too_slow)
			reading <= 0;

		if (!reading) maybe_reading_too_slow <= 0;
		else if (update_scalers && reading) maybe_reading_too_slow <= 1;
		
		was_updating <= updating;
		
		if (!updating && was_updating && !reading) scaler_bank <= ~scaler_bank;		
	end
	
	assign scal_dat_o = scaler_out[15:0];
	assign refpulse_cnt_o = scaler_out[31:16];
endmodule
