library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_MISC.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

--! Simpe trigger
--! Mudit Mishra 7/29/2023
--!


entity Simpler_Trigger is
    generic (
        NUM_TRIG : integer :=4;
        NUM_HOLD : integer := 4
    );
    port (
        clk250_i                : in  std_logic := '0';
        clk33_i              : in  std_logic := '0';
        L2_i                : in std_logic_vector(NUM_TRIG-1 downto 0) := "0000";
        refpulse_i              : in  std_logic := '0';
        trig_o                : out std_logic := '0';
        count_o            : out std_logic_vector(7 downto 0) := "00000000";
        gated_forced_o               : out std_logic := '0'

    );
end Simpler_Trigger;


architecture Behavioral of Simpler_Trigger is

    signal raw_rf_trigger : std_logic_vector(1 downto 0) := (others => '0');
    signal rf_count_flag      : std_logic := '0';
    signal raw_rf_count : std_logic_vector(7 downto 0) := (others => '0');
    signal trigger_holdoff : std_logic := '0';

    signal refpulse_elongated : std_logic := '0';
    signal rst_i : std_logic := '0';
    -- signal holdoff_o : std_logic := '0';
    signal gated_trigger : std_logic := '0';
    signal rf_trigger  : std_logic := '0';
    signal rf_count: std_logic_vector(7 downto 0) := (others => '0');
    signal triggered_flag  : std_logic := '0';


    ---------------------------------------
    COMPONENT srl_oneshot
        PORT(
            clk250_i : IN  std_logic;
            trig_i : IN  std_logic;
            scal_o :OUT  std_logic
        );
    END COMPONENT;

    COMPONENT ANITA3_trigger_holdoff
        PORT(
            clk250_i : IN  std_logic;
            rst_i : IN  std_logic;
            trig_i : IN  std_logic;
            holdoff_o :OUT  std_logic
        );
    END COMPONENT;

begin



    srl_oneshot_inst1 : srl_oneshot 
        port map (
            clk250_i => clk250_i,
            trig_i => refpulse_i ,
            scal_o => refpulse_elongated
        );

    ANITA3_trigger_holdoff1_inst : ANITA3_trigger_holdoff
        port map (
            clk250_i => clk250_i,
            rst_i  => rst_i,
            trig_i => rf_count_flag ,
            holdoff_o => trigger_holdoff
        );




    process (clk250_i)
    begin
        if rising_edge(clk250_i) then
            gated_trigger <= '0';
            rf_trigger <= L2_i(0) and not (trigger_holdoff);
            raw_rf_trigger <= raw_rf_trigger(raw_rf_trigger'left - 1 downto 0) & L2_i(0);
            rf_count_flag <= raw_rf_trigger(0) and (not raw_rf_trigger(1));
            if rf_count_flag = '1' then 
                raw_rf_count <= raw_rf_count + '1';
                triggered_flag <= rf_count_flag;
            end if;
            if (triggered_flag  and trigger_holdoff) = '1' then 
                rf_count <= raw_rf_count;
            end if;
            if (rf_trigger  and refpulse_elongated) = '1' then --coincidence between ref_pulse_eleongated and rf_trigger to GPR
                gated_trigger <= '1';
            end if;
            -- if gated_trigger ='1' then
            --     gated_trigger <= '0'; --set for just 1 cycle
            -- end if;
        end if;
    end process;

    trig_o <= rf_count_flag;
    gated_forced_o <= gated_trigger;
    count_o <= rf_count;

end Behavioral;
