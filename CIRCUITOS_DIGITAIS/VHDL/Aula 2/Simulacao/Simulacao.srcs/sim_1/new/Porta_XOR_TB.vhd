library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity Porta_XOR_tb is
end;

architecture bench of Porta_XOR_tb is

  component Porta_XOR
      Port ( A,B : in STD_LOGIC;
             S : out STD_LOGIC);
  end component;

  signal A,B: STD_LOGIC;
  signal S: STD_LOGIC;

begin

  uut: Porta_XOR port map ( A => A,
                            B => B,
                            S => S );

  stimulus: process
  begin
  
    -- Put initialisation code here
    A <= '0'; B <= '0';
    wait for 10ns;
    
    A <= '0'; B <= '1';
    wait for 10ns;
    
    A <= '1'; B <= '0';
    wait for 10ns;
    
    A <= '1'; B <= '1';
    wait for 10ns;
    
    A <= '0'; B <= '0';
    wait for 10ns;

    -- Put test bench stimulus code here

    wait;
  end process;


end;