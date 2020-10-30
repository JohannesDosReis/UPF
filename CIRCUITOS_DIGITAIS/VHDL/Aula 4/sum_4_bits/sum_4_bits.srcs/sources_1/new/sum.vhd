----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.11.2018 14:31:31
-- Design Name: 
-- Module Name: sum - Behavioral
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

entity sum is
    Port ( A : in STD_LOGIC_VECTOR (3 downto 0);
           B : in STD_LOGIC_VECTOR (3 downto 0);
           cout: out STD_LOGIC;
           S : inout STD_LOGIC_VECTOR (3 downto 0);
           ck_io : out STD_LOGIC_VECTOR (0 to 13));
end sum;

architecture Behavioral of sum is

    signal c1, c2, c3 : STD_LOGIC;

begin
    
    S(0) <= (A(0) xor B(0)) xor '0';
    c1 <= (A(0) and B(0)) or ((A(0) xor B(0))and '0');
    
    S(1) <= (A(1) xor B(1)) xor c1;
    c2 <= (A(1) and B(1)) or ((A(1) xor B(1)) and c1);
    
    S(2) <= (A(2) xor B(2)) xor c2;
    c3 <= (A(2) and B(2)) or ((A(2) xor B(2)) and c2);

    S(3) <= (A(3) xor B(3)) xor c3;
    cout <= (A(3) and B(3)) or ((A(3) xor B(3)) and c3);
    
                --   abcdefg
        ck_io <=    "11111100000001" when S = "0000" else
                    "01100000000001" when S = "0001" else
                    "11011010000001" when S = "0010" else
                    "11110010000001" when S = "0011" else
                    "01100110000001" when S = "0100" else
                    "10110110000001" when S = "0101" else
                    "10111110000001" when S = "0110" else
                    "11100000000001" when S = "0111" else
                    "11111110000001" when S = "1000" else
                    "11110110000001" when S = "1001" else
                    "11111101001111" when S = "1010" else
                    "01100001001111" when S = "1011" else 
                    "11011011001111" when S = "1100" else 
                    "11110011001111" when S = "1101" else
                    "01100111001111" when S = "1110" else
                    "10110111001111" when S = "1111";
    
end Behavioral;  