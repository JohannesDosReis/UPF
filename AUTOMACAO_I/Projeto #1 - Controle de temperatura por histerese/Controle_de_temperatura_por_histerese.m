## Copyright (C) 2020 johannes
## 
## This program is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see
## <https://www.gnu.org/licenses/>.


## Requeriments
# pkg install -forge arduino

## -*- texinfo -*- 
## @deftypefn {} Controle_de_temperatura_por_histerese ()
##
## @seealso{}
## @end deftypefn

## Author: johannes <johannes@JOHANNES-LAPTOP>
## Created: 2020-09-15

function Controle_de_temperatura_por_histerese ()
    clear;
    pkg load arduino;
    # arduinosetup('libraries', 'examplelcd/lcd');
    a = arduino();
    lcd = addon(a, "examplelcd/lcd", "d8", "d9", "d4", "d5", "d6", "d7");
    setPoint = 30.0;
    hysteresisOn = 3.0;
    hysteresisOff = 3.0;
    driver = true;
    screen = 0
    tempSetPoint = 30;
    tempHysteresisOn = 3;
    tempHysteresisOff = 3;
    powerOff = false;
    tempDriver = false;

    while (1)
        # Read Temperature
        temperature = double(readAnalogPin(a, "a0")) * 5.0 * 100.0 / 1023.0;
      
        clearLCD(lcd);
        if (screen == 0)
            # Print 1 screen
            printLCD(lcd, "SP: ");
            printLCD(lcd, num2str(temperature, "%.1f"));
            printLCD(lcd, " C   DRV");
            gotoLCD(lcd, 0, 1);
            printLCD(lcd, "PV: ");
            printLCD(lcd, num2str(setPoint, "%.1f"));
            printLCD(lcd, " C   ");
            if (driver == true)
                printLCD(lcd, "ON");
            else
                printLCD(lcd, "OFF");
            endif

        elseif (screen == 1)
            # Print 2 screen
            printLCD(lcd, "Configurar");
            gotoLCD(lcd, 0, 1);
            printLCD(lcd, "Set-Point: ");
            printLCD(lcd, num2str(tempSetPoint, "%.1f"));
            printLCD(lcd, " C");

        elseif (screen == 2)
            # Print 3 screen
            printLCD(lcd, "Configurar");
            gotoLCD(lcd, 0, 1);
            printLCD(lcd, "HisterON: ");
            printLCD(lcd, num2str(tempHysteresisOn, "%.1f"));
            printLCD(lcd, " C");

        elseif (screen == 3)
            # Print 4 screen
            clearLCD(lcd);
            printLCD(lcd, "Configurar");
            gotoLCD(lcd, 0, 1);
            printLCD(lcd, "HisterOFF: ");
            printLCD(lcd, num2str(tempHysteresisOff, "%.1f"));
            printLCD(lcd, " C");

        elseif (screen == 4)
            # Print 5 screen
            clearLCD(lcd);
            printLCD(lcd, "PowerOff");
            gotoLCD(lcd, 0, 1);
            printLCD(lcd, "Confirmar?");

        endif

        # Faz a leitura dos botões
        buttonP = readDigitalPin (a,  "d10");
        buttonPlus = readDigitalPin (a,  "d11");
        buttonMinus = readDigitalPin (a,  "d12");
        buttonS = readDigitalPin (a,  "d13");

        # Tela 0
        if (screen == 0)
            # Troca de tela
            if (buttonP == 0) 
                screen++;
            endif

        # Tela 1
        elseif (screen == 1)
            
            # Troca de tela
            if (buttonP == 0) 
                screen++;
                # set temVariable igual original
                tempSetPoint = setPoint;
                tempDriver = driver;
            
            # Botão mais
            elseif (buttonPlus == 0)
                # Aumenta o set-point
                tempSetPoint++;
                #Liga o driver
                tempDriver = true;

            # Botão menos
            elseif (buttonMinus == 0 && tempSetPoint > 0)
                # Diminui o set-point
                tempSetPoint--;
                # Desliga o driver
                tempDriver = false;

            # Salva alterações 
            elseif (buttonS == 0)
                setPoint = tempSetPoint;
                driver = tempDriver;

            endif

        #Tela 2
        elseif (screen == 2)
            # Troca de tela
            if (buttonP == 0)
                screen++;
                # set temVariable igual original
                tempHysteresisOn = hysteresisOn;

            # Botão mais
            elseif (buttonPlus == 0)
                # Aumenta histerese para ligar
                tempHysteresisOn++;
            
            elseif (buttonMinus == 0 && tempHysteresisOn > 0)
                # Diminui histerese para ligar se maior de 0
                tempHysteresisOn--;

            # Salva alterações 
            elseif (buttonS == 0)
                hysteresisOn = tempHysteresisOn;
            endif

        
        # Tela 3
        elseif (screen == 3)
            # Troca de tela
            if (buttonP == 0) 
                screen++;
                # set temVariable igual original
                tempHysteresisOff = hysteresisOff;

            # Botão mais
            elseif (buttonPlus == 0)
                # Aumenta histerese para desligar
                tempHysteresisOff++;

            # Botão menos
            elseif (buttonMinus == 0 && tempHysteresisOff > 0)
                # Diminui histerese para desligar se maior de 0
                tempHysteresisOff--;

            # Salva alterações   
            elseif (buttonS == 0)
                hysteresisOff = tempHysteresisOff;
            endif

        # Tela 4
        elseif (screen == 4)
            # Troca de tela
            if (buttonP == 0) 
                screen = 0;

            # Confirmar desligar
            elseif (buttonS == 0)
                driver = false;
                powerOff = true;
            endif
        endif


        if (powerOff == false)
            # Control the driver
            if (temperature <= setPoint - hysteresisOn)
                driver = true;
                writeDigitalPin(a, "d2", driver);
            elseif (temperature >= setPoint + hysteresisOff)
                driver = false;
                writeDigitalPin(a, "d2", driver);
            endif;
        endif;

        pause(0.3);
    endwhile
endfunction
