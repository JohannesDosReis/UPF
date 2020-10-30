/*
1. Faça um programa que incremente um contador de década, visualizado em um
display BCD na PORTC, a cada vez que o microcontrolador perceber uma interrupção
externa (RB0/INT).
*/

#include <16f887.h>

#include "../include/regs_887.h"
#fuses INTRC_IO
#use delay(clock = 4MHz)

void externa(void);

void main(void) {
  TRISC = 0x00;
  PORTC = 0x00;
  INTCON = 0x90;
  INTEDG = 0;
  while (true) {
  }
}

#INT_EXT
void externa(void) {
  PORTC = (PORTC == 9) ? 0 : PORTC + 1;
  INTF = 0;
}
