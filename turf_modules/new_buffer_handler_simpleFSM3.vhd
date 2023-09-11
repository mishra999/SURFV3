----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:19:46 07/18/2014 
-- Design Name: 
-- Module Name:    new_buffer_handler - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
-- 07/31/2023 Mudit Mishra
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity new_buffer_handler_simpleFSM3 is
port(
clk250_i : in std_logic :='0'; -- was 125
clk33_i : in std_logic :='0'; -- was 33
rst_i : in std_logic :='0';
trig_i : in std_logic :='0'; -- was DO_HOLD, forced and rf_triggerer
-- trig_buffer_o : out std_logic_vector(1 downto 0); -- unconnected on top - leave for consistency 
clear_i : in std_logic :='0'; -- used to generate RELEASE
clear_buffer_i : in  std_logic_vector(1 downto 0) := (others => '0'); -- used to generate RELEASE
digitize_hold_o : out std_logic :='0'; -- new: a 100 ns pulse from the time either of the pairs go into second hold - should work as there is a holdoff. 
-- digitize_buffer_o : out std_logic_vector(1 downto 0); -- 2 bits for legacy - needs only one to indicate which
		    															-- of the pairs is being digitized - NEW signal
digitize_lab_33o : out std_logic_vector(3 downto 0):= (others => '0');  -- needs to be kept 100 ns. -- it should always be kept for at least 88 ns is that enough?
HOLD_o : out std_logic_vector(3 downto 0):= (others => '0'); --done
buffer_status_o : out std_logic_vector(3 downto 0):= (others => '0'); -- done
dead_o : out std_logic; --done
--debug_state : out std_logic_vector(1 downto 0)
debug_o : out std_logic_vector(34 downto 0) := (others => '0')
 
);
end new_buffer_handler_simpleFSM3;

architecture Behavioral of new_buffer_handler_simpleFSM3 is

type state_t is (A, B, C, D);
signal state : state_t := A;

signal used : std_logic_vector(1 downto 0):= "00";

signal veto_hold_counter : std_logic_vector(4 downto 0) := "00000";

constant WAIT_FOR_SECOND_LAB : integer := 22; -- 88 ns between first and second hold to guarantee overlap 
constant WAIT_FOR_NEW_DATA_TC : integer := 26; -- 104 ns wait to guarantee filling up a full LAB


signal shreg_to_release_0 : std_logic_vector(WAIT_FOR_NEW_DATA_TC-1 downto 0);
signal shreg_to_release_2 : std_logic_vector(WAIT_FOR_NEW_DATA_TC-1 downto 0);
signal shreg_to_release_1 : std_logic_vector(WAIT_FOR_SECOND_LAB-1 downto 0);
signal shreg_to_release_3 : std_logic_vector(WAIT_FOR_SECOND_LAB-1 downto 0);


signal digitize_counter: std_logic_vector(4 downto 0):= (others =>'0');
signal trig_latched: std_logic :='0';
-- signal trig_to_latch: std_logic :='0';

signal trig_comb: std_logic:= '0';
signal trig_comb33: std_logic:= '0';
signal digitize_lab :std_logic_vector(3 downto 0);



signal HOLD_A :  std_logic := '0';
signal HOLD_B :  std_logic := '0';
signal HOLD_C :  std_logic := '0';
signal HOLD_D :  std_logic := '0';

signal RELEASE :  std_logic_vector(1 downto 0); -- indicates that a digitization is finished - needs to know which pair...
																-- now done using clear_buffers

signal digitize_hold : std_logic := '0';
signal digitize_hold33 : std_logic := '0';


signal 	trig_comb_prolong, trig_comb_del1, trig_comb_del2, trig_comb_del3 : std_logic;


signal debug_state :  std_logic_vector(1 downto 0);
signal debug_state33 : std_logic_vector(1 downto 0);

signal clr_2 :  std_logic_vector(1 downto 0);
signal trig_input  : std_logic := '0';
signal trig_input_debug  : std_logic := '0';


---------------------------------------
    COMPONENT flag_sync 
	-- generic (
	-- 	CLKA : STRING  := "POSEDGE");
		PORT(
        clkA : in std_logic;
        clkB : in std_logic;
        in_clkA : in std_logic;
        busy_clkA : out std_logic;
        out_clkB : out std_logic
        );
	END COMPONENT;



