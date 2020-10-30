#include <stdio.h>      // standard input/output -> Entrada e saida padrao

// printf -> saida formatada
// scanf --> entrada formatada

int main(void)
{
    unsigned char N8;   // 8 bits, sem sinal
    short N16;          // 16 bits
    int N32;            // 32 bits

    printf("Digite um numero de 0 a 255: ");
    scanf("%u", &N8);
    printf("\nVoce digitou %d (%u) para N8.\n\n", N8, N8);

    char L1;
    int D, M, A;
    int n;

    printf("Digite uma letra: ");
    scanf("\n%c", &L1);
    printf("\nVoce digitou a letra %c (%u).\n\n", L1, L1);

    printf("Digite a data de hoje, no formato dd/mm/aaaa: ");
    n = scanf("%u/%u/%u", &D, &M, &A);
    if(n == 3) printf("Hoje eh: %02u/%02u/%02u\n\n", D, M, A%100);
    else printf("Data incorreta! Apenas %d valores foram lidos!", n);
}

