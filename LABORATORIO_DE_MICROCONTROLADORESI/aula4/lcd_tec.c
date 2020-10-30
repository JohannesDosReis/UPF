#include <16f887.h>

#include <../include/regs_887.h>
#use delay(clock = 4MHz)
#include "../include/teclado.h"

#include "../include/display.h"
#fuses INTRC_IO

void main(void) {
  char texto[17];
  TRISC = 0;
  TRISE = 0;
  TRISD = 0b11110000;
  PORTD = 0;
  inicializa();
  strcpy(texto, "LAB. MICRO 1");
  escreve(0x82, texto);
  strcpy(texto, "________________");
  escreve(0xC0, texto);
  strcpy(texto, "Testar o teclado");
  escreve(0x90, texto);
  strcpy(texto, "=>");
  escreve(0xD0, texto);
  while (true) {
    DADO = teclado() + 0x30;
    tempo();
  }
}
