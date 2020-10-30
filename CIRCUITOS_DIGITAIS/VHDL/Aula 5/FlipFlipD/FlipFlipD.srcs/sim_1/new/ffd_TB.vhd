library IEEE;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity ffd_tb is
end;

architecture bench of ffd_tb is

  component ffd
      Port ( D, clock : in STD_LOGIC;
             Q : out STD_LOGIC);
  end component;

  signal D, clock: STD_LOGIC;
  signal Q: STD_LOGIC;

  constant clock_period: time := 10 ns;
  signal stop_the_clock: boolean;

begin

  uut: ffd port map ( D     => D,
                      clock => clock,
                      Q     => Q );

  stimulus: process
  begin
  
    -- Put initialisation code here
    D <= '0';
    wait for 10ns;
    D <= '1';
    wait for 10ns;
    D <= '0';
    wait for 10ns;
    -- Put test bench stimulus code here

    stop_the_clock <= true;
    wait;
  end process;

  clocking: process
  begin
    while not stop_the_clock loop
      clock <= '0', '1' after clock_period / 2;
      wait for clock_period;
    end loop;
    wait;
  end process;

end;