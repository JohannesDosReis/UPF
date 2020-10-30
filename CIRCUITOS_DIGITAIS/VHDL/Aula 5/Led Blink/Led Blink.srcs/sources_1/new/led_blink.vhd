----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.11.2018 15:08:05
-- Design Name: 
-- Module Name: blink - blink
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

entity blink is
    Port ( CLK100MHZ : in STD_LOGIC;
           led : out STD_LOGIC_VECTOR(0 to 2));
end blink;

architecture blink of blink is
    signal count: integer := 0;
begin

    process (CLK100MHZ)
    begin
        if (CLK100MHZ'event and CLK100MHZ = '1') then
            count <= count + 1;
            if (count < 50e6) then 
                led <= "000";
            else
                led <= "111";
            end if;
            if (count > 100e6) then
                count <= 0;
            end if;
        end if;
    end process;

end blink;
