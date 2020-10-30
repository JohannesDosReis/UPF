#include <16f887.h>

#include "../include/regs_887.h"

#use delay(clock = 4MHz)
#include "../include/display.h"
#fuses INTRC_IO
void main(void) {
    int count = 0;
    char texto[17];
    TRISC = 0;
    TRISE = 0;
    inicializa();
    while (TRUE) {
        for (count = 0; count < 100; count++) {
            sprintf(texto, "%02d", count);
            escreve(0xDE, texto);
            delay_ms(1000);
        }
    }
}