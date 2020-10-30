#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma pack(1)
typedef struct
{
    char Name[5];       // 5 bytes
    int Span;           // 4 bytes
    char Lights;        // 1 byte
    char Gears;         // 1 byte
    int Fuel;           // 4 bytes
}TAcft;

void DisplaySizes(TAcft *pAcft)
{
    printf("Estrutura completa: %d bytes\n", sizeof(TAcft));
    printf("Nome:   %d @%d\n", sizeof(pAcft->Name), (int)&pAcft->Name - (int)pAcft);
    printf("Span:   %d @%d\n", sizeof(pAcft->Span), (int)&pAcft->Span - (int)pAcft);
    printf("Lights: %d @%d\n", sizeof(pAcft->Lights), (int)&pAcft->Lights - (int)pAcft);
    printf("Gears:  %d @%d\n", sizeof(pAcft->Gears), (int)&pAcft->Gears - (int)pAcft);
    printf("Fuel:   %d @%d\n", sizeof(pAcft->Fuel), (int)&pAcft->Fuel - (int)pAcft);
    printf("\n\n");
}


// escolhe o modo de operacao (1 = dinamico, 0 = estatico)
#define DYNAMIC      1

// tamanho
#define VET_SZ       10

/*
 * main
 */
int main(void)
{
    int i;

    srand(time(0));

    TAcft Ac;
    DisplaySizes(&Ac);

    #if DYNAMIC
        int *Vetor;
    #else
        int Vetor[VET_SZ];
    #endif // DYNAMIC

    #if DYNAMIC
        Vetor = malloc(VET_SZ * sizeof(int));
    #endif // DYNAMIC

    for(i = 0; i < VET_SZ; i++)
    {
        Vetor[i] = (rand() % 10) + 1;
    }

    printf("Numeros aleatorios sao:\n");
    for(i = 0; i < VET_SZ; i++)
    {
        if(i) printf(", ");
        printf("%d", Vetor[i]);
    }
    putchar('.');
    putchar('\n');

    #if DYNAMIC
        free(Vetor);
    #endif // DYNAMIC

    return(0);
}
