/*
3. Desenvolva um programa que, em laço infinito, monitore a ocorrência de
interrupção externa (RB0/INT) e interrupção por mudança de estado nos pinos RB1
a RB7, informando no display LCD qual delas ocorreu. Observe a montagem abaixo.
*/

#include <16f887.h>

#include "../include/regs_887.h"
#fuses INTRC_IO
#use delay(clock = 4MHz)
#INCLUDE "../include/display.h"
char texto[21];
void externa(void);

void main(void) {
  TRISE = 0x00;
  TRISC = 0x00;
  PORTC = 0x00;
  INTCON = 0x98;
  OPTION = 0x40;

  WPUB = 0xFF;
  IOCB = 0xFE;
  inicializa();
  strcpy(texto, "INTERRUPT");
  escreve(0x85, texto);
  while (TRUE) {
  }
}

#INT_EXT
void externa(void) {
  strcpy(texto, "Externa");
  escreve(0xC0, texto);
}

#INT_RB
void interrupt_rb(void) {
  static int1 flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0,
              flag7 = 0;
  int i;
  if (RB1 ^ flag1) {
    strcpy(texto, "RB1");
    escreve(0x90, texto);

  } else if (RB2 ^ flag2) {
    strcpy(texto, "RB2");
    escreve(0x96, texto);

  } else if (RB3 ^ flag3) {
    strcpy(texto, "RB3");
    escreve(0x9C, texto);

  } else if (RB4 ^ flag4) {
    strcpy(texto, "Externa");
    escreve(0xD0, texto);

  } else if (RB5 ^ flag5) {
    strcpy(texto, "Externa");
    escreve(0xC6, texto);

  } else if (RB6 ^ flag6) {
    strcpy(texto, "Externa");
    escreve(0xDC, texto);

  } else if (RB7 ^ flag7) {
    strcpy(texto, "Externa");
    escreve(0xC0, texto);
  }
}
