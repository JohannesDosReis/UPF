#include <stdio.h>
#include <conio.h>

int main(void)
{
    int N1;
    char L1;
    char L2;
    char L3;
    int N2;
    int N3;

    int *p1;
    int *p2;
    int **pp1;

    // operadores com vetor:
    // & --> obtem o valor do endereço a partir da variavel (referenciar)
    // * --> obtem o valor da variavel a partir do endereço (dereferenciar)
    // * --> utilizado para declarar variavel como ponteiro

    printf("As variaveis estao na memoria:\n");
    printf(" N1: %10d %08X\n", &N1, &N1);
    printf(" L1: %10d %08X\n", &L1, &L1);
    printf(" N2: %10d %08X\n", &N2, &N2);
    printf(" N3: %10d %08X\n", &N3, &N3);
    printf(" L2: %10d %08X\n", &L2, &L2);
    printf(" L3: %10d %08X\n\n", &L3, &L3);

    p1 = &N1;
    p2 = &N2;

    N1 = 30;    // variavel N1 recebe 30
    *p2 = 10;   // variavel para onde P2 diz estar, recebe o valor 10;

    pp1 = &p1;  // endereço do endereço;

    printf("N1 = %d e N2 = %d\n", N1, N2);
    printf("*P1= %d e *P2= %d\n", *p1, *p2);
    printf("P1 = %d e P2 = %d\n", p1, p2);
    *pp1 = &N1;
    printf("*P1= %d e *P2= %d\n", *p1, *p2);
    printf("P1 = %d e P2 = %d\n", p1, p2);
    **pp1 = 90;
    printf("*P1= %d e N1= %d\n", *p1, N1);

    return(0);
}
