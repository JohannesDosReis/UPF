signed char teclado (void)
   {
   signed char tecla='x';
   while(tecla=='x')
      {
      RD3=0; RD1=1;
      if(RD4) {tecla = 1; delay_ms(250);}
      if(RD5) {tecla = 4; delay_ms(250);}
      if(RD6) {tecla = 7; delay_ms(250);}
      if(RD7) {tecla =-6; delay_ms(250);} //caracter *

      RD2 = 1; RD1 = 0;
      if(RD4) {tecla = 2; delay_ms(250);}
      if(RD5) {tecla = 5; delay_ms(250);}
      if(RD6) {tecla = 8; delay_ms(250);}
      if(RD7) {tecla = 0; delay_ms(250);}

      RD3 = 1; RD2 = 0;
      if(RD4) {tecla = 3; delay_ms(250);}
      if(RD5) {tecla = 6; delay_ms(250);}
      if(RD6) {tecla = 9; delay_ms(250);}
      if(RD7) {tecla =-13; delay_ms(250);} //caracter #
      }
   return tecla;
   }
