#include <16f887.h>

#include "regs_887.h"

#use delay(clock = 4MHz)
#include "display.h"
#fuses INTRC_IO

void main(void) {
  char texto[21];
  unsigned int count;
  TRISC = 0x0F;
  TRISE = 0;
  TRISD = 0xFF;
  inicializa();
  while (true) {
    strcpy(texto, "Menu <<CONTADOR>>");
    escreve(0x81, texto);
    strcpy(texto, "RD0->ProGress.(0-99)");
    escreve(0xC0, texto);
    strcpy(texto, "RD0->ReGress. (99-0)");
    escreve(0x94, texto);
    strcpy(texto, "RD2->Volta ao menu");
    escreve(0xD4, texto);
    while (RD0 && RD1 && RD2)
      ;
    if (RD0 == 0) {

      strcpy(texto, "CONT. PROGRESSIVO  ");
      escreve(0x80, texto);
      strcpy(texto, "                    ");
      escreve(0xC0, texto);
      strcpy(texto, "                    ");
      escreve(0x94, texto);
      count = 0;
      while (RD2) {
        sprintf(texto, "%02d", count);
        escreve(0x9D, texto);
        delay_ms(1000);
        count = (count == 99) ? 00 : count + 1;
      }

    } else if (RD1 == 0) {

      strcpy(texto, "CONT. REGRESSIVO  ");
      escreve(0x80, texto);
      strcpy(texto, "                    ");
      escreve(0xC0, texto);
      strcpy(texto, "                    ");
      escreve(0x94, texto);
      count = 99;
      while (RD2) {
        sprintf(texto, "%02d", count);
        escreve(0x9D, texto);
        delay_ms(1000);
        count = (count == 0) ? 99 : count - 1;
      }
    }
  }
}
