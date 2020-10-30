library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity sum_tb is
end;

architecture bench of sum_tb is

  component sum
      Port ( A : in STD_LOGIC;
             B : in STD_LOGIC;
             cin : in STD_LOGIC;
             cout : out STD_LOGIC;
             S : out STD_LOGIC);
  end component;

  signal A: STD_LOGIC;
  signal B: STD_LOGIC;
  signal cin: STD_LOGIC;
  signal cout: STD_LOGIC;
  signal S: STD_LOGIC;

begin

  uut: sum port map ( A    => A,
                      B    => B,
                      cin  => cin,
                      cout => cout,
                      S    => S );

  stimulus: process
  begin
  
    -- Put initialisation code here

    cin <= '0'; A <= '0'; B <= '0';
    wait for 10ns;
    cin <= '0'; A <= '0'; B <= '1';
    wait for 10ns; 
    cin <= '0'; A <= '1'; B <= '0';
    wait for 10ns; 
    cin <= '0'; A <= '1'; B <= '1';
    wait for 10ns; 
    cin <= '1'; A <= '0'; B <= '0';
    wait for 10ns; 
    cin <= '1'; A <= '0'; B <= '1';
    wait for 10ns; 
    cin <= '1'; A <= '1'; B <= '0';
    wait for 10ns; 
    cin <= '1'; A <= '1'; B <= '1'; 
    wait for 10ns; 
    
    -- Put test bench stimulus code here

    wait;
  end process;


end;