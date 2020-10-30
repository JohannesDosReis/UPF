----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21.11.2018 14:25:36
-- Design Name: 
-- Module Name: alarme_carro - Behavioral
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

entity alarme_carro is
    Port ( controle, sensores, rst, clk, CLK100MHZ: in STD_LOGIC;
           sirene: out STD_LOGIC;
           led_estado: out STD_LOGIC_VECTOR (0 to 2));
end alarme_carro;
-- led disarmdado - verde
-- led armado - azul
-- led intruso - vermelho


architecture Behavioral of alarme_carro is

type estados_alarme is (disarmado, armado, intruso);
signal estado_anterior, proximo_estado: estados_alarme;
signal count : integer := 0;

begin
    
    process (CLK100MHZ, estado_anterior)
    begin
        if (estado_anterior = intruso) then
            if (CLK100MHZ'event and CLK100MHZ = '1') then
                count <= count + 1;
            end if;
        else
            count <= 0;
        end if;
    end process;
    
    
    
    process (estado_anterior) 
    begin
        if (estado_anterior = disarmado) then
            led_estado <= "010";
        elsif (estado_anterior = armado) then
            led_estado <= "100";
        elsif (estado_anterior = intruso) then
            led_estado <= "001";
        end if;
    end process;
    
    
    process (clk, rst, count)
    begin
        if (count > 500e6) then
            estado_anterior <= armado;
        elsif (rst='1') then
            estado_anterior <= disarmado;
        elsif (clk'event and clk='1') then
            estado_anterior <= proximo_estado; 
        end if;
    end process;
    
    
    
    process (estado_anterior, controle, sensores)
    begin
        case estado_anterior is
            when disarmado => sirene <= '0';
                if (controle = '1' ) then
                    proximo_estado <= armado;
                else
                    proximo_estado <= disarmado;
                end if;
            
            when armado => sirene <= '0';
                if (sensores = '1') then
                    proximo_estado <= intruso;
                elsif (controle = '1') then
                    proximo_estado <= disarmado;
                else
                    proximo_estado <= armado;
                end if;
                
            when intruso => sirene <= '1';
                if (controle = '1') then
                    proximo_estado <= disarmado;
                else
                    proximo_estado <= intruso;
                end if;
                    
        end case;
    end process;
    
end Behavioral;
