`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////
// This file is a part of the Antarctic Impulsive Transient Antenna (ANITA)
// project, a collaborative scientific effort between multiple institutions. For
// more information, contact Peter Gorham (gorham@phys.hawaii.edu).
//
// All rights reserved.
//
// Author: Eric Oberla, univ of chicago
// Author:
// Author:
////////////////////////////////////////////////////////////////////////////////
///written July 2016
///module to handle singles for ANITA4
module ANITA4_trig_single_pol(TRIG, CLK, CLR, TRIG_SYNC, MASK);
	input TRIG;
	input CLK;
	input CLR;
	input MASK;
	output reg [2:0] TRIG_SYNC;
	
	// reg [2:0] trig_reg = {3{1'b0}};  //note: LSB is meta-stable 
	wire trig_latch;

	//latch on falling-edge of TRIG 
	(* IOB = "FORCE" *)
	FDCE_1 #(
      .INIT(1'b0) // Initial value of register (1'b0 or 1'b1)
   ) FDCE_latch (
      .Q(trig_latch),  // Data output
      .C(TRIG),        // Clock input
      .CE(1'b1),       // Clock enable input
      .CLR(CLR),       // Asynchronous clear input
      .D(1'b1)         // Data input
   );	
	
	//if CLR=1, set all to 0
	always @(posedge CLK) begin
		if (CLR)
			TRIG_SYNC <= {3{1'b0}};
		else
			TRIG_SYNC <= {TRIG_SYNC[1:0], trig_latch};
			//trig_reg <= {trig_reg[1:0], trig_latch};
		
		//TRIG_SYNC[1:0] = trig_reg[2:1];//_SYNC[0] used for l+r coinc.
                                     //_SYNC[1] (or SYNC delayed) used to clear
	end	
	
endmodule 