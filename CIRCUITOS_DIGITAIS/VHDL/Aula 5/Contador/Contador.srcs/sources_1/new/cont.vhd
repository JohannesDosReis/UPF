----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.11.2018 14:35:39
-- Design Name: 
-- Module Name: cont - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity cont is
    Port ( cont : in STD_LOGIC;
          MAIS: out STD_LOGIC_VECTOR (0 to 6);
          MENOS: out STD_LOGIC_VECTOR (0 to 6));
end cont;

architecture Behavioral of cont is

begin

    process (cont)
    variable x:  natural range 0 to 99 := 0;
    
    begin
        if (cont'event and cont='1') then
            if (x = 99) then
                x := 0;
            else
                x := x + 1;
            end if;
        end if;
        if (x/10 = 0) then 
            MAIS <= "1111110";
        elsif (x/10 = 1) then 
            MAIS <= "0110000";
        elsif (x/10 = 2) then 
            MAIS <= "1101101";
        elsif (x/10 = 3) then 
            MAIS <= "1111001";
        elsif (x/10 = 4) then 
            MAIS <= "0110011";
        elsif (x/10 = 5) then 
            MAIS <= "1011011";
        elsif (x/10 = 6) then 
            MAIS <= "1011111";
        elsif (x/10 = 7) then 
            MAIS <= "1110000";
        elsif (x/10 = 8) then 
            MAIS <= "1111111";
        elsif (x/10 = 9) then 
            MAIS <= "1111011";
        end if;
        if (x mod 10 = 0) then 
            MENOS <= "0000001";
        elsif (x mod 10 = 1) then 
            MENOS <= "1001111";
        elsif (x mod 10 = 2) then 
            MENOS <= "0010010";
        elsif (x mod 10 = 3) then 
            MENOS <= "0000110";
        elsif (x mod 10 = 4) then 
            MENOS <= "1001100";
        elsif (x mod 10 = 5) then 
            MENOS <= "0100100";
        elsif (x mod 10 = 6) then 
            MENOS <= "0100000";
        elsif (x mod 10 = 7) then 
            MENOS <= "0001111";
        elsif (x mod 10 = 8) then 
            MENOS <= "0000000";
        elsif (x mod 10 = 9) then 
            MENOS <= "0000100";
        end if;
    end process;
end Behavioral;
