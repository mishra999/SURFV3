module SURF_debug_multiplexer( input [34:0] in0,
										 input [34:0] in1,
										 input [34:0] in2,
										 input [34:0] in3,
										 input clk_i,
										 input [1:0] sel_i,
										 output [34:0] out);
	reg [34:0] mux_reg = {35{1'b0}};
	always @(posedge clk_i) begin
		case (sel_i)
			2'b00: mux_reg <= in0;
			2'b01: mux_reg <= in1;
			2'b10: mux_reg <= in2;
			2'b11: mux_reg <= in3;
		endcase
	end

	assign out = mux_reg;
										 
endmodule										 