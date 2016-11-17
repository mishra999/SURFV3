`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////
// This file is a part of the Antarctic Impulsive Transient Antenna (ANITA)
// project, a collaborative scientific effort between multiple institutions. For
// more information, contact Peter Gorham (gorham@phys.hawaii.edu).
//
// All rights reserved.
//
// Author: Eric Oberla, univ of chicago
// Author: Patrick Allison (allison.122@osu.edu), Ohio State
// Author:
////////////////////////////////////////////////////////////////////////////////
///written July 2016
///module to handle singles for ANITA4
module ANITA4_trig_single_pol_fast_retrig(TRIG, CLK, CLR, TRIG_SYNC, MASK, FORCE);
	parameter ONESHOT=1;
	input TRIG;
	input CLK;
	input CLR;
	input MASK;
	input FORCE;
	output [ONESHOT:0] TRIG_SYNC;
	wire trig_latch;
	

	// Bring the latch into our clock domain.
	wire trig_sync_meta;
	// Reset pipeline.
	reg [ONESHOT-1:0] trig_reset = {ONESHOT{1'b0}};
	// Oneshot.
	reg trig_oneshot = 0;
	// Pipeline for the oneshot.
	reg [ONESHOT-1:0] trig_pipeline = {ONESHOT{1'b0}};
	
	//latch on falling-edge of TRIG 
	(* IOB = "TRUE" *)
	FDCE_1 #(
      .INIT(1'b0) // Initial value of register (1'b0 or 1'b1)
   ) FDCE_latch (
      .Q(trig_latch),  // Data output
      .C(TRIG),        // Clock input
      .CE(1'b1),       // Clock enable input
      .CLR(trig_reset[ONESHOT-1]),       // Asynchronous clear input
      .D(~MASK)         // Data input
   );	
	FDCE #(.INIT(1'b0)) FDCE_reg(.Q(trig_sync_meta),.C(CLK),.CE(1'b1),.CLR(trig_reset[ONESHOT-1]),.D(trig_latch));
	
	integer i,j;
	always @(posedge CLK) begin
		trig_reset[0] <= trig_sync_meta;
		for (j=1;j<ONESHOT;j=j+1) trig_reset[j] <= trig_reset[j-1];
		
		if (trig_pipeline[ONESHOT-1]) begin
			trig_oneshot <= 0;
			trig_pipeline[ONESHOT-1:0] <= {ONESHOT{1'b0}};
		end else begin
			if (trig_reset[0]) trig_oneshot <= 1;
			trig_pipeline[0] <= trig_oneshot;
			for (i=1;i<ONESHOT;i=i+1) begin
				trig_pipeline[i] <= trig_pipeline[i-1];
			end
		end
	end
	assign TRIG_SYNC={trig_pipeline,trig_oneshot};
endmodule 