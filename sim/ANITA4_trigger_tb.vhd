--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   08:08:20 07/16/2016
-- Design Name:   
-- Module Name:   C:/Users/EDG/Downloads/firmware-surf-master/firmware-surf-master/sim/ANITA4_trigger_tb.vhd
-- Project Name:  SURFv38
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ANITA4_L1_TRIGGER_PIPE
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
 
ENTITY ANITA4_trigger_tb IS
END ANITA4_trigger_tb;
 
ARCHITECTURE behavior OF ANITA4_trigger_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ANITA4_L1_TRIGGER_PIPE
    PORT(
         REF_PULSE : IN  std_logic;
         CLK : IN  std_logic;
         BOTTOM : IN  std_logic_vector(1 downto 0);
         MIDDLE : IN  std_logic_vector(1 downto 0);
         TOP : IN  std_logic_vector(1 downto 0);
         MASK : IN  std_logic_vector(2 downto 0);
         L1 : OUT  std_logic_vector(2 downto 0);
         ANT_HITS : OUT  std_logic_vector(5 downto 0);
			ONESHOTS_DEBUG : OUT std_logic_vector(2 downto 0);
         L2 : OUT  std_logic
        );
    END COMPONENT;
    
   --Inputs
   signal REF_PULSE : std_logic := '0';
   signal CLK : std_logic := '0';
   signal BOTTOM : std_logic_vector(1 downto 0) := (others => '1');
   signal MIDDLE : std_logic_vector(1 downto 0) := (others => '1');
   signal TOP : std_logic_vector(1 downto 0) := (others => '1');
   signal MASK : std_logic_vector(2 downto 0) := (others => '1');

 	--Outputs
   signal L1 : std_logic_vector(2 downto 0);
   signal ANT_HITS : std_logic_vector(5 downto 0);
   signal ONESHOTS_DEBUG : std_logic_vector(2 downto 0);
	signal L2 : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 4 ns; --250MHz
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ANITA4_L1_TRIGGER_PIPE PORT MAP (
          REF_PULSE => REF_PULSE,
          CLK => CLK,
          BOTTOM => BOTTOM,
          MIDDLE => MIDDLE,
          TOP => TOP,
          MASK => MASK,
          L1 => L1,
          ANT_HITS => ANT_HITS,
			 ONESHOTS_DEBUG => ONESHOTS_DEBUG,
          L2 => L2
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 
	-- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_period*2;

      -- insert stimulus here 
		wait for 3 ns;
		BOTTOM <= (others=>'0');
		
		wait for 5 ns;
		MIDDLE <= (others=>'0');

		wait for 10 ns;
		TOP <= (others=>'0');
      wait;
   end process;

END;
