// LAB data is read out here now. Scaler data and
// RF power data still come in separately.
module MESSv2( input        clk_i,
	       input 	     cmd_i,
	       input 	     nADS,
	       input 	     WnR,
	       input [7:2]   LA,
	       inout [31:0]  LD,
	       input 	     nCS2,
	       input 	     nCS3,
	       input 	     nRD,
			 input		  nWR,
	       output 	     nREADY,
	       output 	     nBTERM,
			
			 // Header crap.
			 input 		  [5:0] board_id_i,			 

	       output 	     clr_all_o, 

			 output [31:0] short_mask_o,
	       
	       input [31:0]  lab_dat_i,
	       input 	     lab_ready_i,
			 output [3:0] lab_digitize_o,
			 
	       output [12:0] lab_addr_o,
	       input [15:0]  rfp_dat_i,
	       output [4:0]  rfp_addr_o,

			 output 			dac_update_o,
			 input 			dac_busy_i,
			 output 			dac_wr_o,
			 output [4:0]  dac_waddr_o,
			 output [15:0] dac_dat_o,
	       input [15:0]  dac_dat_i,
	       output [4:0]  dac_raddr_o,
			 
	       input [15:0]  scal_dat_i,
	       output [4:0]  scal_addr_o,
			 output 			scal_rd_o,
			 input [15:0]  refpulse_cnt_i,
			 
			 output busy_flag_o,
			 
			 output [34:0] debug_o
	       );

	localparam [31:0] IDENT = "SURF";
	localparam [3:0] VER_MONTH = 11;
	localparam [7:0] VER_DAY = 17;
	localparam [3:0] VER_MAJOR = 4;
	localparam [3:0] VER_MINOR = 0;
	localparam [7:0] VER_REV = 4;
	localparam [3:0] VER_BOARDREV = 0;
   localparam [31:0] VERSION = {VER_BOARDREV,VER_MONTH,VER_DAY,VER_MAJOR,VER_MINOR,VER_REV};

	// IOB-pushed registers.
   (* IOB = "TRUE" *)
   reg [5:0] 		     la_q = {6{1'b0}};
   (* IOB = "TRUE" *)
   reg [31:0] 		     ldi_q = {32{1'b0}};
   wire [31:0] 		     ldo_q;
   wire [31:0] 		     ldoeb_q;
   (* IOB = "TRUE" *)
   reg 			     nads_q = 1;
   (* IOB = "TRUE" *)
   reg 			     wnr_q = 1;   
   (* IOB = "TRUE" *)
   reg 			     ncs2_q = 1;
   (* IOB = "TRUE" *)
   reg 			     ncs3_q = 1;
   (* IOB = "TRUE" *)
   reg 			     nready_q = 1;   
   (* IOB = "TRUE" *)
   reg 			     nrd_q = 1;
	(* IOB = "TRUE" *)
	reg				  nbterm_q = 1;
	(* IOB = "TRUE" *)
	reg				  nwr_q = 1;
	// Set high if bursts are enabled.
	reg			  lab_burst_read = 0;
	// Clears.
   reg 		     clr_all = 0;   
   reg 		     clr_evt = 0;
	reg 			  update_dac = 0;
	reg 			  busy_flag = 0;
	// Mask register.
	reg [31:0]	  short_mask = {32{1'b0}};
	// Header crap.
	reg [3:0]	  event_count = {4{1'b0}};
	reg [5:0]	  board_id = {6{1'b0}};	
	reg [1:0]	  lab_sel = {2{1'b0}};
	wire [15:0] header;
	wire [15:0] scal_header;
	// Debug data output.
	reg [31:0]	ldo_mux_debug = {32{1'b0}};
	
	// Event FIFO inputs, outputs, write flag, empty flag.
   wire 		     event_wr;
   wire [31:0] 		     event_id;
   wire [1:0] 		     event_id_buffer;
	wire event_id_ok;
   wire [34:0] 		     event_fifo_in;
	assign event_fifo_in[34] = event_id_ok;
	assign event_fifo_in[33:32] = event_id_buffer;
	assign event_fifo_in[31:0] = event_id;
	
   wire [34:0] 		     event_fifo_out;
   wire 		     event_fifo_empty;   

   // These generate the address outputs for the lab and HK data.
   reg [6:0] 		     hk_counter = {7{1'b0}};
	// The LAB counter consists of 2 segments - the page register, and the
	// address predictor.
	// The page register gets written progressively during the readout,
	// and sets the 'window' that the true LAB readout space (0x00-0xFF)
	// points to.
	reg [4:0]			  lab_page_register = {5{1'b0}};
	// The LAB address predictor 'predicts' the address that will be presented
	// for each burst.
	reg [5:0]			  lab_address_predictor = {6{1'b0}};
	wire [6:0]			  lab_address_predictor_plus_one = lab_address_predictor + 1;

	// Ready for LABs.
	reg				  ready_lab= 0;
   // Ready for HK/Regs.
	reg 				  ready_regs_or_hk = 0;
	// ready debug
	reg				  ready_debug = 0;
	// bterm debug
	reg				  bterm_debug = 0;
   // Data output mux for regs/hk.
	reg [31:0]		  regs_or_hk = {32{1'b0}};
   // Vector of housekeeping outputs: scalers first, then DAC, then RFP.
   wire [31:0] 		     hk_dat[3:0];
	// Multiplexed housekeeping output.
   wire [31:0] 		     hk_dat_mux;
	// Select bits to mux the data output.
   wire [1:0] 		     ldo_in_sel;   
	// Vector of data outputs.
   wire [31:0] 		     ldo_in[3:0];
	// Multiplexed data output.
   wire [31:0] 		     ldo_in_mux;
	// Vector of register outputs.
   wire [31:0] 		     register_data[15:0];
	// Multiplexed register output.
   wire [31:0] 		     register_data_mux;
	
	// Readout state machine.
   localparam FSM_BITS = 3;   
   localparam [FSM_BITS-1:0] IDLE = 0;
	localparam [FSM_BITS-1:0] WAIT = 7;
   localparam [FSM_BITS-1:0] LAB_WR = 1;
   localparam [FSM_BITS-1:0] LAB_RD = 2;
   localparam [FSM_BITS-1:0] HK_WR = 3;
   localparam [FSM_BITS-1:0] HK_RD = 4;
   localparam [FSM_BITS-1:0] REG_WR = 5;
   localparam [FSM_BITS-1:0] REG_RD = 6;
   reg [FSM_BITS-1:0] 	     state = IDLE;
	
	// The LAB read logic is a little complicated to support
	// proper bursting. If bursting is enabled (lab_burst_read = 1)
	// then the address fed to the LAB RAM is lab_counter + 1
	// when ncs3_q is low. lab_counter increments
	// when ncs3_q is low, and until LAB_RD_DONE.
	//
	// Simplified timing (assume 4-cycle burst):
	// clk ncs3_q lab_addr lab_counter lab_data	ldo_q		state
	// 0   1      0        0				<0>		Z			idle
	// 1   0      1        0				<0>		Z			idle
	// 2   0      2        1				<1>		<0>		lab_rd
	// 3   0      3        2				<2>		<1>		lab_rd
	// 4	 0		  4		  3				<3>		<2>		lab_rd
	// 5   0      4        4            <4>		<3>		lab_rd_done
	// 6   1      4 		  4				<4>		Z			idle
	// So lab_addr = (ncs3_q || (state == LAB_RD_DONE)) ? lab_counter : lab_counter_plus_one
	// Single cycle timing:
	// clk ncs3_q nads_q	  lab_addr lab_counter lab_data  ldo_q	state
	// 0   1      1		  0        0            <0>      Z		idle
	// 1   0      0		  1        0            <0>		Z		idle
	// 2   0      1		  1		  1				<1>		<0>	lab_rd_done
	// 3   0		  0		  2		  1				<1>		Z		idle
	// 4	 0		  1		  2		  2				<2>		<1>	lab_rd_done
	// 5	 0		  0		  3		  2				<2>		Z		idle
	// 6	 0		  1		  3		  3				<3>		<2>	lab_rd_done
	//
	// The single cycle mode is enforced by having nBTERM's (negative-edge) output be
	// !(!ncs3_q && !nads_q), issuing BTERM every time an ADS is seen.
	// This *should* allow bursting to be disabled in any configuration, so long as
	// the BTERM input is enabled.
   always @(posedge clk_i) begin : FSM_LOGIC
      case (state)
			IDLE: if (!nads_q) begin
						if (!ncs3_q) begin
							if (wnr_q) state <= LAB_WR;
							else state <= LAB_RD;
						end else state <= WAIT;
					end
			WAIT:	if (wnr_q) begin
						if (!ncs2_q) state <= HK_WR;
						else state <= REG_WR;
					end else begin
						if (!ncs2_q) state <= HK_RD;
						else state <= REG_RD;
					end
			LAB_WR: state <= IDLE;
			HK_WR: state <= IDLE;
			REG_WR: state <= IDLE;
			LAB_RD: if (ncs3_q || !lab_burst_read) state <= IDLE;
			HK_RD: state <= IDLE;
			REG_RD: state <= IDLE;
			default: state <= IDLE;
      endcase // case (state)
   end // block: FSM_LOGIC

	// HK header generation: 000 (Dat_notHK) (EvtNo) (Lab_Sel) (Board_ID)
	assign header	= {{3'b000},ncs2_q,event_count,lab_sel,board_id};   
	// Scalers use the HK header for half, then the refpulse count.
	assign scal_header = (hk_counter[4]) ? refpulse_cnt_i : header;

	// Assignment of HK data output vector.
	assign hk_dat[0] = {scal_header,scal_dat_i};
   assign hk_dat[1] = {header,dac_dat_i};
   assign hk_dat[2] = {header,rfp_dat_i};
   assign hk_dat[3] = dac_dat_i;   
   assign hk_dat_mux = hk_dat[hk_counter[6:5]];
   
	// Assignment of register output vector.
   assign register_data[0] = IDENT;
   assign register_data[1] = VERSION;
   assign register_data[2] = hk_counter;
   assign register_data[3] = {lab_burst_read,{20{1'b0}},lab_page_register,{6{1'b0}}};
   assign register_data[4] = {header,{11{1'b0}},
					event_fifo_out[34],
			      event_fifo_empty,
			      event_fifo_out[33:32],
			      !event_fifo_empty && lab_ready_i };
   assign register_data[5] = event_fifo_out[31:0];
   assign register_data[6] = {busy_flag_o,{27{1'b0}},dac_busy_i,update_dac,clr_evt,clr_all};   
   assign register_data[7] = short_mask;
   assign register_data_mux = register_data[la_q[3:0]];
   
	// terminate_read is used to determine when OEB can go high.
	// I actually think this might be pointless: OEB can probably be straight
	// copied from WnR. It's held quite a bit before nADS is asserted, and quite
	// a bit after too. 

/*
   wire 		     terminate_read = 
							 (state == LAB_RD_DONE
					       || state == HK_RD 
					       || state == REG_RD);
*/

	// nREADY is asserted 2 clocks after nADS. Goes low when nRD/nWR are both high.
	wire ready = (ready_lab || ready_regs_or_hk) && (!nrd_q || !nwr_q);
   wire 		     nready_in = !ready;
	// Assert BTERM if nADS is low and we're not bursting from CS3 (lab_burst_read is low, or ncs3_q is high).
	wire bterm = ((!nads_q && !ncs3_q && !lab_burst_read) || ready_regs_or_hk);
	wire 			  nbterm_in = !bterm;
   wire 		     ldo_oeb_in = wnr_q; // || terminate_read;

	wire 			  cmd_sample;
	wire			  cmd_debug;
	wire [8:0]	  receiver_debug;
   SURF_command_receiver_v2 u_receiver(.clk33_i(clk_i),
				    .rst_i(clr_all),
				    .cmd_i(cmd_i),
					 .cmd_debug_o(cmd_debug),
					 .sample_o(cmd_sample),
					 .event_id_ok_o(event_id_ok),
				    .event_id_wr_o(event_wr),
				    .event_id_buffer_o(event_id_buffer),
				    .event_id_o(event_id),
				    .digitize_o(lab_digitize_o),
					 .debug_o(receiver_debug));   

	(* BOX_TYPE = "black_box" *)
   event_fifo u_fifo(.din(event_fifo_in),
		     .dout(event_fifo_out),
		     .clk(clk_i),
		     .wr_en(event_wr),
		     .rd_en(clr_evt),
			  .rst(clr_all),
		     .empty(event_fifo_empty));

	dac_address_remap u_remap_1(.logical_addr_i(la_q),.dac_addr_o(dac_waddr_o));
	dac_address_remap u_remap_2(.logical_addr_i(hk_counter[4:0]),.dac_addr_o(dac_raddr_o));

   always @(posedge clk_i) begin : REGISTER_LOGIC
		// Multiplex the data/housekeeping.
		regs_or_hk <= (ncs2_q) ? register_data_mux : hk_dat_mux;
		// nREADY assertion for either register data or housekeeping data.
		ready_regs_or_hk <= (state == WAIT);
		
		// nREADY assertion for LABs.
		if (!nads_q && !ncs3_q) ready_lab <= 1;
		else if (nrd_q && nwr_q) ready_lab <= 0;
				
		// Board ID.
		board_id <= board_id_i;
		// LAB data selection.
		lab_sel <= event_fifo_out[33:32];

		// Dumb event counter.
		if (clr_all) event_count <= {4{1'b0}};
		else if (clr_evt) event_count <= event_count + 1;

		// Local register capture.
      if (state == REG_WR) begin
			 if (la_q[2:0] == 3'd2) hk_counter <= ldi_q;
		end

		if (state == REG_WR && la_q[2:0] == 3'd3) lab_burst_read <= ldi_q[31];

		if ((state == REG_WR) && la_q[2:0] == 3'd6) clr_all <= ldi_q[0];
		else clr_all <= 0;
		
		if ((state == REG_WR) && la_q[2:0] == 3'd6) clr_evt <= ldi_q[1];
		else clr_evt <= 0;

		if ((state == REG_WR) && la_q[2:0] == 3'd6) update_dac <= ldi_q[2];
		else update_dac <= 0;

		if ((state == REG_WR) && la_q[2:0] == 3'd6) busy_flag <= ldi_q[31];

		if ((state == REG_WR) && la_q[2:0] == 3'd7) short_mask <= ldi_q;		

		if ((state == REG_WR) && la_q[2:0] == 3'd3) lab_page_register <= ldi_q[10:6];
		else if (state == LAB_WR) lab_page_register <= ldi_q[10:6];
		
		// Simple HK counter increment. HK doesn't support bursting:
		// I should probably have nBTERM asserted, then, or something.
      if (state == HK_RD) hk_counter <= hk_counter + 1;

		// LAB address predictor. Updated with new address at nads_q,
		// and then increments as long as ncs3_q is low.
		// Data is held off for 2 clocks: nADS goes low, wait (la_q feeds BRAM), wait (BRAM data is on ldo_in_mux), data.
		// BRAM is fed with la_q if nads_q is low, otherwise lab_address_predictor.
		if (clr_evt) lab_address_predictor <= {6{1'b0}};
      else if (!nads_q) lab_address_predictor <= la_q;
		else if (!ncs3_q) lab_address_predictor <= lab_address_predictor_plus_one;
   end
   
   always @(posedge clk_i) begin : IOB_LOGIC_P
      nads_q <= nADS;
      wnr_q <= WnR;
      ncs2_q <= nCS2;
      ncs3_q <= nCS3;
      ldi_q <= LD;
      la_q <= LA[7:2];      
		nrd_q <= nRD;
		nwr_q <= nWR;
		ldo_mux_debug <= ldo_in_mux;
		ready_debug <= nready_in;
		bterm_debug <= nbterm_in;
	end
	
   always @(negedge clk_i) begin : IOB_LOGIC_N
      nready_q <= nready_in;
		nbterm_q <= nbterm_in;
	end      
   
	assign ldo_in_mux = (ncs3_q) ? regs_or_hk : lab_dat_i;
		
   assign scal_addr_o = hk_counter[4:0];
   assign rfp_addr_o = hk_counter[4:0];
//   assign dac_raddr_o = hk_counter[4:0];

	assign lab_addr_o[5:0] = (nads_q) ? lab_address_predictor_plus_one : la_q;
	assign lab_addr_o[10:6] = lab_page_register;
	assign lab_addr_o[12:11] = event_fifo_out[33:32];

   assign clr_all_o = clr_all;
   assign busy_flag_o = busy_flag;
	
   generate
      genvar oe;
      for (oe=0;oe<32;oe=oe+1) begin : LDBUF
			(* IOB = "TRUE" *)
			FD_1 u_ld(.D(ldo_in_mux[oe]),.C(clk_i),.Q(ldo_q[oe]));
			(* IOB = "TRUE" *)
			FD_1 u_ldoe(.D(ldo_oeb_in),.C(clk_i),.Q(ldoeb_q[oe]));
			assign LD[oe] = (ldoeb_q[oe]) ? 1'bZ : ldo_q[oe];
      end
   endgenerate   

	assign nREADY = nready_q;

//	assign dac_waddr_o = la_q;
	assign dac_wr_o = (state == HK_WR);
	assign dac_dat_o = ldi_q;
	assign dac_update_o = update_dac;
	
	assign short_mask_o = short_mask;

	assign scal_rd_o = (state == HK_RD) && (hk_counter[6:5] == 2'b00);
	
//	assign debug_o[0 +: 16] = ldo_mux_debug[15:0];
//	assign debug_o[16 +: 6] = la_q;
//	assign debug_o[22 +: 5] = lab_page_register;
//	assign debug_o[28] = nads_q;
//	assign debug_o[29] = ready_debug;
//	assign debug_o[30] = ncs3_q;
//	assign debug_o[31] = bterm_debug;
//	assign debug_o[32 +: 3] = state;

	assign debug_o[0] = nads_q;
	assign debug_o[1] = ncs2_q;
	assign debug_o[2] = ncs3_q;
	assign debug_o[3] = wnr_q;
	assign debug_o[4 +: 3] = state;
	assign debug_o[7] = event_fifo_empty;
	assign debug_o[8] = event_wr;
	assign debug_o[9] = clr_evt;
	assign debug_o[10 +: 6] = la_q[5:0];
	assign debug_o[16 +: 8] = event_id[7:0];
	assign debug_o[24 +: 8] = receiver_debug[7:0];
	assign debug_o[32] = clr_all;
	assign debug_o[33] = lab_ready_i;
	assign debug_o[34] = receiver_debug[8];

   assign nBTERM = nbterm_q;   

endmodule
