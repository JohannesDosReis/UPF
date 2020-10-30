#include <16f887.h>

#include "../include/regs_887.h"

// RC interno com f=4MHZ (default) e libera RA6 e RA7 como pinos de E/S
#fuses INTRC_IO
#use delay(clock = 4MHZ)

// int millis(){

// }

void main(void) {
  TRISC = 0x80;
  TRISE = 9;

  int j, i = 0, inc, dez, uni;
  // numbers[] = {0x00, 0x06, 0x5B, 0x4F, 0x26, 0x6C, 0x7C, 0x07, 0x7F, 0x67};
  int numbers[] = {0b0111111,  0b00000110, 0b01011011, 0b01001111, 0b01100110,
                   0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};

  while (true) {
    dez = i / 10;
    uni = i % 10;

    j = 0;
    while (j < 50) {
      PORTC = numbers[dez];
      RE1 = 0;
      delay_ms(10);
      RE1 = 1;

      PORTC = numbers[uni];
      RE2 = 0;
      delay_ms(10);
      RE2 = 1;
      j++;
    }

    inc = (RC7) ? 1 : -1;
    i += inc;

    if (i == 100 && inc == 1) {
      i = 0;
    } else if (i == -1 && inc == -1) {
      i = 99;
    }
  }
}
