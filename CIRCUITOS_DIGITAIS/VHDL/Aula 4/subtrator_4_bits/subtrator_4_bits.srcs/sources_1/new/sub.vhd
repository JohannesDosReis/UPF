----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.11.2018 16:40:30
-- Design Name: 
-- Module Name: sub - Behavioral
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

entity sub is
    Port ( A : in STD_LOGIC_VECTOR (3 downto 0);
           B : in STD_LOGIC_VECTOR (3 downto 0);
           cout: out STD_LOGIC;
           S : out STD_LOGIC_VECTOR (3 downto 0));
end sub;

architecture Behavioral of sub is

    signal c1, c2, c3 : STD_LOGIC;

begin
    
S(0) <= (A(0) xor B(0)) xor '0';
  c1 <= (not A(0) and B(0)) or (not(A(0) xor B(0))and '0');
  
  S(1) <= (A(1) xor B(1)) xor c1;
  c2 <= (not A(1) and B(1)) or (not(A(1) xor B(1)) and c1);
  
  S(2) <= (A(2) xor B(2)) xor c2;
  c3 <= (not A(2) and B(2)) or (not(A(2) xor B(2)) and c2);

  S(3) <= (A(3) xor B(3)) xor c3;
  cout <= (not A(3) and B(3)) or (not(A(3) xor B(3)) and c3);



end Behavioral;
