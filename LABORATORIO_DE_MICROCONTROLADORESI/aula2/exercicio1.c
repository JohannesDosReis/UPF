#include <16f887.h>

#include "../include/regs_887.h"

// RC interno com f=4MHZ (default) e libera RA6 e RA7 como pinos de E/S
#fuses INTRC_IO
#use delay(clock = 4MHZ)

void main(void) {
  int inc;
  //   Define todos os pinos como saida
  TRISA = 0;
  TRISB = 0;
  TRISC = 0;
  TRISD = 0;
  //   RE é smere entrada
  TRISE = 15;
  PORTA = 255;
  PORTB = 0b10101010;
  PORTC = 1;
  PORTD = 0x0F;

  while (true) {
    delay_ms(500);
    inc = (RE0) ? 1 : -1;

    if (!RE2)
      PORTA = 0;
    else if (!RE1)
      PORTA = 255;
    else
      PORTA += inc;

    PORTB = ~PORTB;
    PORTC <<= 1;
    if (PORTC == 0)
      PORTC = 1;
    PORTD = ~PORTD;
  }
}
