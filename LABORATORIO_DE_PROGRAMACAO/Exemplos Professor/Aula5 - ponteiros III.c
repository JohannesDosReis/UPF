#include <stdio.h>
#include <conio.h>

// vetor como ponteiro para ser modificado
void Criavetor(int *pVetor, int Tam)
{
    int i;

    for(i = 0; i < Tam; i++)
    {
        // cada elemento recebe o valor da sua posicao*2
        // 0 2 4 6 8 10 ....
        pVetor[i] = 2*i;
    }
}

// vetor como ponteiro, de forma implicita
void InverteVetor(int pVetor[], int Tam)
{
    int Temp;
    int *pFim;

    // ultimo elemento
    pFim = pVetor + Tam - 1;

    do
    {
        // faz a troca dos dois elementos
        Temp = *pVetor;
        *pVetor = *pFim;
        *pFim = Temp;

        pVetor++;   // proximo a partir do inicio
        pFim--;     // previo a partir do ultimo
    }while(pVetor < pFim);

}

void MostraVetor(int *pVetor, int Tam)
{
    printf("Vet[] = ");
    while(Tam)
    {
        // escreve o elemento atual na tela
        printf("%d ", *pVetor); // idem a pVetor[0]

        // proximo
        Tam--;      // um elemento a menos
        pVetor++;   // uma posição adiante
    }
    putchar('\n');
}

// define se vamos alocar dinamicamente (1) ou estaticamente (0)
#define DYNAMIC     1

int main(void)
{
    const int TAM = 11;

    #if DYNAMIC
        int *Vetor;
        Vetor = malloc(TAM*sizeof(*Vetor));
    #else
        int Vetor[TAM];
    #endif // DYNAMIC

    // cria o vetor aleatorio
    Criavetor(Vetor, TAM);
    MostraVetor(Vetor, TAM);
    InverteVetor(Vetor, TAM);
    MostraVetor(Vetor, TAM);

    #if DYNAMIC
        free(Vetor);
    #endif // DYNAMIC
    return(0);
}
