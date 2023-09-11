
`timescale 1ns / 1ps
  
           

module ANITA_TOP9_TB#(
	parameter NUM_TRIG = 4,
	parameter NUM_HOLD   = 4
  )		;


		reg nRD;
		reg nWR;
	reg nADS;
	reg WnR;
	reg [7:2] LA;
	reg nCS2;
	reg nCS3;
	reg BCLKO;
    reg [5:0] BAD;

	// reg CLK125_P;
	// wire CLK125_N = ~CLK125_P;

	// wire CMD_P;
	// wire CMD_N = ~CMD_P;
	reg [3:0] HOLD_P;
	wire [3:0] HOLD_N = ~HOLD_P;

	reg A_HITBUS;
	reg A_RCO;
	reg [11:0] A_DAT;
	reg B_HITBUS;
	reg B_RCO;
	reg [11:0] B_DAT;
	reg C_HITBUS;
	reg C_RCO;
	reg [11:0] C_DAT;
	reg D_HITBUS;
	reg D_RCO;
	reg [11:0] D_DAT;

	// Outputs
	wire nREADY;
	wire nBTERM;
	wire LCLK;
	wire A_GCK;
	wire A_GCCLR;
	wire A_RAMP;
	wire [3:0] A_CS;
	wire [7:0] A_S;
	wire A_SELMAIN;
	wire A_SELTAIL;
	wire A_NRUN;
	wire A_TREF_P;
	wire A_TREF_N;
	wire B_GCK;
	wire B_GCCLR;
	wire B_RAMP;
	wire [3:0] B_CS;
	wire [7:0] B_S;
	wire B_SELMAIN;
	wire B_SELTAIL;
	wire B_NRUN;
	wire B_TREF_P;
	wire B_TREF_N;
	wire C_GCK;
	wire C_GCCLR;
	wire C_RAMP;
	wire [3:0] C_CS;
	wire [7:0] C_S;
	wire C_SELMAIN;
	wire C_SELTAIL;
	wire C_NRUN;
	wire C_TREF_P;
	wire C_TREF_N;
	wire D_GCK;
	wire D_GCCLR;
	wire D_RAMP;
	wire [3:0] D_CS;
	wire [7:0] D_S;
	wire D_SELMAIN;
	wire D_SELTAIL;
	wire D_NRUN;
	// wire D_TREF_P;
	// wire D_TREF_N;
	// wire [3:0] CALSNH;
	// wire [3:0] TCS;
	// wire [3:0] RSS;

	// Bidirs
	wire [31:0] LD;
	//
	wire rf_trigger;
	reg rf_trigger_reg; //for sim only
	wire [7:0] rf_count;
	wire clear_to_buffer_handler;
	wire [1:0] clear_buffer_to_buffer_handler;
	wire digitize_hold_o;
	wire [3:0] buffer_status_o;
	wire dead_lab;
	wire [34:0] debug_buff;
	// assign debug_buff = {35{1'b0}};

	wire [3:0] lab_done;
	wire [31:0] event_mess;
	wire event_done_mess;
	wire [1:0] lab_sel;

	reg clk250;
	reg clk33;
	reg clk100;

	always #15 BCLKO = ~BCLKO;
	// always #4 CLK125_P = ~CLK125_P;
    always #2 clk250 = ~clk250;
	always #16.6665 clk33 = ~clk33;
	always #5 clk100 = ~clk100;
	
	// Instantiate the Unit Under Test (UUT)
	reg REF = 1'b0;
	wire [3:0] L1;
	wire gated_forced_trig;

	Simpler_Trigger # (
		.NUM_TRIG(NUM_TRIG),
		.NUM_HOLD(NUM_HOLD)
	  )
	  Simpler_Trigger_inst (
		.clk250_i(clk250),
		.clk33_i(clk33_i),
		.L2_i(L1),
		.refpulse_i(REF),
		.trig_o(rf_trigger),
		.count_o(rf_count),
		.gated_forced_o(gated_forced_trig)
	  );

	  reg ext_trig; //vio input 
	  wire ext_trg_out;
  
	//   ref_trigger  ref_trigger_inst (
	// 	.clk250_i(clk250),
	// 	.ext_trig_i(ext_trig),
	// 	.ext_trg_o(ext_trg_out)
	//   );


	wire [3:0] digitize_lab;
	wire [3:0]  HOLD;
    new_buffer_handler_simpleFSM3  buff_handler(
					.clk250_i(clk250),
					.clk33_i(clk33),
					.rst_i(clr_all_reg),
					.trig_i(ext_trig), // was DO_HOLD, forced and rf_triggerer
					.clear_i(clear_to_buffer_handler), // used to generate RELEASE
					.clear_buffer_i(clear_buffer_to_buffer_handler), // used to generate RELEASE
					.digitize_hold_o(digitize_hold_o), //new: not connected  
					.digitize_lab_33o(digitize_lab),  // needs to be kept 100 ns. -- it should always be kept for at least 88 ns is that enough?
					.HOLD_o(HOLD), //done
					.buffer_status_o(buffer_status_o), //-- done
					.dead_o(dead_lab), //--done
					//debug_state : out std_logic_vector(1 downto 0)
					.debug_o(debug_buff )
					
					);



	decode_digitize decode_labpair(
		.clk33_i(clk33),
		.rst_i(clr_all_reg),
		.digitize_lab_in(digitize_lab),
		.lab_done_in(lab_done),
		.clear_o (clear_to_buffer_handler),
		.clear_buffer_o (clear_buffer_to_buffer_handler)
		// event_o => event_mess,
		// event_done_o => event_done_mess
	
	);

	event_data event_gen(
			.clk33_i(clk33),
			.rst_i(clr_all_reg),
			.event_gen_flag_i(clear_to_buffer_handler),
			.event_buffer_i(clear_buffer_to_buffer_handler),

			.event_o(event_mess),
			.event_done_o(event_done_mess),
			.lab_num_o(lab_sel)
	
	);

	wire [34:0] lab_debug;
	wire [1:0] lab_debug_sel= 2'b0;
	wire lab_testpattern_sel;
	wire lab_ready;
	wire [31:0] lab_dat;
	assign lab_testpattern_sel = 1'b0;
	// LAB readout and memory.
	LAB_TOPv2 u_labtop( .clk_i(clk33),
							  .clk100_i(clk100),
							  .rst_i(clr_all_reg),
							  .hold_i(HOLD),
							  .digitize_i(digitize_lab),
							  .addr_i(lab_addr),
							  .dat_o(lab_dat),
							  .done_o(lab_ready),
							  .lab_done_mask_o(lab_done),
							  .A_SELTAIL(A_SELTAIL),
							  .A_SELMAIN(A_SELMAIN),
							  .A_GCK(A_GCK),
							  .A_RAMP(A_RAMP),
							  .A_GCCLR(A_GCCLR),
							  .A_NRUN(A_NRUN),
							  .A_CS(A_CS),
							  .A_S(A_S),
							  .A_HITBUS(A_HITBUS),
							  .A_RCO(A_RCO),
							  .A_DAT(A_DAT),
							  
							  .B_SELTAIL(B_SELTAIL),
							  .B_SELMAIN(B_SELMAIN),
							  .B_GCK(B_GCK),
							  .B_RAMP(B_RAMP),
							  .B_GCCLR(B_GCCLR),
							  .B_NRUN(B_NRUN),
							  .B_CS(B_CS),
							  .B_S(B_S),
							  .B_HITBUS(B_HITBUS),
							  .B_RCO(B_RCO),
							  .B_DAT(B_DAT),

							  .C_SELTAIL(C_SELTAIL),
							  .C_SELMAIN(C_SELMAIN),
							  .C_GCK(C_GCK),
							  .C_RAMP(C_RAMP),
							  .C_GCCLR(C_GCCLR),
							  .C_NRUN(C_NRUN),
							  .C_CS(C_CS),
							  .C_S(C_S),
							  .C_HITBUS(C_HITBUS),
							  .C_RCO(C_RCO),
							  .C_DAT(C_DAT),

							  .D_SELTAIL(D_SELTAIL),
							  .D_SELMAIN(D_SELMAIN),
							  .D_GCK(D_GCK),
							  .D_RAMP(D_RAMP),
							  .D_GCCLR(D_GCCLR),
							  .D_NRUN(D_NRUN),
							  .D_CS(D_CS),
							  .D_S(D_S),
							  .D_HITBUS(D_HITBUS),
							  .D_RCO(D_RCO),
							  .D_DAT(D_DAT),
							  .debug_tp_i(lab_testpattern_sel),
							  .debug_sel_i(lab_debug_sel),
							  .debug_o(lab_debug)
		);


	wire dac_wr;
	wire dac_busy;
	wire dac_update;
	wire [4:0] dac_waddr;
	wire [4:0] dac_raddr;
	wire [15:0] dac_dat_in;
	wire [15:0] dac_dat_out;


	// wire [34:0] td_debug;
	
	// assign td_debug[16:0] = CR[16:0];
	// assign td_debug[34:17] = {18{1'b0}};
	wire SCLK;
	wire NSYNC;
	wire [7:0] DIN;

	DAC_CTRL_v3 u_dacs( 	.clk_i(clk33),
								.dac_we_i(dac_wr),
								.busy_o(dac_busy),
								.dac_waddr_i(dac_waddr),
								.dac_dat_i(dac_dat_in),
								.dac_raddr_i(dac_raddr),
								.dac_dat_o(dac_dat_out),
								.update_i(dac_update),
								.SCLK(SCLK),
								.NSYNC(NSYNC),
								.DIN(DIN));


	wire [4:0] 	scal_addr;
	wire 			scal_rd;
	reg [15:0] scal_dat_out;
	reg [15:0] refpulse_cnt;

    wire [31:0] short_mask;
    wire clr_all;
	reg clr_all_reg;
	wire [12:0] lab_addr;
	// assign lab_addr = {13{1'b0}};
	reg [12:0] lab_addr_reg = {13{1'b0}};
	reg command;

	 
	// MESS debugging.
	wire [34:0] debug;
	wire busy_flag;
	// PLX/register interface
	MESSv29 u_mess(		  .clk_i(clk33),
							//.clk250_i(clk250),
							  .cmd_i(command),
							  .lab_dat_i(lab_dat),
							  .lab_ready_i(lab_ready),
							  .lab_addr_o(lab_addr),
							  .event_done_in(event_done_mess), // by me
                               .event_id_i(event_mess), // by me
							   .lab_sel_i(lab_sel),
							//   .lab_digitize_o(lab_digitize), //by me
//							  .rfp_dat_i(rfp_addr),
							  .rfp_dat_i(), //RFPWR
							  .rfp_addr_o(), // rfp_addr
							  .clr_all_o(clr_all),

							  .dac_waddr_o(dac_waddr),
							  .dac_raddr_o(dac_raddr),
							  .dac_wr_o(dac_wr),
							  .dac_update_o(dac_update),
							  .dac_busy_i(dac_busy),
							  .dac_dat_i(dac_dat_out),
							  .dac_dat_o(dac_dat_in),
	
							  .scal_addr_o(scal_addr),
							  .scal_rd_o(scal_rd),
							  .scal_dat_i(scal_dat_out),
							  .refpulse_cnt_i(refpulse_cnt),
	
							  .short_mask_o(short_mask),
							  .board_id_i(BAD),
							  .busy_flag_o(busy_flag),
							  
							  .nADS(nADS),
							  .WnR(WnR),
							  .LA(LA),
							  .LD(LD),
							  .nCS2(nCS2),
							  .nCS3(nCS3),
							  .nRD(nRD),
							  .nWR(nWR),
							  .nREADY(nREADY),
							  .nBTERM(nBTERM),
							  .debug_o(debug)
	);


	initial begin
		// Initialize Inputs
		nADS = 1;
		WnR = 1;
		LA = 0;
		nRD=1;
		nWR=1;
		nCS2 = 1;
		nCS3 = 1;
		BCLKO = 0;
		//CLK125_P = 0;
		HOLD_P = 0;

		A_HITBUS = 0;
		A_RCO = 0;
		A_DAT = 12'd54;
		B_HITBUS = 0;
		B_RCO = 0;
		B_DAT = 0;
		C_HITBUS = 0;
		C_RCO = 0;
		C_DAT = 0;
		D_HITBUS = 0;
		D_RCO = 0;
		D_DAT = 0;
		clk250=0;
		clk33=0;
		clk100=0;
		clr_all_reg = 0;
		ext_trig=0;


		// Wait 100 ns for global reset to finish
		#100;
       
		// Add stimulus here
		@(posedge clk33);
		clr_all_reg = 1;
		@(posedge clk33);
		clr_all_reg = 0;
		// Wait 10 ns for ext trig to finish
		#100;
		@(posedge clk250);
		ext_trig=1;
		#100;
		@(posedge clk250);
		ext_trig=0;

		// do two invalid triggers, no thing should happen
		@(posedge clk250);
		ext_trig=1;
		#100;
		@(posedge clk250);
		ext_trig=0;

		#100;
		@(posedge clk250);
		ext_trig=1;
		#10;
		@(posedge clk250);
		ext_trig=0;

		// do another valid trigger after digitization
		@(posedge event_done_mess);
		#10;
		ext_trig=1;
		#10;
		ext_trig=0;
		// always @(posedge clk250);

		// @(posedge BCLKO);
		// my_event_id = 32'h12345678;
		// my_buffer = 2'b00;
		// start_command = 1;
		// @(posedge BCLKO);
		// start_command = 0;
		
		// // Add stimulus here
		// while (counter < 32) begin
		// 	@(posedge clk_i);
		// 	dac_dat_i = counter;
		// 	dac_we_i = 1;
		// 	dac_waddr_i = counter;
		// 	counter = counter + 1;
		// end

	end



endmodule