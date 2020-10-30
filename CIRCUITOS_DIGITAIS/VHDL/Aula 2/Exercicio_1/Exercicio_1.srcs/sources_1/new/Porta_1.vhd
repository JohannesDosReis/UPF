----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 07.11.2018 14:41:43
-- Design Name: 
-- Module Name: Porta_1 - Behavioral
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

entity Porta_1 is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : in STD_LOGIC;
           S : out STD_LOGIC);
           -- O, O1 : out STD_LOGIC);
end Porta_1;

architecture Behavioral of Porta_1 is
    
    signal x1, x2: std_logic;
    
begin
    x1 <= (A and B);
    x1 <= (B nand C);
    S <= x1 xor x2;
    
    -- O1 <= (A and B) xor (B nand C);
    -- O <= (not((A and B) xor (B nand C)));

end Behavioral;