begin
	-- trig_input_debug <= trig_i;
	--trig_input occurs at the rising edge for 1 cycle
	ref_trigger_inst : entity work.ref_trigger
	port map (
	  clk250_i => clk250_i,
	  ext_trig_i => trig_i,
	  ext_trg_o => trig_input
	);
  


clk_change :  --label name
   for ii in 0 to 3 generate  
    begin  --"begin" statement for "generate"
    u_sync1 : flag_sync 
        port map (
            clkA => clk250_i,
            clkB => clk33_i ,
            in_clkA => digitize_lab(ii),
			busy_clkA => open,
			out_clkB => digitize_lab_33o(ii)
        );
   end generate;  --end "generate" block.

-- trig_buffer_o <= "00"; -- unused
buffer_status_o<= "0000"; -- always constant!
digitize_hold_o <= digitize_hold;
HOLD_o <=HOLD_D & HOLD_C & HOLD_B & HOLD_A;
trig_comb <= trig_input;--(0) or trig_i(1); --  or trig_i(2) or trig_i(3)
-- trig_to_latch<= trig_i and trig_comb; --& (trig_i(0) and trig_comb); -- & (trig_i(1) and trig_comb) & (trig_i(0) and trig_comb);

--clear on rising edge/clearing process by me
process(clk250_i, rst_i)
begin 
	if rising_edge(clk250_i) then
		clr_2 <= "00";
		if clear_i = '1' then
			clr_2(0) <= clear_i;
			clr_2(1) <= clr_2(0);
		end if;
	end if;
end process;

-- latching process
process(clk250_i, rst_i)
begin
	if rst_i = '1' then
		dead_o <= '0';
		RELEASE <= "00";
		-- clr_2 <= "00"; --by me
	elsif rising_edge(clk250_i) then
		if (trig_comb = '1') and (state = A or state = C) then trig_latched <= trig_comb; end if;
--		trig_latched <= trig_to_latch;
		dead_o <= (HOLD_D or HOLD_C) and (HOLD_B or HOLD_A); -- if even only one of the chip is held, we need to wait to start issuing triggers.
		if clr_2 = "01" then
			trig_latched <= '0'; -- to ensure it is zero when next trigger arrives
			case clear_buffer_i is 
			when "01" => RELEASE(0)<= '1';
			when "10" => RELEASE(1)<= '1';
			when others => RELEASE <= "00";
			end case;
		else
			RELEASE <= "00";
		end if;
	end if;
end process;


-- Main process to control which pair gets the hold. Needs release info to know when a pair is again available.
-- if both are available it continuously ping-pongs.

process(clk250_i, rst_i)
begin
	if rst_i = '1' then
		used <= "00";
		HOLD_A<= '0';
		HOLD_B<= '0';
		HOLD_C<= '0';
		HOLD_D<= '0';
		digitize_hold<= '0';
		-- digitize_buffer_o<= "00";
		state <= A;
		
-- does not meet timing at time_to_release -> try duplicating the register
	elsif rising_edge(clk250_i) then
		shreg_to_release_0(WAIT_FOR_NEW_DATA_TC-1 downto 1) <= shreg_to_release_0(WAIT_FOR_NEW_DATA_TC-2 downto 0);
		shreg_to_release_2(WAIT_FOR_NEW_DATA_TC-1 downto 1) <= shreg_to_release_2(WAIT_FOR_NEW_DATA_TC-2 downto 0);
		shreg_to_release_1(WAIT_FOR_SECOND_LAB-1 downto 1) <= shreg_to_release_1(WAIT_FOR_SECOND_LAB-2 downto 0);
		shreg_to_release_3(WAIT_FOR_SECOND_LAB-1 downto 1) <= shreg_to_release_3(WAIT_FOR_SECOND_LAB-2 downto 0);
		
		shreg_to_release_0(0) <= '0';
		shreg_to_release_1(0) <= '0';
		shreg_to_release_2(0) <= '0';
		shreg_to_release_3(0) <= '0';

		digitize_lab <= "0000";
		
		case state is 
			when A =>
				debug_state<= "00";
				if used(0) = '0' and shreg_to_release_0(WAIT_FOR_NEW_DATA_TC-1) = '1' and trig_comb = '1' then
--				if used /= "11" and shreg_to_release_0(WAIT_FOR_NEW_DATA_TC-1) = '1' and trig_comb = '1' then
					state <= B;
					used(0) <= '1';
					HOLD_A<='1';
					-- digitize_buffer_o<= "00";
					digitize_hold<= '1';
					shreg_to_release_1(0) <='1'; -- the first 1 will emerge after WAIT_FOR_SECOND_LAB clock cycles
				else
					shreg_to_release_0(0) <= not used(0); -- so it will keep remembering that the time has passed
