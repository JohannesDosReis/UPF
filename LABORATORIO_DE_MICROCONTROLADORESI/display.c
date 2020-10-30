#include <16f887.h>
#include <regs_887.h>
#use delay (clock=4MHz)
#include <display.h>
#fuses INTRC_IO

void main(void)
   {
   char texto[17];
   TRISC=0;
   TRISE=0;
   inicializa();
   strcpy(texto,"  LAB. MICRO 1");
   escreve (0x80, texto);
   strcpy(texto,"________________");
   escreve (0xC0, texto);
   strcpy(texto,">>>>>>>>>>>>>>>>");
   escreve (0x90, texto);
   strcpy(texto,"   PIC 16F887");
   escreve (0xD0, texto);
   while(true);
  }
