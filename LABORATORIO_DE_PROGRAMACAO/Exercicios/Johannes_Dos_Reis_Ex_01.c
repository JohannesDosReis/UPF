#include <stdio.h>
#include <conio.h>

int main(void)
{
    printf("Digite 10 valores para o vetor\n");
    int i, vetor[10];
    for(i = 0; i < 10; i++)
    {
        printf("Valor %02d de 10: ", i+1);
        scanf("%d", &vetor[i]);
        if(vetor[i] > 50 || vetor[i] < 1)
        {
            printf("Valor do item %d [%d] deve estar entre 1 e 50\n", i+1, vetor[i]);
            i--;
        }
    }
    for(i = 0; i < 10; i++)
        {
            printf(" %02d ", i);
        }
        printf("\n");
        for(i = 0; i < 10; i++)
        {
             printf(" %02d ", vetor[i]);
        }
        printf("\n");
        printf("%c%02d ", 24, vetor[0]);
        for(i = 1; i < 10; i++)
        {
            if(vetor[i] < vetor[i-1])
            {
                printf("%c%02d ", 25, vetor[i-1]-vetor[i]);
            }
            else
            {
                printf("%c%02d ", 24, vetor[i]-vetor[i-1]);
            }
        }
        printf("\n");
        printf("%c%02d ", 24, vetor[0]);
        for(i = 1; i < 10; i++)
        {
            if(vetor[i] < vetor[0])
            {
                printf("%c%02d ", 25, vetor[0] - vetor[i]);
            }
            else
            {
                printf("%c%02d ", 24, vetor[i] - vetor[0]);
            }
        }
    return 0;
}
