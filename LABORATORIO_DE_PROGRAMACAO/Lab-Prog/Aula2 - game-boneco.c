#include <stdio.h>      // standard input/output -> Entrada e saida padrao
#include <conio.h>

// printf -> saida formatada
// scanf --> entrada formatada

int main(void)
{
    unsigned char L1;
    unsigned char C;
    int Pos = 1;

    printf("Brinque com o bonequinho:\nUtilize as teclas <- e ->\n\n");
    do
    {
        printf("\r");
        for(C = 0; C < Pos; C++) putchar(' ');
        printf("%c%c%c ", 192, 1, 217);
        C = 0x00;
        L1 = getch();
        if(L1 == 0xE0)
        {
            // command parameter
            L1 = getch();

            // LEFT
            if(L1 == 'K' && Pos > 1) { Pos--; }

            // RIGHT
            if(L1 == 'M' && Pos < 75) { Pos++; }
        }

        //printf("%c (0x%02X) CMD= 0x%02X\n", L1, L1, C);
    }while(L1 != 0x1B); // ESC

    printf("\033[%d;%dH%s\n", 60, 15, "-END-");

    putchar('\n');
    return(0);
}
