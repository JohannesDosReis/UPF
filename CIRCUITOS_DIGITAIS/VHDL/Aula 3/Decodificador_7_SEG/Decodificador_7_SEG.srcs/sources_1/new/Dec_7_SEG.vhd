----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 12.11.2018 14:12:22
-- Design Name: 
-- Module Name: Dec_7_SEG - Behavioral
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

entity Dec_7_SEG is
    Port ( sw : in STD_LOGIC_VECTOR (3 downto 0);
           btn: in STD_LOGIC;
           ck_io : out STD_LOGIC_VECTOR (0 to 6));
end Dec_7_SEG;

architecture Behavioral of Dec_7_SEG is

begin
--               abcdefg
    ck_io <=    "1111111" when btn = '1' else
                "1111110" when sw = "0000" else
                "0110000" when sw = "0001" else
                "1101101" when sw = "0010" else
                "1111001" when sw = "0011" else
                "0110011" when sw = "0100" else
                "1011011" when sw = "0101" else
                "1011111" when sw = "0110" else
                "1110000" when sw = "0111" else
                "1111111" when sw = "1000" else
                "1111011" when sw = "1001" else
                "1110111" when sw = "1010" else
                "0011111" when sw = "1011" else
                "1001110" when sw = "1100" else
                "0111101" when sw = "1101" else
                "1001111" when sw = "1110" else
                "1000111" when sw = "1111" else
                "0000000";
end Behavioral;
