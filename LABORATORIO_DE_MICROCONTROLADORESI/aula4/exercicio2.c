/*
2. Melhore o exercício 1, acrescentando a funcionalidade do contador ser
crescente ou decrescente de acordo com as interrupções por mudança de estado no
pino RB1 (0→1 – crescente e 1→0 decrescente). Também, utilize qualquer mudança
de estado no pino RB2 para zerar o contador.
*/

#include <16f887.h>

#include "../include/regs_887.h"
#fuses INTRC_IO // diretiva para usar oscilador interno + adi��o 2 pinos IO
#use delay(clock = 4MHz)

// Esta fun��o � associada a interrup��o externa
void externa(void);

void main(void) {
  TRISC = 0x00;
  PORTC = 0x00;
  INTCON = 0x90;
  INTEDG = 0;
  while (true) {
    PORTC &= (~RB2 * 0x0F);
  }
}

#INT_EXT
void externa(void) {
  if (RB1 == 0 && PORTC == 9)
    PORTC = 0;
  else if (RB1 == 1 && PORTC == 0)
    PORTC = 9;
  else
    PORTC -= (RB1 << 1) - 1;
  INTF = 0;
}