--					shreg_to_release_0(0) <= '1'; -- so it will keep remembering that the time has passed
					state <= A;
				end if;
			when B => 
				debug_state<= "01";
				if shreg_to_release_1(WAIT_FOR_SECOND_LAB-1) = '1' then
					state <= C;
					HOLD_B<='1';
					shreg_to_release_2(0) <='1'; -- the first 1 will emerge after WAIT_FOR_SECOND_LAB clock cycles
					digitize_hold<= '0';
					digitize_lab<="00" & trig_latched & trig_latched; -- digitize only if it gets latched		
				else
					shreg_to_release_1(0) <='1'; -- the first 1 will emerge after WAIT_FOR_SECOND_LAB clock cycles - it will keep
														  -- feeding 1 so that even if the first get lost, this is not a deadlock state
					
					state <= B;			
				end if;
			when C =>
				debug_state<= "10";
				if used(1) = '0' and shreg_to_release_2(WAIT_FOR_NEW_DATA_TC-1) = '1' and trig_comb = '1' then
--				if used /= "11" and shreg_to_release_2(WAIT_FOR_NEW_DATA_TC-1) = '1' and trig_comb = '1' then
					state <= D;
					used(1) <= '1';
					HOLD_C<='1';
					-- digitize_buffer_o<= "01";
					digitize_hold<= '1';
					shreg_to_release_3(0) <= '1';
				else
					shreg_to_release_2(0) <= not used(1); -- so it will keep remembering that the time has passed
--					shreg_to_release_2(0) <= '1'; -- so it will keep remembering that the time has passed
					state <= C;
				end if;				
			when D => 
				debug_state<= "11";
				if shreg_to_release_3(WAIT_FOR_SECOND_LAB-1) = '1' then
					state <= A;
					HOLD_D<='1';
					shreg_to_release_0(0) <='1'; -- the first 1 will emerge after WAIT_FOR_SECOND_LAB clock cycles
					digitize_hold<= '0';
					digitize_lab<=trig_latched & trig_latched & "00"; -- digitize only if it gets latched		
				else
					shreg_to_release_3(0) <='1'; -- the first 1 will emerge after WAIT_FOR_SECOND_LAB clock cycles - it will keep
														  -- feeding 1 so that even if the first get lost, this is not a deadlock state
					
					state <= D;
				end if;					
			end case;
			if RELEASE(0) = '1' then HOLD_A<= '0'; HOLD_B<= '0'; used(0) <= '0'; end if; 
			if RELEASE(1) = '1' then HOLD_C<= '0'; HOLD_D<= '0'; used(1) <= '0'; end if;
	end if;
end process;


trig_comb_prolong_p: process(clk250_i)
begin
	if rising_edge(clk250_i) then
		trig_comb_del1 <= trig_comb;
		trig_comb_del2 <= trig_comb_del1;
		trig_comb_del3 <= trig_comb_del2;
		trig_comb_prolong<=trig_comb or trig_comb_del1 or trig_comb_del2 or trig_comb_del3;
	end if;
	
end process;


-- u_syncdebug1 : flag_sync 
-- port map (
-- 	clkA => clk250_i,
-- 	clkB => clk33_i ,
-- 	in_clkA => trig_comb,
-- 	busy_clkA => open,
-- 	out_clkB => trig_comb33
-- );

-- u_syncdebug2 : flag_sync 
-- port map (
-- 	clkA => clk250_i,
-- 	clkB => clk33_i ,
-- 	in_clkA => digitize_hold,
-- 	busy_clkA => open,
-- 	out_clkB => digitize_hold33
-- );
-- u_syncdebug3 : flag_sync 
-- port map (
-- 	clkA => clk250_i,
-- 	clkB => clk33_i ,
-- 	in_clkA => trig_i,
-- 	busy_clkA => open,
-- 	out_clkB => trig_input_debug
-- );
debug_o(1 downto 0) <= debug_state;
-- debug_o(0) <= trig_input_debug;
debug_o(2) <= trig_i;
-- debug_o(3) <= shreg_to_release_0(WAIT_FOR_NEW_DATA_TC-1);
debug_o(5 downto 4) <= used;
debug_o(6) <= digitize_hold;

--output to LABv2
-- digitize_lab_33o <= digitize_lab;

end Behavioral;




