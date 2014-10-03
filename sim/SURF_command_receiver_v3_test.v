`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:28:15 10/03/2014
// Design Name:   SURF_command_receiver_v3
// Module Name:   C:/cygwin/home/barawn/repositories/github/firmware-surf/sim/SURF_command_receiver_v3_test.v
// Project Name:  SURFv38
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: SURF_command_receiver_v3
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module SURF_command_receiver_v3_test;

	// Inputs
	reg clk33_i;
	reg rst_i;
	wire cmd_i;

	// Outputs
	wire cmd_debug_o;
	wire sample_o;
	wire event_id_ok_o;
	wire [1:0] event_id_buffer_o;
	wire event_id_wr_o;
	wire [31:0] event_id_o;
	wire [3:0] digitize_o;

	reg [31:0] event_id_i = {32{1'b0}};
	reg [1:0] buffer_i = {2{1'b0}};
	reg start_i = 0;
	wire busy;
	wire done;
	wire [11:0] CMD;
	wire cmd_tx_debug;
	SURF_command_interface_v3 u_interface(.clk_i(clk33_i),.event_id_i(event_id_i),
													  .buffer_i(buffer_i),
													  .start_i(start_i),
													  .busy_o(busy),
													  .done_o(done),
													  .CMD_o(CMD),
													  .CMD_debug_o(cmd_tx_debug));
	assign cmd_i = CMD[0];
	// Instantiate the Unit Under Test (UUT)
	SURF_command_receiver_v3 uut (
		.clk33_i(clk33_i), 
		.rst_i(rst_i), 
		.cmd_i(cmd_i), 
		.cmd_debug_o(cmd_debug_o), 
		.sample_o(sample_o), 
		.event_id_ok_o(event_id_ok_o), 
		.event_id_buffer_o(event_id_buffer_o), 
		.event_id_wr_o(event_id_wr_o), 
		.event_id_o(event_id_o), 
		.digitize_o(digitize_o)
	);

	always #15 clk33_i <= ~clk33_i;

	initial begin
		// Initialize Inputs
		clk33_i = 0;
		rst_i = 0;

		// Wait 100 ns for global reset to finish
		#10000;
        
		// Add stimulus here
		@(posedge clk33_i);
		event_id_i <= 32'h12345678;
		buffer_i <= 2'b00;
		start_i <= 1;
		@(posedge clk33_i);
		start_i <= 0;
	end
      
endmodule

