`timescale 1ns / 1ps

//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:56:22 07/21/2014 
// Design Name: 
// Module Name:    RF_Pow_Ben 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//    Ben Rotter (BenJRotter@gmail.com) - University of Hawaii at Manoa - July 2014
//////////////////////////////////////////////////////////////////////////////////
module RF_Pow_Ben(
	 input AD_nBusy,      //tells when the ADC (LTC1415) is busy (active low)
    input [11:0] AData, //data from external ADC chip
    input CLK, //33MHz input CPCI clock
	 input [4:0] RAD, //read address
	 input RCLK, //read clock
    input rst_i, //reset from top module, resets everything to zero
	 output [2:0] MUXSel, //8 possible selections, 3 bits (output to chip)
    output [15:0] RFPWR,    //blockram data register selected by RAD and read out by RCLK
	 output AD_nCONVST, //command to convert (active low)
    output AD_nCS,     //chip select, should be always on (active low)
    output AD_nRD,      //command to read (active low)
	 
	 //chipscope debugging outputs
	 output [11:0] AData_debug,
	 output [6:0] signals_debug, //6:4=sample_state, 3:2=write_state, 1=changeSig_flag, 0=changeSigHold_flag
	 output [25:0] adder_debug,
	 output [15:0] sampleCount_debug,
	 output AD_nCS_debug, 
	 output AD_nCONVST_debug,
	 output AD_nRD_debug,
	 output AD_nBusy_debug,
	 output rst_i_debug,
	 output [4:0] convst_timer_debug
    );

	assign AData_debug = AData;

	assign rst_i_debug = rst_i;

	//ADC signals (LTC1415)
	reg AD_nRD_reg = 1;
	reg AD_nCONVST_reg = 1;

	assign AD_nCS = 1'b0; //chip select should always be on
	assign AD_nCONVST = AD_nCONVST_reg;
	assign AD_nRD = AD_nRD_reg;
	
	assign AD_nCS_debug =  AD_nCS;
	assign AD_nCONVST_debug = AD_nCONVST;
	assign AD_nRD_debug = AD_nRD;

	reg AD_nBusy_reg = 1; //to make asynchronous external signal synchronous
	reg AD_nBusy_buf = 1; //I saw the thing get stuck, so lets add a buffer too
	assign AD_nBusy_debug = AD_nBusy_reg;
	
	//MUX signals
	reg [2:0] MUXSel_reg = {3{1'b0}};
	assign MUXSel = MUXSel_reg;

	//internal registers and wires//
	//block ram data storage
	reg [15:0] block_ram [31:0];
	
	//addressing for readout
	reg [4:0] wr_addr_MSB = {5{1'b0}}; //512 is 9 bits
	reg [4:0] wr_addr_LSB = {5{1'b0}};
	reg [4:0] wr_timing_addr_MSB = {5{1'b0}};
	reg [4:0] wr_timing_addr_LSB = {5{1'b0}};
	
	//sampling and data
	reg [15:0] sampleCount = {16{1'b0}}; //count how many samples I am taking
	reg [1:0] sample_timer = 0;     //timer to ensure I don't try to sample faster than the ADC can handle
	reg [25:0] RF_PowAdder = {26{1'b0}}; //for adding up the power read up (top 12 bits are stored, like an average)
	assign adder_debug = RF_PowAdder;
	reg [15:0] RFPWR_reg = {16{1'b0}};   //actual output for when the MESSv2 block reads the data
	assign RFPWR = RFPWR_reg;
	reg phase = 0; 						//lets us get a 6ms timing resolution, the highest bit will be the "RCO phase"
	reg [1:0] wrapCount = {4{1'b0}}; //how many times it has wrapped around (sort of a debug)

	
	//flags for state machines
	reg sample_flag = 0;         //start sampling machine
	reg sampleHold_flag = 0;     //lets everything else know sample state machine is running (7 clocks, ~212ns)
	reg [4:0] convst_timer = 0;  //timer that waits 26 clock cycles (780ns) for the conversion to finish
	assign convst_timer_debug = convst_timer;
	
	reg changeSig_flag = 0;      //change input
	assign signals_debug[1] = changeSig_flag;
	reg changeSigHold_flag = 0;  //the hold after changing input for everything to settle
	assign signals_debug[0] = changeSigHold_flag;
	reg [5:0] changeSigHold_counter = 0;  //stores when switch occurrs so hold flag can be dropped 2uS after (64 clock cycles)
	wire [6:0] changeSigHold_counter_wrap = changeSigHold_counter + 1; //when this goes high, the mux is switched and settled


	reg [2:0] sample_state = 0;  //the sampling state machine
	assign signals_debug[6:4] =  sample_state;
	reg [1:0] write_state = 0;   //the block ram writing state machine
	assign signals_debug[3:2] =  write_state;	

	wire [3:0] channelWrap = MUXSel_reg + 1; //will will be 'b1000 when it is about to wrap

	always @ (posedge CLK) begin	//
		RFPWR_reg <= block_ram[RAD];
	end

	always @ (posedge CLK) begin //syncronous 33MHz clock! (30ns)

		if (rst_i == 1) begin
			sample_timer    <= 0;
			sample_flag     <= 0;
			sample_state    <= 0;
			sampleHold_flag <= 0;
			sampleCount     <= 0;
			write_state     <= 0;
			changeSig_flag        <= 0;
			changeSigHold_flag    <= 0;
			changeSigHold_counter <= 0;
			RF_PowAdder     <= 0;
			MUXSel_reg      <= 0;
			AD_nCONVST_reg  <= 1;
			AD_nRD_reg      <= 1;
			convst_timer    <= 0;
		end
		else begin //do stuff if there isn't a reset
		
		
		//decide to start sampling, unless you have already sampled up to the averaging limit (2**14 in this case)
		if (sample_timer == 2'b10) begin
			sample_flag <= 1;   // (1uS) 1MHz sampling speed flag, starts sampling
		end		
		
		//buffer the busy flag (twice I guess)
		AD_nBusy_buf <= AD_nBusy;
		AD_nBusy_reg <= AD_nBusy_buf;


		//sampling state machine
		 case (sample_state)  
			3'd0: begin //hold state, wait until this counter fills before sampling
				//sampling state starter, the most important state starter and very picky
					//requires: no sampling already, ADC not busy, state change not recent or in queue
				if (sample_flag == 1 && changeSig_flag == 0 && changeSigHold_flag == 0) begin
					sample_state <= 3'd1;
					sampleHold_flag <= 1;
					sampleCount <= sampleCount + 1;
				end
				else begin
					sample_timer <= sample_timer + 1;
					sample_state <= 3'd0;
					end
				end
			3'd1: begin //start conversion by putting convert flag low
				AD_nCONVST_reg <= 1'b0;
				sample_state <= 3'd2;
			end
			3'd2: begin //wait 60ns (2 clock cycles) for conversion to start
				if (convst_timer == 5'd3) begin //it can take up to 60ns for AD_nBusy to drop low, so wait that long
					sample_state <= 3'd3;
					convst_timer <= 0;
				end
			   else begin
					sample_state <= 3'd2;
					convst_timer <= convst_timer + 1;
				end
			end
			3'd3: begin //once conversion starts, wait 700ns at least for conversion to finish
				if (convst_timer == 5'd25) begin //wait 25clock cycles (750ns) for the conversion to finish
					AD_nCONVST_reg <= 1'b1;
					AD_nRD_reg <= 1'b0;
					sample_state <= 3'd4;
					convst_timer <= 0;
				end
				else begin
					sample_state <= 3'd3;
					convst_timer <= convst_timer + 1;
				end
			end
			3'd4: begin //once conversion finishes, read data into adder
				if (convst_timer == 5'd2) begin
					convst_timer <= 0;
					RF_PowAdder <= RF_PowAdder + AData;
					AD_nRD_reg <= 1'b1;
					sample_state <= 3'd0; //done with sampling reset everything
					sampleHold_flag <= 0;
					sample_timer <= 0;
					sample_flag <= 0;
				end
				else begin
					sample_state <= 3'd4;
					convst_timer <= convst_timer + 1;
				end
			end

			default: begin
				sample_state <= 3'd0;
			end

		 endcase //end of sampling state machine case
		
	
		
		//update the register to write the data to, dependant on where the RAD is and what the mux channel is
		// 32 (2**5) blocks to write into, separate into 4 sectors
		if (write_state == 2'd1) begin
			wr_addr_MSB[2:0] <= MUXSel_reg;
			wr_addr_MSB[4:3] <= 2'b01;
			
			wr_addr_LSB[2:0] <= MUXSel_reg;
			wr_addr_LSB[4:3] <= 2'b00;

			write_state <= write_state + 1;
		end
		
		//need to split this into two clock cycles since calculating the address takes one (because of the if statement)
		if (write_state == 2'd2) begin
			MUXSel_reg <= MUXSel_reg + 1;            // actually change the analog signal select now that you saved it in the wr_addr's
			write_state <= write_state + 1;
		end
		
		
		//write out the highest bits of the adder (an average essentially) to the block ram
		if (write_state == 2'd3) begin
			block_ram[wr_addr_MSB] <= {phase,RF_PowAdder[22:8]}; //top bit is "phase", which shows the last position of the write
			block_ram[wr_addr_LSB] <= {RF_PowAdder[8:0],RF_PowAdder[25:23]}; //also store the least significant bits!
			
			block_ram[{2'b10,wr_addr_MSB[2:0]}] <= AData; //since I have a ton of room, just copy the old functionality here to this block
			
			RF_PowAdder <= 0; //null out adder
			sampleCount <= 0; //null out counter
			
			write_state <= 0; //turn off write flag after you've written
		end
		
		

	
		//Switch MUX when you've taken enough samples 
			//(34 clock cycles per sample * 30ns period = 1020ns/samp)
			//(100ms / (1020ns/samp*8chan) = 12255 samples/chan) ~14bits (110^2 = 12100 so lets go with that)
		if (sampleCount == 5625 && changeSigHold_flag == 0) begin
			changeSig_flag <= 1;  //stays high until switch is completed (in case flag raises during sampling)
		end
		
				
	   //change the Analog Signal Select
	   //do it when you've got enough samples to do the average
		//don't change while sampling is happening
		if (changeSig_flag == 1 && sampleHold_flag == 0) begin
			if (MUXSel_reg == 3'b000) begin //after you wrap from ch7->ch0 do some extra stuff
				wrapCount <= wrapCount + 1; //incriment debug wrap if needed (channelWrap[3] is a wire that will be 1 when it is about to wrap)
				phase <= ~phase;            //switch the phase so the data reflects where the "Hit Bus" is located
			end
			changeSig_flag <= 0;                     //lower flag cuz you just changed successfully
			sample_timer <= 0;                       //reset sample timer, otherwise you'll get a delay the size of the counter
			changeSigHold_flag <= 1;                 //raise the hold flag so the mux can settle
			write_state <= write_state + 1;          //start the write state machine
		end
		
		//count up after MUX switch so it can settle
		if (changeSigHold_flag == 1) begin
			changeSigHold_counter <= changeSigHold_counter + 1;
		end
		
		//turn off 'hold' after mux switch settles (~2uS)
		if (changeSigHold_counter_wrap[6] == 1) begin 
			changeSigHold_flag <= 0;
			changeSigHold_counter <= 0;
		end

		
end


	
		end //end of syncronous 33MHz clock
		
	
	

endmodule
