#include <16f887.h>

#include "../include/regs_887.h"

#fuses INTRC_IO
#use delay(clock = 4MHZ)

void main(void) {
  TRISA = 0b11111110; // RA0 como saída
  RA0 = 1;            // LED em RA3 inicia ligado
  while (true) {
    delay_ms(500);
    RA0 = ~RA0;
  }
}
