library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity Dec_7_SEG_tb is
end;

architecture bench of Dec_7_SEG_tb is

  component Dec_7_SEG
      Port ( sw : in STD_LOGIC_VECTOR (3 downto 0);
             ck_io : out STD_LOGIC_VECTOR (6 downto 0));
  end component;

  signal sw: STD_LOGIC_VECTOR (3 downto 0);
  signal ck_io: STD_LOGIC_VECTOR (6 downto 0);

begin

  uut: Dec_7_SEG port map ( sw    => sw,
                            ck_io => ck_io );

  stimulus: process
  begin
  
    -- Put initialisation code here
    sw <= "0000";
    wait for 10ns;
    sw <= "0001";
    wait for 10ns;
    sw <= "0010";
    wait for 10ns;
    sw <= "0011";
    wait for 10ns;
    sw <= "0100";
    wait for 10ns;
    sw <= "0101";
    wait for 10ns;
    sw <= "0110";
    wait for 10ns;
    sw <= "0111";
    wait for 10ns;
    sw <= "1000";
    wait for 10ns;
    sw <= "1001";
    wait for 10ns;
    

    -- Put test bench stimulus code here

    wait;
  end process;


end;