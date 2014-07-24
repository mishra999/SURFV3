`timescale 1ns/1ps
////////////////////////////////////////////////////////////////////////////////
// LAB3 readout module, simplified to just use a counter.
//
// All rights reserved.
//
// Author: Patrick Allison, Ohio State University (allison.122@osu.edu)
// Author:
// Author:
////////////////////////////////////////////////////////////////////////////////
module LAB_CTRL_v2(
		    output 	  SELMAIN,
		    output 	  SELTAIL,
		    output [3:0]  CS,
		    output [7:0]  S,
		    input [11:0]  DAT,
		    input 	  RCO,
		    input 	  HITBUS,
			 
		    input 	  clk_i,
			 input	  rst_i,
		    input 	  readout_i,
			 input	  hold_i,
			 
			 output [11:0] addr_o,
			 output [15:0]  dat_o,
			 output		 hitbus_o,
			 output         rco_o,
			 output 			  wr_o,
			 output 			done_o
		    );

   localparam NUM_CHANNELS = 9;
   localparam NUM_SAMPLES = 256;
   localparam NUM_TAIL_SAMPLES = 4;
   
   (* IOB = "TRUE" *)
   reg [11:0] 			  dat_q = {12{1'b0}};
   (* IOB = "TRUE" *)
   reg [3:0] 			  cs_q = {4{1'b0}};
   (* IOB = "TRUE" *)
   reg [7:0] 			  s_q = {8{1'b0}};   
   (* IOB = "TRUE" *)
   reg 				  hitbus_q = 0;
   (* IOB = "TRUE" *)
   reg 				  selmain_q = 0;
   (* IOB = "TRUE" *)
   reg 				  seltail_q = 0;
   
   wire 			  rco_held;
      
   (* IOB = "TRUE" *)
   LDCPE #(.INIT(1'b0)) 	u_rco_latch(.G(!hold_i),.GE(1'b1),
		     .CLR(1'b0),.PRE(1'b0),.D(RCO),.Q(rco_held));
   // Total data is 2340.
   localparam [11:0] COUNT_MAX = NUM_CHANNELS*(NUM_SAMPLES+NUM_TAIL_SAMPLES);
   
   // S[1:0] are always the counter outputs.
   // S[7:2] are the counter outputs until
   // counter[7:0] == FF and counter[11]. After that they're zero.
   // CS are bits[11:8] until count[7:0] and counter[11].
   // After that they're bits[5:2].

	reg reading = 0;
	reg done = 0;
   reg 				  tail_select = 0;   
   reg [11:0] 			  counter = {12{1'b0}};
	reg [11:0] counter_store_1 = {12{1'b0}};
	reg [11:0] counter_store_2 = {12{1'b0}};
   wire [12:0] 			  counter_plus_one = counter + 1;
	reg [1:0] delay = {2{1'b0}};
	   
	always @(posedge clk_i) begin
      if ((reading) && (counter_plus_one[8] && counter[11])) tail_select <= 1;
      else tail_select <= 0;

		if (rst_i || !reading) counter <= {12{1'b0}};
		else if (reading) counter <= counter_plus_one;
		
		counter_store_1 <= counter;
		counter_store_2 <= counter_store_1;

		if (rst_i) reading <= 0;
		else if (readout_i) reading <= 1;
		else if (counter_plus_one == COUNT_MAX) reading <= 0;

		done <= delay[1] && !delay[0];

		if (rst_i) delay <= {2{1'b0}};
		else delay <= {delay[0],reading};
   end
   always @(posedge clk_i) begin : IOB_LOGIC
      selmain_q <= (reading && !tail_select);
      seltail_q <= (reading && tail_select);

		if (reading) begin
			cs_q <= (tail_select) ? counter[5:2] : counter[11:8];
			s_q[1:0] <= counter[1:0];
			s_q[7:2] <= (tail_select) ? {6{1'b0}} : counter[7:2];
		end      
      
      dat_q <= DAT;
      hitbus_q <= HITBUS;      
	end

   assign CS = cs_q;
   assign S = s_q;
   assign SELMAIN = selmain_q;
   assign SELTAIL = seltail_q;

	assign addr_o = counter_store_2;
	assign dat_o = {2'b00,rco_o,hitbus_o,dat_q};
	assign hitbus_o = hitbus_q;
	assign rco_o = rco_held;
	assign wr_o = delay[1];
	assign done_o = done;
endmodule
   
