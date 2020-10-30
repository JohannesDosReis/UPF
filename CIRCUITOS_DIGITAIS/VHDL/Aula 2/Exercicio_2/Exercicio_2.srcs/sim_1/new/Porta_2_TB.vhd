library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity Porta_2_tb is
end;

architecture bench of Porta_2_tb is

  component Porta_2
      Port ( A,B,C,D : in STD_LOGIC;
             S : out STD_LOGIC);
  end component;

  -- signal A,B,C,D: STD_LOGIC;
  signal tab: std_logic_vector(0 to 3);
  signal S: STD_LOGIC;

begin

  uut: Porta_2 port map ( A => tab(0),
                          B => tab(1),
                          C => tab(2),
                          D => tab(3),
                          S => S );

  stimulus: process
  begin
  
  tab <= "0000";
  wait for 10ns;
    -- Put initialisation code here
  for i in 0 to 15 loop
    tab <= std_logic_vector(unsigned(tab) + 1);
    wait for 10ns;
  
  end loop;
    
--A <= '0'; B <= '0'; C <= '0'; D <= '0';
--    wait for 10 ns;
--    A <= '0'; B <= '0'; C <= '0'; D <= '1';
--    wait for 10 ns;
--    A <= '0'; B <= '0'; C <= '1'; D <= '0';
--    wait for 10 ns;
--    A <= '0'; B <= '0'; C <= '1'; D <= '1';
--    wait for 10 ns;
--    A <= '0'; B <= '1'; C <= '0'; D <= '0';
--    wait for 10 ns;
--    A <= '0'; B <= '1'; C <= '0'; D <= '1';
--    wait for 10 ns;
--    A <= '0'; B <= '1'; C <= '1'; D <= '0';
--    wait for 10 ns;
--    A <= '0'; B <= '1'; C <= '1'; D <= '1';
--    wait for 10 ns;
--    A <= '1'; B <= '0'; C <= '0'; D <= '0';
--    wait for 10 ns;
--    A <= '1'; B <= '0'; C <= '0'; D <= '1';
--    wait for 10 ns;
--    A <= '1'; B <= '0'; C <= '1'; D <= '0';
--    wait for 10 ns;
--    A <= '1'; B <= '0'; C <= '1'; D <= '1';
--    wait for 10 ns;
--    A <= '1'; B <= '1'; C <= '0'; D <= '0';
--    wait for 10 ns;
--    A <= '1'; B <= '1'; C <= '0'; D <= '1';
--    wait for 10 ns;
--    A <= '1'; B <= '1'; C <= '1'; D <= '0';
--    wait for 10 ns;
--    A <= '1'; B <= '1'; C <= '1'; D <= '1';
--    wait for 10 ns;
    
--    A <= '0'; B <= '0'; C <= '0'; D <= '0';
--    wait for 10 ns;
    -- Put test bench stimulus code here

    wait;
  end process;


end;