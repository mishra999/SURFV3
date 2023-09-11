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

entity decode_digitize is
port(
-- clk250_i : in std_logic :='0'; -- was 125
clk33_i : in std_logic :='0'; -- was 125
rst_i : in std_logic :='0';
digitize_lab_in : in std_logic_vector(3 downto 0); -- done
lab_done_in : in std_logic_vector(3 downto 0);
clear_o : out std_logic :='0'; -- used to generate RELEASE
clear_buffer_o : out  std_logic_vector(1 downto 0)
-- event_o : out  std_logic_vector(11 downto 0);
-- event_done_o : out  std_logic
 
);
end decode_digitize;

architecture Behavioral of decode_digitize is

type state_t is (IDLE, dig_AB, dig_ABCD, dig_CD, dig_CDAB);
signal state : state_t := IDLE;


signal digitize_lab_i : std_logic_vector(3 downto 0) := "0000";
signal lab_done_i : std_logic_vector(3 downto 0) := "0000";
signal clear_buffer_out : std_logic_vector(1 downto 0) := "00";
signal clear_out: std_logic :='0';
-- signal event_out : std_logic_vector(31 downto 0) := (others => '0');
-- signal event_done_out: std_logic :='0';
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

digitize_lab_i <= digitize_lab_in;
lab_done_i <= lab_done_in;


process(clk33_i, rst_i)
begin
	if rst_i = '1' then
		clear_out <= '0';
		clear_buffer_out <= "00";
        -- event_out <= (others =>'0');
        state <= IDLE;
        -- event_done_out <= '0';

	
	elsif rising_edge(clk33_i) then
		clear_out <= '0';
		clear_buffer_out <= "00";

		case state is 
			when IDLE =>
				if digitize_lab_i = "0011" then
					state <= dig_AB;
                else
                    state <= IDLE;
				end if;
			when dig_AB => 
				if lab_done_i = "0011" then 
					state <= IDLE;
                    clear_out <= '1';
                    clear_buffer_out <= "01";
                elsif digitize_lab_i = "1100" then
                    state <= dig_ABCD;
                else
					state <= dig_AB;		
				end if;
            
            when dig_ABCD => 
                if lab_done_i = "0011" then 
                    state <= dig_CD;
                    clear_out <= '1';
                    clear_buffer_out <= "01";
                else
                    state <= dig_ABCD;		
                end if;

			when dig_CD => 
				if lab_done_i = "1100" then -- use a mask anding because of the way lab_done works
					state <= IDLE;
                    clear_out <= '1';
                    clear_buffer_out <= "10";
                elsif digitize_lab_i = "0011" then
                    state <= dig_CDAB;
                else
					state <= dig_CD;		
				end if;	

            when dig_CDAB => 
            if lab_done_i = "1100" then 
                state <= dig_AB;
                clear_out <= '1';
                clear_buffer_out <= "10";
            else
                state <= dig_CDAB;		
            end if;

            when others =>
                state <= IDLE;
			end case;
	end if;
end process;



clear_o <= clear_out;
clear_buffer_o <= clear_buffer_out;
-- event_o <= event_out;
-- event_done_o <= event_done_out;

end Behavioral;




