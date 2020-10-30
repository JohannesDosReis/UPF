#include <16f887.h>
#include <regs_887.h>
#use delay (clock=4MHz)
#fuses INTRC_IO

void main(void)
   {
   TRISD=0;      //PORTD como saida
   TRISB=0xFF;   //Todos os pinos da PORTB como entrada
   PORTD=0;
   INTEDG=1;     // borda de subida para RB0/INT
   INTE=RBIE=1;
   GIE=1;
   RBPU=0;      //pull-up global da PORTB habilitado
   WPUB=0xFF;   //pull-ups individuais da PORTB habilitados
   IOCB=0xFE;   //RB7 a RB1 hab. p/ int. mudança de estado
   while(true);
   }

#INT_EXT
void interrupt_ext(void)
   {
   PORTD=0x01;
   delay_ms(2000);
   PORTD=0;
   INTF=0;
   }

#INT_RB
void interrupt_rb(void)
   {
   if (RB7==1) PORTD=0x80;
   else if (RB6==1) PORTD=0x40;
   else if (RB5==1) PORTD=0x20;
   else if (RB4==1) PORTD=0x10;
   else if (RB3==1) PORTD=0x08;
   else if (RB2==1) PORTD=0x04;
   else if (RB1==1) PORTD=0x02;
   delay_ms(1000);   
   PORTD=0;
   RBIF=0;
   }
