#include <16f887.h>

#include "../include/regs_887.h"

#use delay(clock = 4MHz)
#include "../include/display_4bits.h"
#fuses INTRC_IO

void main(void) {
  char texto[21];
  int count = 0;
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
    if (RD0 == 0) {

      strcpy(texto, "CONT. PROGRESSIVO");
      escreve(0x80, texto);
      strcpy(texto, "                    ");
      escreve(0xC0, texto);
      strcpy(texto, "                    ");
      escreve(0x94, texto);

      for (count = 0; count < 100 && RD2; count++) {
        if (count == 100)
          count = 0;
        sprintf(texto, "%02d", count);
        escreve(0x9D, texto);
        delay_ms(1000);
      }
    } else if (RD1 == 0) {

      strcpy(texto, "CONT. REGRESSIVO");
      escreve(0x80, texto);
      strcpy(texto, "                    ");
      escreve(0xC0, texto);
      strcpy(texto, "                    ");
      escreve(0x94, texto);

      for (count = 99; count >= 0 && RD2; count--) {
        sprintf(texto, "%02d", count);
        escreve(0x9D, texto);
        delay_ms(1000);
        if (count == 0)
          count = 100;
      }
    }
  }
}
