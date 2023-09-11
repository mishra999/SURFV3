--------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
--                
-- Create Date:   13:11:02 07/20/2016
-- Design Name:   
-- Module Name:   C:/Users/EDG/Desktop/firmware-surf/sim/ANITA4_dual_trigger_tb.vhd
-- Project Name:  SURFv38
-- Target Device:  
-- Tool versions:  
-- Description:   
--  
-- VHDL Test Bench Created by ISE for module: ANITA4_dual_L1_trigger
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use std.textio.all;
use ieee.std_logic_textio.all;
--use ieee.numeric_std.all;
     
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
       
ENTITY ANITA4_dual_trigger_L3_tb IS
    generic (
        NUM_PHI : integer := 16 ;
		NUM_TRIG : integer := 4
    );
END ANITA4_dual_trigger_L3_tb;
 
ARCHITECTURE behavior OF ANITA4_dual_trigger_L3_tb IS 
   
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ANITA4_dual_L1_trigger
    PORT(
         TOP_LCP : IN  std_logic_vector(1 downto 0);
         TOP_RCP : IN  std_logic_vector(1 downto 0);
         MID_LCP : IN  std_logic_vector(1 downto 0);
         MID_RCP : IN  std_logic_vector(1 downto 0);
         BOT_LCP : IN  std_logic_vector(1 downto 0);
         BOT_RCP : IN  std_logic_vector(1 downto 0);
         mask_i : IN  std_logic_vector(11 downto 0);
			force_i : IN  std_logic_vector(11 downto 0);
         L1_scaler_o : OUT  std_logic_vector(5 downto 0);
         L2_scaler_o : OUT  std_logic_vector(1 downto 0);
         clk_i : IN  std_logic;
         mclk_i : IN  std_logic;
         trig_o : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal TOP_LCP : std_logic_vector(1 downto 0) := (others => '0');
   signal TOP_RCP : std_logic_vector(1 downto 0) := (others => '0');
   signal MID_LCP : std_logic_vector(1 downto 0) := (others => '0');
   signal MID_RCP : std_logic_vector(1 downto 0) := (others => '0');
   signal BOT_LCP : std_logic_vector(1 downto 0) := (others => '0');
   signal BOT_RCP : std_logic_vector(1 downto 0) := (others => '0');
   signal mask_i : std_logic_vector(11 downto 0) := (others => '0');
	signal force_i : std_logic_vector(11 downto 0) := (others => '0');
   signal clk_i : std_logic := '0';
   signal mclk_i : std_logic := '0';
   signal clk250b_i : std_logic := '0';

 	--Outputs
   signal L1_scaler_o : std_logic_vector(5 downto 0);
   signal L2_scaler_o : std_logic_vector(1 downto 0);
   signal trig_o_uut : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant clk_i_period : time := 4 ns;
	constant mclk_i_period : time := 33.333 ns;
	constant clk100_i_period : time := 10 ns;

    -- COMPONENT ANITA4_simple_trigger
    -- PORT(
    --      clk250_i : IN  std_logic;
	-- 	 clk250b_i : IN  std_logic;
    --      clk33_i : IN  std_logic;
	-- 	ant_mask_i : IN std_logic_vector(2*NUM_PHI-1 downto 0);
	-- 	phi_mask_i : IN  std_logic_vector(2*NUM_PHI-1 downto 0);
	-- 	disable_i : IN std_logic;
	-- 	rf_scal_o: OUT std_logic;
	-- 	gated_rf_scal_o : OUT std_logic;
	-- 	scal_o :  OUT std_logic_vector(2*NUM_PHI-1 downto 0);
	-- 	scal_L2_o :  OUT std_logic_vector(2*NUM_PHI-1 downto 0);
	-- 	refpulse_i : IN std_logic;
	-- 	mon_scal_o :  OUT  std_logic_vector(2*NUM_PHI-1 downto 0);
	-- 	L2_i :  IN std_logic_vector(NUM_TRIG-1 downto 0);
	-- 	L2B_i :  IN std_logic_vector(NUM_TRIG-1 downto 0);
	-- 	trig_o : OUT std_logic;
	-- 	phi_o : OUT std_logic_vector(2*NUM_PHI-1 downto 0);
	-- 	count_o : OUT std_logic_vector(7 downto 0)
    --     );
    -- END COMPONENT;

    COMPONENT Simpler_Trigger
    PORT(
         clk250_i : IN  std_logic;
         clk33_i : IN  std_logic;
		refpulse_i : IN std_logic;
		L2_i :  IN std_logic_vector(NUM_TRIG-1 downto 0);
		trig_o : OUT std_logic;
		count_o : OUT std_logic_vector(7 downto 0)
        );
    END COMPONENT;


	COMPONENT LAB_TOPv2
	PORT(
		clk_i : IN  std_logic;
		clk100_i : IN  std_logic;
		rst_i	: IN  std_logic;
		hold_i : in std_logic_vector(3 downto 0);
		digitize_i : in std_logic_vector(3 downto 0);
			 
	    A_SELTAIL	: OUT  std_logic;
	    A_SELMAIN	: OUT  std_logic;
		A_GCK	: OUT  std_logic;
		A_RAMP	: OUT  std_logic;
		A_GCCLR	: OUT  std_logic;
		A_NRUN	: OUT  std_logic;
	    A_CS : out std_logic_vector(3 downto 0);
	    A_S : out std_logic_vector(7 downto 0);
	    A_HITBUS : IN  std_logic;
	    A_RCO : IN  std_logic;
	    A_DAT : IN  std_logic_vector(11 downto 0);

		B_GCK	: OUT  std_logic;
		B_RAMP	: OUT  std_logic;
		B_GCCLR	: OUT  std_logic;
		B_NRUN	: OUT  std_logic;
	        B_SELTAIL	: OUT  std_logic;
	       B_SELMAIN	: OUT  std_logic;
	    B_CS : out std_logic_vector(3 downto 0);
	    B_S : out std_logic_vector(7 downto 0);
	    B_HITBUS : IN  std_logic;
	    B_RCO : IN  std_logic;
	    B_DAT : IN  std_logic_vector(11 downto 0);

		C_GCK	: OUT  std_logic;
		C_RAMP	: OUT  std_logic;
		C_GCCLR	: OUT  std_logic;			 
		C_NRUN	: OUT  std_logic;
	       C_SELTAIL	: OUT  std_logic;
	       C_SELMAIN	: OUT  std_logic;
	    C_CS : out std_logic_vector(3 downto 0);
	    C_S : out std_logic_vector(7 downto 0);
	       C_RCO: IN  std_logic;
	       C_HITBUS: IN  std_logic;
	       C_DAT : in std_logic_vector(11 downto 0);

			D_GCK	: OUT  std_logic;
			D_RAMP	: OUT  std_logic;
			D_GCCLR	: OUT  std_logic;			 
			D_NRUN	: OUT  std_logic;
	        	    D_SELTAIL	: OUT  std_logic;
	        	    D_SELMAIN	: OUT  std_logic;
	        D_CS : out std_logic_vector(3 downto 0);
	        D_S : out std_logic_vector(7 downto 0);
	       D_RCO: IN  std_logic;
	       D_HITBUS: IN  std_logic;
	       D_DAT : in std_logic_vector(11 downto 0);
			-- [12:11] select which LAB is being read out.
			 addr_i : in std_logic_vector(12 downto 0);
			 dat_o : out std_logic_vector(31 downto 0);
			 lab_done_o : out std_logic_vector(3 downto 0);
			 done_o	: OUT  std_logic;
			 debug_tp_i : IN  std_logic;
			 debug_sel_i : in std_logic_vector(1 downto 0);
			 debug_o : out std_logic_vector(34 downto 0)
    );
	END COMPONENT;
	
	--ANITA4_simple_trigger signals
	-- signal ant_mask_i :  std_logic_vector(2*NUM_PHI-1 downto 0) := (others => '0');
	-- signal phi_mask_i :  std_logic_vector(2*NUM_PHI-1 downto 0) := (others => '0');
	-- signal disable_i : std_logic := '0';
    -- signal rf_trigger_scaler : std_logic := '0';
    -- signal gated_rf_scaler : std_logic := '0';
	-- signal phi_scaler :  std_logic_vector(2*NUM_PHI-1 downto 0) := (others => '0');
	-- signal L2_scaler :  std_logic_vector(2*NUM_PHI-1 downto 0) := (others => '0');
	signal refpulse_i : std_logic := '0';
	-- signal phi_mon_scaler : std_logic_vector(2*NUM_PHI-1 downto 0) := (others => '0');
	signal L2_i : std_logic_vector(NUM_TRIG-1 downto 0)  := (others => '0');
    -- signal L2B_i : std_logic_vector(NUM_TRIG-1 downto 0) := (others => '0');
	signal rf_trigger : std_logic := '0';
	-- signal phi_pattern : std_logic_vector(2*NUM_PHI-1 downto 0) := (others => '0');
	signal rf_count: std_logic_vector(7 downto 0) := (others => '0');

	--BUFFER HANDLER for hold
	signal rst_i : std_logic := '0';
	-- signal trig_i : std_logic_vector(1 downto 0); -- was DO_HOLD, forced and rf_triggerer
	signal trig_buffer_o : std_logic_vector(1 downto 0) := (others => '0'); -- unconnected on top - leave for consistency 
	signal clear_i : std_logic := '0'; -- used to generate RELEASE
	signal clear_buffer_i :  std_logic_vector(1 downto 0) := (others => '0'); -- used to generate RELEASE
	signal digitize_hold_o : std_logic := '0';-- new: a 100 ns pulse from the time either of the pairs go into second hold - should work as there is a holdoff. 
	signal digitize_buffer_o : std_logic_vector(1 downto 0) := (others => '0'); -- 2 bits for legacy - needs only one to indicate which
																			-- of the pairs is being digitized - NEW signal
	signal digitize_source_o : std_logic :='0';  -- needs to be kept 100 ns. -- it should always be kept for at least 88 ns is that enough?
	signal HOLD_o : std_logic_vector(3 downto 0) := (others => '0'); --done
	signal buffer_status_o : std_logic_vector(3 downto 0) := (others => '0'); -- done
	signal dead_o : std_logic := '0'; --done
	--debug_state : out std_logic_vector(1 downto 0)
	signal debug_o : std_logic_vector(5 downto 0) := (others => '0');


	-- signals from LAB_TOPV2
	signal clk100_i	: std_logic :='0';	 
	signal A_SELTAIL : std_logic :='0';
	signal A_SELMAIN : std_logic :='0';
	signal A_GCK : std_logic :='0';
	signal A_RAMP : std_logic :='0';
	signal A_GCCLR : std_logic :='0';
	signal A_NRUN : std_logic :='0';
	signal A_CS : std_logic_vector(3 downto 0) := (others => '0');
	signal A_S : std_logic_vector(7 downto 0) := (others => '0');
	signal A_HITBUS : std_logic :='0';
	signal A_RCO : std_logic :='0';
	signal A_DAT : std_logic_vector(11 downto 0) := (others => '0');

	signal B_GCK : std_logic :='0';
	signal B_RAMP : std_logic :='0';
	signal B_GCCLR : std_logic :='0';
	signal B_NRUN : std_logic :='0';
	signal B_SELTAIL : std_logic :='0';
	signal B_SELMAIN : std_logic :='0';
	signal B_CS : std_logic_vector(3 downto 0) := (others => '0');
	signal B_S : std_logic_vector(7 downto 0) := (others => '0');
	signal B_HITBUS : std_logic :='0';
	signal B_RCO : std_logic :='0';
	signal B_DAT : std_logic_vector(11 downto 0) := (others => '0');

	signal C_GCK : std_logic :='0';
	signal C_RAMP : std_logic :='0';
	signal C_GCCLR : std_logic :='0';			 
	signal C_NRUN : std_logic :='0';
	signal C_SELTAIL : std_logic :='0';
	signal C_SELMAIN : std_logic :='0';
	signal C_CS : std_logic_vector(3 downto 0) := (others => '0');
	signal C_S : std_logic_vector(7 downto 0) := (others => '0');
	signal C_RCO : std_logic :='0';
	signal C_HITBUS : std_logic :='0';
	signal C_DAT : std_logic_vector(11 downto 0) := (others => '0');

	signal D_GCK : std_logic :='0';
	signal D_RAMP : std_logic :='0';
	signal D_GCCLR : std_logic :='0';			 
	signal D_NRUN : std_logic :='0';
	signal D_SELTAIL : std_logic :='0';
	signal D_SELMAIN : std_logic :='0';
	signal D_CS : std_logic_vector(3 downto 0) := (others => '0');
	signal D_S : std_logic_vector(7 downto 0) := (others => '0');
	signal D_RCO : std_logic :='0';
	signal D_HITBUS : std_logic :='0'; 
	signal D_DAT : std_logic_vector(11 downto 0) := (others => '0');
			-- [12:11] select which LAB is being read out.
	signal addr_i : std_logic_vector(12 downto 0) := (others => '0');

	signal dat_o : std_logic_vector(31 downto 0) := (others => '0');
	signal done_o : std_logic :='0';
	signal lab_done_o : std_logic_vector(3 downto 0) := (others => '0');
	signal debug_tp_i : std_logic :='0';
	signal debug_sel_i : std_logic_vector(1 downto 0) := (others => '0');
	signal debug_o1 : std_logic_vector(34 downto 0) := (others => '0');
	signal digitize_lab_o : std_logic_vector(3 downto 0) := (others => '0');

	-- decode digitize
	signal clear_to_buffer_handler : std_logic :='0';
	signal clear_buffer_to_buffer_handler : std_logic_vector(1 downto 0) := (others => '0');
	signal event_mess : std_logic_vector(11 downto 0) := (others => '0');
	signal event_done_mess : std_logic :='0';

BEGIN
	-- addr_i <= digitize_buffer_o & addr_i(10 downto 0);
	-- Instantiate the Unit Under Test (UUT)
   uut: ANITA4_dual_L1_trigger PORT MAP (
          TOP_LCP => TOP_LCP,
          TOP_RCP => TOP_RCP,
          MID_LCP => MID_LCP,
          MID_RCP => MID_RCP,
          BOT_LCP => BOT_LCP,
          BOT_RCP => BOT_RCP,
          mask_i => mask_i,
			 force_i => force_i,
          L1_scaler_o => L1_scaler_o,
          L2_scaler_o => L2_scaler_o,
          clk_i => clk_i,
          mclk_i => mclk_i,
          trig_o => trig_o_uut
        );



--    uut2: ANITA4_simple_trigger PORT MAP (clk33_i => mclk_i,
-- 											  clk250_i => clk_i,
-- 											  clk250b_i => clk250b_i,
-- 											  ant_mask_i => ant_mask_i,
-- 											  phi_mask_i => phi_mask_i,
-- 											  disable_i => disable_i,
--                                    			  rf_scal_o => rf_trigger_scaler,
--                                    gated_rf_scal_o => gated_rf_scaler,
-- 											  scal_o => phi_scaler,
-- 											  scal_L2_o => L2_scaler,
-- 											  refpulse_i => refpulse_i,
-- 											  mon_scal_o => phi_mon_scaler,
-- 											  L2_i => trig_o_uut,
--                                               L2B_i => L2B_i,
-- 											  trig_o => rf_trigger,
-- 											  phi_o => phi_pattern,
-- 											  count_o => rf_count);

   uut2: Simpler_Trigger PORT MAP (clk33_i => mclk_i,
											  clk250_i => clk_i,
											  refpulse_i => refpulse_i,
											  L2_i => trig_o_uut,
											  trig_o => rf_trigger,
											  count_o => rf_count);


uut3 : entity work.new_buffer_handler_simpleFSM3  PORT MAP (
					clk250_i  => clk_i,
					rst_i => rst_i,
					trig_i => rf_trigger, -- was DO_HOLD, forced and rf_triggerer
					-- trig_buffer_o => trig_buffer_o, -- unconnected on top - leave for consistency 
					clear_i => clear_to_buffer_handler, -- used to generate RELEASE
					clear_buffer_i => clear_buffer_to_buffer_handler, -- used to generate RELEASE
					digitize_hold_o => digitize_hold_o, -- new:  
					-- digitize_buffer_o => digitize_buffer_o, -- 2 bits for legacy - needs only one to indicate which
																							-- of the pairs is being digitized - NEW signal
					digitize_lab_o => digitize_lab_o,  -- needs to be kept 100 ns. -- it should always be kept for at least 88 ns is that enough?
					HOLD_o => HOLD_o, --done
					buffer_status_o => buffer_status_o, -- done
					dead_o => dead_o, --done
					--debug_state : out std_logic_vector(1 downto 0)
					debug_o => debug_o 
					
					);

   uut4: LAB_TOPv2 PORT MAP (
		clk_i => clk_i,
		clk100_i => clk100_i,
		rst_i => rst_i,
		hold_i => HOLD_o,
		digitize_i => digitize_lab_o,
			 
	    A_SELTAIL => 	A_SELTAIL,
	    A_SELMAIN => 	A_SELMAIN,
		A_GCK => 	A_GCK,
		A_RAMP	 => A_RAMP,
		A_GCCLR	 => A_GCCLR,
		A_NRUN => 	A_NRUN,
	    A_CS =>  A_CS,
	    A_S =>  A_S,
	    A_HITBUS =>  A_HITBUS,
	    A_RCO =>   A_RCO,
	    A_DAT =>   A_DAT,

		B_GCK => 	B_GCK,
		B_RAMP => 	B_RAMP,
		B_GCCLR	 => B_GCCLR,
		B_NRUN => 	B_NRUN,
	        B_SELTAIL => 	B_SELTAIL,
	       B_SELMAIN => 	 B_SELMAIN,
	    B_CS  =>  B_CS,
	    B_S =>  B_S,
	    B_HITBUS  => B_HITBUS,
	    B_RCO  =>  B_RCO ,
	    B_DAT =>   B_DAT,

		C_GCK => 	C_GCK,
		C_RAMP	 => C_RAMP,
		C_GCCLR	  => C_GCCLR,			 
		C_NRUN	 =>  C_NRUN,
	       C_SELTAIL => 	C_SELTAIL,
	       C_SELMAIN => 	C_SELMAIN,
	    C_CS  =>  C_CS,
	    C_S =>   C_S,
	       C_RCO  =>  C_RCO,
	       C_HITBUS   => C_HITBUS,
	       C_DAT  => C_DAT,

			D_GCK	 => D_GCK,
			D_RAMP => 	D_RAMP,
			D_GCCLR	 => D_GCCLR	,		 
			D_NRUN	 => D_NRUN,
	        	    D_SELTAIL	 => D_SELTAIL,
	        	    D_SELMAIN => 	D_SELMAIN,
	        D_CS  =>  D_CS,
	        D_S  =>  D_S,
	       D_RCO =>  D_RCO,
	       D_HITBUS  =>  D_HITBUS,
	       D_DAT =>   D_DAT,
			-- [12:11] select which LAB is being read out.
			 addr_i  =>  addr_i,
			 dat_o  =>   dat_o,
			 lab_done_o => lab_done_o, --by me
			 done_o	 =>  done_o,
			 debug_tp_i   =>  debug_tp_i,
			 debug_sel_i   =>  debug_sel_i,
			 debug_o  =>  debug_o1
    );


uut5: entity work.decode_digitize PORT MAP (
	clk250_i  => clk_i,
	rst_i  => rst_i,
	digitize_lab_in  => digitize_lab_o,
	lab_done_in => lab_done_o,
	clear_o => clear_to_buffer_handler,
	clear_buffer_o => clear_buffer_to_buffer_handler,
	event_o => event_mess,
	event_done_o => event_done_mess
 
);


	write_file : process(clk_i)
		variable out_line : line;
		variable clk_tick : integer range 1001 downto 0 := 0; 
		variable the_line : std_logic_vector(15 downto 0);
		file out_file     : text is out "results.txt";
	begin
		if rising_edge(clk_i) then
			clk_tick := clk_tick + 1;
			
			--the_line(0) := std_logic(to_unsigned(clk_tick));
			the_line(11 downto 0) := TOP_RCP & TOP_LCP & MID_RCP & MID_LCP & BOT_RCP & BOT_LCP;
			the_line(15 downto 12):= trig_o_uut;
			write (out_line, the_line);
			writeline (out_file, out_line);
		end if;
		
	end process write_file;
   -- Clock process definitions
   clk_i_process :process
   begin
		clk_i <= '0';
		wait for clk_i_period/2;
		clk_i <= '1';
		wait for clk_i_period/2;
   end process;
	
	mclk_i_process :process
   begin
		mclk_i <= '0';
		wait for mclk_i_period/2;
		mclk_i <= '1';
		wait for mclk_i_period/2;
   end process;

	clk100_i_process :process
   begin
		clk100_i <= '0';
		wait for clk100_i_period/2;
		clk100_i <= '1';
		wait for clk100_i_period/2;
   end process;

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
	  rst_i <= '1';
      wait for 100 ns;	
	  rst_i <= '0';
		-- digitize_buffer_o <="00";
      --wait for clk_i_period*10; 
	  wait for 100 ns;
		wait for 8 ns;
		BOT_LCP(0) <= '0';
		BOT_RCP(0) <= '0';
		MID_LCP(0) <= '1';
		MID_RCP(0) <= '1';
		 wait for 2 ns;
		MID_LCP(0) <= '0';
		MID_RCP(0) <= '0';
		BOT_LCP(0) <= '0';
		BOT_RCP(0) <= '0';
		wait for 5 ns;
		MID_LCP(0) <= '0';
		MID_RCP(0) <= '0';
		BOT_LCP(0) <= '1';
		BOT_RCP(0) <= '1';
		wait for 2 ns;
		--TOP_LCP(0) <= '1';
		--TOP_RCP(0) <= '1';
		--wait for 2 ns;
		--BOT_LCP[0] <= '0';
		--BOT_RCP[0] <= '0';
		BOT_LCP(0) <= '0';
		BOT_RCP(0) <= '0';
		MID_LCP(0) <= '0';
		MID_RCP(0) <= '0';
		wait for 40 ns;
		TOP_LCP(0) <= '0';
		TOP_RCP(0) <= '0';
		wait for 2 ns;
		
		wait for 2 ns;
		TOP_LCP(0) <= '1';
		TOP_RCP(0) <= '1';
		wait for 2 ns;
		TOP_LCP(0) <= '0';
		TOP_RCP(0) <= '0';
		wait for 2 ns;
		
      -- insert stimulus here 

      wait;
   end process;
	
END;
