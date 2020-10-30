#include <stdio.h>      // standard input/output -> Entrada e saida padrao

// printf -> saida formatada
// scanf --> entrada formatada

int main(void)
{
    unsigned int N1;
    int N2;
    long N3;

    float F1;
    double F2;

    char L1;
    char L2;

    // escrevendo na tela
    N1 = -1;    // sem sinal -1 dá o maior valor possivel!
    N2 = -1;    // com sinal
    N3 = 0xFFFFFFFF;
    printf("N1= %u N2= %d N3= %lu%%\n", N1, N2, N3);

    F1 = 10.333333333333333333333333333;
    F2 = 10.333333333333333333333333333;
    printf("F1= %2.3f F1= %3.4f F1= %04.2f\n", F1, F1, F1);
    printf("F2= %f F2= %2.30f\n", F2, F2);

    L1 = 'M';
    L2 = 65;
    printf("L1= %c L2= %c L1= %d\n", L1, L2, L1);
}

