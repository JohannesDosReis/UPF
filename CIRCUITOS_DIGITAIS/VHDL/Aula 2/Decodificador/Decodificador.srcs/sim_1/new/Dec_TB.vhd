
library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity Dec_tb is
end;

architecture bench of Dec_tb is

  component Dec
      Port ( A : in STD_LOGIC_VECTOR (2 downto 0);
             L : out STD_LOGIC_VECTOR (7 downto 0));
  end component;

  signal A: STD_LOGIC_VECTOR (2 downto 0);
  signal L: STD_LOGIC_VECTOR (7 downto 0);

begin

  uut: Dec port map ( A => A,
                      L => L );
    
    
  stimulus: process
  begin
  
    -- Put initialisation code here
    A <= "000";
    wait for 10ns;
    
    for i in 0 to 7 loop
        A <= std_logic_vector(unsigned(A) + 1); 
        wait for 10ns;
    end loop;

    -- Put test bench stimulus code here

    wait;
  end process;


end;
  