#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Aula8 - preprocess-radio.h"

#if RADIO_ESP8266
    #include <drivers/esp_8266.h>
#endif // RADIO_ESP8266

#if RADIO_L2408
    #include <lib/spi.h>
    #include <drivers/L2408.h>
#endif // RADIO_L2408

#if RADIO_LITHIUM
    #include <lib/i2c.h>
    #include <drivers/lithium.h>
    #include <drivers/lithium_cmd.h>
#endif // RADIO_LITHIUM


#if !(RADIO_ESP8266 || RADIO_L2408 || RADIO_LITHIUM)
    #error "Ative algum modulo de radio para compilar!!!"
#endif

/*
 * Transmite os dados via radio
 */
int TxData(char *pDados, int Tam)
{
   char Crc;

   // verificacao de erros
   Crc = CalculaCrc(pDados, Tam);

    #if RADIO_ESP8266
        EspSend(pDados, Tam);

        EspSend(&Crc, 1);
    #endif // RADIO_ESP8266

    #if RADIO_L2408
        L2408_tx(pDados, Tam, Crc);
    #endif // RADIO_L2408

    #if RADIO_LITHIUM
        i2c_begin();
        i2c_wait_bus();
        while(Tam)
        {
            lithium_write(*pDados);
            pDados++;
            Tam--;
        }

        lithium_write(Crc);

        lithium_tx();

        i2c_clear();
    #endif // RADIO_LITHIUM
}


/*
 * main
 */
int main(void)
{


    return(0);
}
