----------------------------------------------------------------------------------

-- Additional Comments: 
-- 08/3/2023 Mudit Mishra
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity event_data is
port(
-- clk250_i : in std_logic :='0'; -- was 125
clk33_i : in std_logic :='0'; -- was 125
rst_i : in std_logic :='0';
event_gen_flag_i : in std_logic :='0';
event_buffer_i : in std_logic_vector(1 downto 0);

event_o : out  std_logic_vector(31 downto 0);
event_done_o : out  std_logic;
lab_num_o : out  std_logic_vector(1 downto 0)
 
);
end event_data;

architecture Behavioral of event_data is

type state_t is (IDLE, evt_A, evt_B, evt_C, evt_D);
signal state : state_t := IDLE;


signal lab_num : std_logic_vector(1 downto 0) := (others => '0');
signal event_out : std_logic_vector(31 downto 0) := (others => '0');
signal event_done_out: std_logic :='0';
constant ZERO_C   : std_logic_vector(19 downto 0) := (others => '0');

-- ---------------------------------------
--     COMPONENT flag_sync PORT(
--         clkA : in std_logic;
--         clkB : in std_logic;
--         in_clkA : in std_logic;
--         busy_clkA : out std_logic;
--         out_clkB : out std_logic
--         );
-- 	END COMPONENT;


begin

process(clk33_i, rst_i)
begin
	if rst_i = '1' then
        event_out <= (others =>'0');
        state <= IDLE;
        event_done_out <= '0';
        lab_num <="00";

	
	elsif rising_edge(clk33_i) then
        event_out <= (others =>'0');
        event_done_out <= '0';
        lab_num <="00";

		case state is 
			when IDLE =>
				if event_buffer_i = "01" and event_gen_flag_i = '1' then
					state <= evt_A;

				elsif event_buffer_i = "10" and event_gen_flag_i = '1' then
					state <= evt_C; 
                else
                    state <= IDLE;
				end if;
			when evt_A => 
                event_out <= ZERO_C  & "0000000000" & "01"; --A and B are read out
                event_done_out <= '1';
                lab_num <="00";
                state <= evt_B;

			when evt_B => 
                event_out <= ZERO_C  & "0000000000" & "10"; --A and B are read out
                event_done_out <= '1';
                lab_num <="01";
                state <= IDLE;

			when evt_C => 
                event_out <= ZERO_C  & "0000000001" & "00"; --A and B are read out
                event_done_out <= '1';
                lab_num <="10";
                state <= evt_D;

			when evt_D => 
                event_out <= ZERO_C  & "0000000010" & "00"; --A and B are read out
                event_done_out <= '1';
                lab_num <="11";
                state <= IDLE;                	
            when others =>
                state <= IDLE;
			end case;
	end if;
end process;


event_o <= event_out;
event_done_o <= event_done_out;
lab_num_o <= lab_num;
end Behavioral;




