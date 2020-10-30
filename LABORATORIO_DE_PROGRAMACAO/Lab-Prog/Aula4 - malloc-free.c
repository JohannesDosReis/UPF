#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ReadSize(void);

/*
 * main
 */
int main(void)
{
    int i;
    int Sz;

    int Vet[10];
    int *Dyn;

    srand(clock());

    // obtem a quantidade
    Sz = ReadSize();

    // cria o vetor dinamicamente, em bytes!
    //Dyn = malloc(Sz*sizeof(int));  // tipo especifico int
    Dyn = malloc(Sz*sizeof(*Dyn));  // acompanha o tipo

    // elementos aleatorios de 0 a 99
    for(i = 0; i < Sz; i++) Dyn[i] = rand()%100;

    // escreve na tela
    for(i = 0; i < Sz; i++) printf(" %02d ", Dyn[i]);
    putchar('\n');

    // libera o vetor criado
    free(Dyn);

    return(0);
}

/*
 * Faz a leitura da quantidade
 */
int ReadSize(void)
{
    int N;

    printf("Escolha quantos elementos tera o vetor: ");
    scanf("%d", &N);

    while(N < 1)
    {
        printf("Quantidade deve ser pelo menos 1!\n");
        printf("Escolha outra: ");
        scanf("%d", &N);
    }

    return(N);
}
