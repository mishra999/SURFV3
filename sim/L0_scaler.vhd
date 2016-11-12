--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:30:25 07/19/2016
-- Design Name:   
-- Module Name:   C:/Users/EDG/Desktop/firmware-surf/sim/L0_scaler.vhd
-- Project Name:  SURFv38
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: L0_scaler_single
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
 
ENTITY L0_scaler IS
END L0_scaler;
 
ARCHITECTURE behavior OF L0_scaler IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT L0_scaler_single
    PORT(
         clk100_i : IN  std_logic;
         mclk_i : IN  std_logic;
         trig_i : IN  std_logic;
         pulse_o : OUT  std_logic;
         stuck_o : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk100_i : std_logic := '0';
   signal mclk_i : std_logic := '0';
   signal trig_i : std_logic := '0';

 	--Outputs
   signal pulse_o : std_logic;
   signal stuck_o : std_logic;

   -- Clock period definitions
   constant clk100_i_period : time := 10 ns;
   constant mclk_i_period   : time := 33.33 ns;

BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: L0_scaler_single PORT MAP (
          clk100_i => clk100_i,
          mclk_i => mclk_i,
          trig_i => trig_i,
          pulse_o => pulse_o,
          stuck_o => stuck_o
        );

   -- Clock process definitions
   clk100_i_process :process
   begin
		clk100_i <= '0';
		wait for clk100_i_period/2;
		clk100_i <= '1';
		wait for clk100_i_period/2;
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
		trig_i <= '0';
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      -- wait for clk100_i_period*10;
		
		wait for 50 ns;
		trig_i <= '1';
		wait for 4 ns;
		trig_i <= '0';
		
		wait for 70 ns;
		trig_i <= '1';
		wait for 4 ns;
		trig_i <= '0';
      
		wait for 70 ns;
		trig_i <= '1';
		wait for 4 ns;
		trig_i <= '0';
		
		wait for 200 ns;
		trig_i <= '1';
		wait for 4 ns;
		trig_i <= '0';
		
		wait for 40 ns;
		trig_i <= '1';
		wait for 4 ns;
		trig_i <= '0';
		
		wait for 40 ns;
		trig_i <= '1';
		wait for 4 ns;
		trig_i <= '0';
		
		wait for 40 ns;
		trig_i <= '1';
		wait for 4 ns;
		trig_i <= '0';
		
		
		-- insert stimulus here 

      wait;
   end process;

END;
