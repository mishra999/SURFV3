library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_MISC.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

--! Simpe trigger
--! Mudit Mishra 7/29/2023
--!


entity ref_trigger is
    port (
        clk250_i                : in  std_logic := '0'; --made it 33 MHZ on top modlue
        ext_trig_i              : in  std_logic := '0';
        ext_trg_o               : out std_logic := '0'

    );
end ref_trigger;


architecture Behavioral of ref_trigger is

    signal raw_rf_trigger : std_logic_vector(1 downto 0) := (others => '0');
    signal rf_count_flag      : std_logic := '0';
    signal ext_trg_out : std_logic := '0';

    signal ext_trig_in : std_logic := '0';


begin



    ext_trig_in <= ext_trig_i;


--get rising edge of the ext trigger
    process (clk250_i)
    begin
        if rising_edge(clk250_i) then
            ext_trg_out <= '0';
            raw_rf_trigger <= raw_rf_trigger(raw_rf_trigger'left - 1 downto 0) & ext_trig_in;
            rf_count_flag <= raw_rf_trigger(0) and (not raw_rf_trigger(1));
            if rf_count_flag = '1' then 
                ext_trg_out <= '1';
                
            end if;
        end if;
    end process;

    ext_trg_o <= ext_trg_out;

end Behavioral;
