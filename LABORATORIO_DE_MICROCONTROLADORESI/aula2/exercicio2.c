#include <16f887.h>

#include "../include/regs_887.h"

// RC interno com f=4MHZ (default) e libera RA6 e RA7 como pinos de E/S
#fuses INTRC_IO
#use delay(clock = 4MHZ)

void main(void) {
  //   Define todos os pinos como saida
  TRISC = 0;
  // int i = 0;
  // numbers[] = {0x00, 0x06, 0x5B, 0x4F, 0x26, 0x6C, 0x7C, 0x07, 0x7F, 0x67};
  int i,
      numbers[] = {0b0111111,  0b00000110, 0b01011011, 0b01001111, 0b01100110,
                   0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};

  while (true) {
    for (i = 0; i < 10; i++) {
      PORTC = numbers[i];
      delay_ms(1000);
    }

    // PORTC = numbers[i++];
    // if (i == 10)
    //   i = 0;

    // delay_ms(1000);
  }
}
