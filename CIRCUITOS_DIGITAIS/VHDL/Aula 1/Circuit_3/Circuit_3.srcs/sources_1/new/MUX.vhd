----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05.11.2018 15:17:52
-- Design Name: 
-- Module Name: MUX - Behavioral
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

entity MUX is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           I0 : in STD_LOGIC;
           I1 : in STD_LOGIC;
           I2 : in STD_LOGIC;
           I3 : in STD_LOGIC;
           O : out STD_LOGIC);
end MUX;

architecture Behavioral of MUX is

begin

    O <= (I0 and (not A and not B)) 
    or (I1 and (not A and B)) 
    or (I2 and (A and not B)) 
    or (I3 and (A and B));

end Behavioral;
