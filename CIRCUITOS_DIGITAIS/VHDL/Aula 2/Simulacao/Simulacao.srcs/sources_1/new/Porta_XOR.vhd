----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 07.11.2018 14:20:32
-- Design Name: 
-- Module Name: Porta_XOR - Arch_Porta_XOR
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

entity Porta_XOR is
    Port ( A,B : in STD_LOGIC;
           S : out STD_LOGIC);
end Porta_XOR;

architecture Arch_Porta_XOR of Porta_XOR is

begin

    S <= A xor B;

end Arch_Porta_XOR;
