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
module SURF_command_receiver_v3(
				   input         clk33_i,
			      input 	    rst_i,
			      input 	    cmd_i,
					output		 cmd_debug_o,
					output		 sample_o,
					output 		 event_id_ok_o,
			      output [1:0]  event_id_buffer_o,
			      output 	    event_id_wr_o,
			      output [31:0] event_id_o,
			      output [3:0]  digitize_o,
					output [8:0] debug_o					);
					
	localparam [7:0] TX_HEADER = 8'hA6;
	
   (* IOB = "TRUE" *)
   reg 					    	 cmd_in = 0;
	reg							 cmd_in_sync = 0;

   localparam FSM_BITS = 3;
	localparam [FSM_BITS-1:0] IDLE = 0;
	localparam [FSM_BITS-1:0] LAB_ID = 1;
	localparam [FSM_BITS-1:0] EVENT_ID_3 = 2;
	localparam [FSM_BITS-1:0] EVENT_ID_2 = 3;
	localparam [FSM_BITS-1:0] EVENT_ID_1 = 4;
	localparam [FSM_BITS-1:0] EVENT_ID_0 = 5;
	localparam [FSM_BITS-1:0] EVENT_ID_SUM = 6;
	localparam [FSM_BITS-1:0] DONE = 7;
	reg [FSM_BITS-1:0] state = IDLE;
	
	reg [1:0] lab_id = {2{1'b0}};
	
	reg [7:0] temp_sum = {8{1'b0}};
	wire [7:0] data_out;
	// We always read data whenever it's available. This dumps any invalid characters and half-full commands,
	// searching for the header.
	wire data_available;
	
	reg sum_ok = 0;
	reg [3:0] digitize_flag = {4{1'b0}};
	
	reg [31:0] event_id_reg = {32{1'b0}};
	
	// Resets are taken care of in software: on a clear_all, triggers are disabled, 
	// the CPU waits for a short while (NOTE: This was added!) which ensures that
	// all commands are transmitted, then Clr_All is issued which dumps the
	// event buffers on both the SURF and the TURF. Then triggers are re-enabled.
	always @(posedge clk33_i) begin
		if (rst_i) state <= IDLE; 
		else case (state)
			IDLE: if (data_available && data_out == TX_HEADER) state <= LAB_ID;
			LAB_ID: if (data_available) state <= EVENT_ID_3;
			EVENT_ID_3: if (data_available) state <= EVENT_ID_2;
			EVENT_ID_2: if (data_available) state <= EVENT_ID_1;
			EVENT_ID_1: if (data_available) state <= EVENT_ID_0;
			EVENT_ID_0: if (data_available) state <= EVENT_ID_SUM;
			EVENT_ID_SUM: if (data_available) state <= DONE;
			DONE: state <= IDLE;
		endcase
		
		if (state == LAB_ID && data_available) lab_id <= data_out[1:0];
		if (state == EVENT_ID_0 && data_available) event_id_reg[7:0] <= data_out;
		if (state == EVENT_ID_1 && data_available) event_id_reg[15:8] <= data_out;
		if (state == EVENT_ID_2 && data_available) event_id_reg[23:16] <= data_out;
		if (state == EVENT_ID_3 && data_available) event_id_reg[31:24] <= data_out;
		if (data_available) begin
			if (state == LAB_ID) temp_sum <= {8{1'b0}};
			else if (state == EVENT_ID_3 || state == EVENT_ID_2 || state == EVENT_ID_1 || state == EVENT_ID_0)
				temp_sum <= temp_sum + data_out;
		end
		if (state == LAB_ID) sum_ok <= 0;
		else if (state == EVENT_ID_SUM && data_available) sum_ok <= (temp_sum == data_out);

		if (state == LAB_ID && data_available) begin
			digitize_flag[0] <= (data_out[1:0] == 2'b00);
			digitize_flag[1] <= (data_out[1:0] == 2'b01);
			digitize_flag[2] <= (data_out[1:0] == 2'b10);
			digitize_flag[3] <= (data_out[1:0] == 2'b11);
		end else begin
			digitize_flag <= {4{1'b0}};
		end
		
		cmd_in <= cmd_i;
		cmd_in_sync <= cmd_in;
	end
	
	uart_rx u_receiver(.serial_in(cmd_in_sync),
							 .data_out(data_out),
							 .read_buffer(data_available),
							 .reset_buffer(rst_i),
							 .en_16_x_baud(1'b1),
							 .buffer_data_present(data_available),
							 .buffer_full(),
							 .buffer_half_full(),
							 .clk(clk33_i));

	assign event_id_o = event_id_reg;
	assign event_id_ok_o = sum_ok;
	assign event_id_buffer_o = lab_id;
	assign digitize_o = digitize_flag;
	assign cmd_debug_o = cmd_in_sync;
	assign event_id_wr_o = (state == DONE);
	assign sample_o = 1'b0;
	assign debug_o = {data_available,data_out};
endmodule
