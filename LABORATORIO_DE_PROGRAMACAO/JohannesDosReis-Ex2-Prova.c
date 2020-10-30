#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int N, i, j = 0, posmaoir, posmenor;
    float *vet, media = 0, maior, menor;
    srand(time(NULL));
    do
    {
        printf("Digite um valor entre 10 e 100: ");
        scanf("%d", &N);
    }
    while (N < 10 || N > 100);
    vet = malloc(N*sizeof(*vet));
    for (i = 0; i < N; i++)
    {
        *(vet + i) = (float) (rand()%49 + 1 + (float)rand()/RAND_MAX);
        media += *(vet + i);
    }
    media /= N;
    i = 0;
    maior = *(vet + i);
    menor = *(vet + i);
    for (i = 1; i < N; i++)
    {
        if (*(vet + i) < menor)
        {
            menor = *(vet + i);
            posmenor = i;
        }
        if (*(vet + i) > maior)
        {
            maior = *(vet + i);
            posmaoir = i;
        }
    }
    printf("  ");
    for (i = 0; i < 10; i++)
        printf("      %d", i);
    printf("\n");
    printf("   %c", 218);
    for (i = 0; i < 74; i++) printf("%c", 196);
    printf("%c\n ", 191);
    for (i = 0; i < N; i++)
    {
        if (i % 10 == 0) printf("%d %c ", i, 179);
        if (*(vet + i) < media) printf(" %c", 25);
        else if (*(vet + i) > media) printf(" %c", 24);
        else printf("  ");
        printf("%04.1f ", *(vet + i));
        j++;
        if (j == 10)
        {
            printf("   %c\n", 179);
            j = 0;
        }
    }
    printf("   %c", 192);
    for (i = 0; i < 74; i++) printf("%c", 196);
    printf("%c\n\n", 217);
    printf("Maior: %4.1f  Pos: %d\n", maior, posmaoir);
    printf("Menor: %4.1f  Pos: %d\n", menor, posmenor);
    free(vet);
    return 0;
}
