----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.11.2018 14:06:01
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
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           cin : in STD_LOGIC;
           cout : out STD_LOGIC;
           S : out STD_LOGIC);
end sum;

architecture Behavioral of sum is

begin

    S <= (A xor B) xor cin;
    cout <= (A and B) or ((A xor B) and cin);
    

end Behavioral;
