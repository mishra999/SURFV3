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
// The v2 version works at 1/8th the clock rate, to comfortably accept arbitrary
// jitter and phase difference between transmitter/receiver. 
module SURF_command_receiver_v2( 
				   input         clk33_i,
			      input 	    rst_i,
			      input 	    cmd_i,
					output		 cmd_debug_o,
					output		 sample_o,
			      output [1:0]  event_id_buffer_o,
			      output 	    event_id_wr_o,
			      output [31:0] event_id_o,
			      output [3:0]  digitize_o );
	localparam NCLOCK_BITS = 3;
	localparam NWAIT_CLOCKS = 6;
   (* IOB = "TRUE" *)
   reg 					    	 cmd_in = 0;
	reg							 cmd_in_sync = 0;
	
   reg [1:0] 				    buf_bit = {2{1'b0}};   
   reg [31:0] 				    shift_in = {32{1'b0}};   
   reg [4:0] 				    shift_counter = {5{1'b0}};
   wire [5:0] 				    shift_counter_plus_one = shift_counter + 1;
   reg [3:0] 				    digitize_flag = {4{1'b0}};   
	reg [NCLOCK_BITS-1:0] counter = {NCLOCK_BITS{1'b0}};
	wire [NCLOCK_BITS:0] counter_plus_one = counter + 1;
   
   always @(posedge clk33_i) begin : IOB_LOGIC
      cmd_in <= cmd_i;
		cmd_in_sync <= cmd_in;
	end

   localparam FSM_BITS = 4;
   localparam [FSM_BITS-1:0] IDLE = 0;
	localparam [FSM_BITS-1:0] WAIT = 1;
   localparam [FSM_BITS-1:0] BUF_BIT_0 = 2;
   localparam [FSM_BITS-1:0] BUF_BIT_1 = 3;
   localparam [FSM_BITS-1:0] SHIFT = 4;
   localparam [FSM_BITS-1:0] DIGITIZE = 5;
   reg [FSM_BITS-1:0] state = IDLE;

	// in IDLE, we jump to WAIT immediately.
	// Then we jump to BUF_BIT_0.
	// Then we wait 4 clocks before sampling and moving on.
	always @(posedge clk33_i) begin
		if (state == IDLE) counter <= {NCLOCK_BITS{1'b0}};
		else if (state == WAIT && counter == NWAIT_CLOCKS-1) counter <= {NCLOCK_BITS{1'b0}};
		else counter <= counter + 1;
	end
	
   always @(posedge clk33_i) begin : FSM_LOGIC
      if (rst_i) state <= IDLE;
      else begin
			case (state)
				IDLE: if (cmd_in_sync) state <= WAIT;
				WAIT: if (counter == NWAIT_CLOCKS-1) state <= BUF_BIT_0;
				BUF_BIT_0: if (counter_plus_one[NCLOCK_BITS]) state <= BUF_BIT_1;
				BUF_BIT_1: if (counter_plus_one[NCLOCK_BITS]) state <= SHIFT;
				SHIFT: if (counter_plus_one[NCLOCK_BITS] && shift_counter_plus_one[5]) state <= DIGITIZE;
				DIGITIZE: if (counter_plus_one[NCLOCK_BITS]) state <= IDLE;
			endcase // case (state)
		end
	end // always @ (posedge clk33_i)
   
   always @(posedge clk33_i) begin
      if (state == BUF_BIT_0 && counter_plus_one[NCLOCK_BITS]) buf_bit[0] <= cmd_in_sync;
      if (state == BUF_BIT_1 && counter_plus_one[NCLOCK_BITS]) buf_bit[1] <= cmd_in_sync;
      if (state == SHIFT && counter_plus_one[NCLOCK_BITS]) begin
			shift_in <= {cmd_in_sync,shift_in[31:1]};
      end

		if (state == SHIFT && counter_plus_one[NCLOCK_BITS]) shift_counter <= shift_counter_plus_one;
		else if (state != SHIFT) shift_counter <= {5{1'b0}};

      if (state == DIGITIZE && counter_plus_one[NCLOCK_BITS] && !cmd_in_sync) digitize_flag[buf_bit] <= 1;
      else digitize_flag <= {4{1'b0}};      
   end

   assign digitize_o = digitize_flag;
   assign event_id_o = shift_in;
   assign event_id_wr_o = (state == DIGITIZE && !cmd_in_sync && counter_plus_one[NCLOCK_BITS]);
   assign event_id_buffer_o = buf_bit;
	assign sample_o = counter_plus_one[NCLOCK_BITS];
	assign cmd_debug_o = cmd_in_sync;
endmodule // SURF_command_receiver

   
      
	   
      
			  
   
