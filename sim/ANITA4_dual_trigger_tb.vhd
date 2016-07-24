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
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY ANITA4_dual_trigger_tb IS
END ANITA4_dual_trigger_tb;
 
ARCHITECTURE behavior OF ANITA4_dual_trigger_tb IS 
 
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
   signal clk_i : std_logic := '0';
   signal mclk_i : std_logic := '0';

 	--Outputs
   signal L1_scaler_o : std_logic_vector(5 downto 0);
   signal L2_scaler_o : std_logic_vector(1 downto 0);
   signal trig_o : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant clk_i_period : time := 4 ns;
	constant mclk_i_period : time := 33.333 ns;
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ANITA4_dual_L1_trigger PORT MAP (
          TOP_LCP => TOP_LCP,
          TOP_RCP => TOP_RCP,
          MID_LCP => MID_LCP,
          MID_RCP => MID_RCP,
          BOT_LCP => BOT_LCP,
          BOT_RCP => BOT_RCP,
          mask_i => mask_i,
          L1_scaler_o => L1_scaler_o,
          L2_scaler_o => L2_scaler_o,
          clk_i => clk_i,
          mclk_i => mclk_i,
          trig_o => trig_o
        );

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
 
   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      --wait for clk_i_period*10; 
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
