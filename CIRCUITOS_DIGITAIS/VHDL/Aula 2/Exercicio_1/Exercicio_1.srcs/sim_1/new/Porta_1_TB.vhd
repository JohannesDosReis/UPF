
library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity Porta_1_tb is
end;

architecture bench of Porta_1_tb is

  component Porta_1
      Port ( A : in STD_LOGIC;
             B : in STD_LOGIC;
             C : in STD_LOGIC;
             S : out STD_LOGIC);
  end component;

  signal A: STD_LOGIC;
  signal B: STD_LOGIC;
  signal C: STD_LOGIC;
  signal S: STD_LOGIC;

begin

  uut: Porta_1 port map ( A => A,
                          B => B,
                          C => C,
                          S => S );

  stimulus: process
  begin
  
    -- Put initialisation code here

    A <= '0'; B <= '0'; C <= '0';
    wait for 10ns;
    A <= '0'; B <= '0'; C <= '1';
    wait for 10ns;
    A <= '0'; B <= '1'; C <= '0';
    wait for 10ns;
    A <= '0'; B <= '1'; C <= '1';
    wait for 10ns;
    A <= '1'; B <= '0'; C <= '0';
    wait for 10ns;
    A <= '1'; B <= '0'; C <= '1';
    wait for 10ns;
    A <= '1'; B <= '1'; C <= '0';
    wait for 10ns;
    A <= '1'; B <= '1'; C <= '1';
    wait for 10ns;
    
    A <= '0'; B <= '0'; C <= '0';
    wait for 10ns;
    
    -- Put test bench stimulus code here

    wait;
  end process;


end;