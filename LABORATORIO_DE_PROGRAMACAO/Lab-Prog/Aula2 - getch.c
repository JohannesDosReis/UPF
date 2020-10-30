#include <stdio.h>      // standard input/output -> Entrada e saida padrao
#include <conio.h>

// printf -> saida formatada
// scanf --> entrada formatada

int main(void)
{
    unsigned char L1;
    unsigned char C;

    C = 0x00;

    printf("Digite uma letra: ");
    L1 = getch();
    if(L1 == 0xE0) { C = L1; L1 = getch(); }  // CMD key
    printf("%c (0x%02X) CMD= 0x%02X\n", L1, L1, C);


}
