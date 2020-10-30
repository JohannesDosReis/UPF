#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Faz a contagem, sem utilizad while() ou for()
 */
void Contagem(int N)
{
    // escreve o N na tela
    printf("%d ", N);

    // se o N for maior que zero, faz a contagem pra N - 1 valores
    if(N > 0) Contagem(N - 1);
}

/*
 * main
 */
int main(void)
{
    int N;

    printf("Escolha um numero: ");
    scanf("%d", &N);

    Contagem(N);
    putchar('\n');

    return(0);
}
