#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
 * Aleatoriza o vetor
 */
void Randomize(float Vet[], int N)
{
    int i;

    // percorre todos os elementos do vetor
    for(i = 0; i < N; i++)
    {
        // aleatorio: 1.0 ate 50.0 --> 10 ate 500
        Vet[i] = ((float)(rand() % (500-10)) + 10) * 0.1;
    }
}

/*
 * Aleatoriza o vetor
 */
float Average(float Vet[], int N)
{
    int i;
    float Soma;
    float Total;

    Soma = 0;
    Total = (float)N;

    // percorre todos os elementos do vetor
    for(i = 0; i < N; i++)
    {
        // soma o valor
        Soma += Vet[i];
    }

    // retorna a media
    return(Soma/Total);
}

/*
 * Escreve o vetor na tela
 */
void DisplayVet(float Vet[], int N, float Avg)
{
    int i, j, l;
    int linhas;

    // colunas
    printf("\n\n     ");
    for(j = 0; j < 10; j++) printf("   %d   ", j);
    putchar('\n');

    // linha das colunas
    printf("    ");
    putchar(218);
    for(j = 0; j < 70; j++) putchar(196);
    putchar(191);
    putchar('\n');

    // calcula a quantidade de linhas necessarias
    linhas = ((N-1)/10) + 1;
    i = 0;

    for(l = 0; l < linhas; l++)
    {
        // linha
        printf(" %2d %c", l*10, 179);

        // todas as colunas
        for(j = 0; j < 10; j++)
        {
            // ainda tem numeros?
            if(i < N)
            {
                putchar(' ');
                if(Vet[i] > Avg) putchar(24); // seta acima (24)
                else if(Vet[i] < Avg) putchar(25); // seta abaixo (25)
                else putchar(' '); // sem seta pois eh igual

                if(Vet[i] < 10.0) putchar('0');
                printf("%.1f ", Vet[i]);

                // conta um a mais que foi escrito na tela
                i++;
            }
            else
            {
                // completa com espaco em branco
                printf("       ");
            }
        }

        // fim de linha
        putchar(179);
        putchar('\n');
    }

    // linha final
    printf("    ");
    putchar(192);
    for(j = 0; j < 70; j++) putchar(196);
    putchar(217);
    putchar('\n');
}

/*
 * Escreve o vetor na tela
 */
void DisplayMaxMin(float Vet[], int N)
{
    int Max, Min, i;

    // considera o primeiro sendo o maior e o menor
    Max = 0;
    Min = 0;

    // pula o primeiro
    for(i = 1; i < N; i++)
    {
        // eh maior que o maior?
        if(Vet[i] > Vet[Max])
        {
            Max = i;
        }

        // eh menor que o menor?
        if(Vet[i] < Vet[Min])
        {
            Min = i;
        }
    }

    // escreve na tela
    putchar('\n');
    printf("O maior numero vale %.1f e esta na posicao {", Vet[Max]);
    for(i = 0; i < N; i++) if(Vet[i] == Vet[Max]) printf("%d, ", i);
    printf("\b\b}.\n");

    printf("O menor numero vale %.1f e esta na posicao {", Vet[Min]);
    for(i = 0; i < N; i++) if(Vet[i] == Vet[Min]) printf("%d, ", i);
    printf("\b\b}.\n");
}

/*
 * MAIN
 */
int main(void)
{
    const int N = 40;
    float Vet[N];
    float Avg;

    // inicializa o gerador aleatorio
    srand(time(0));

    // aleatoriza o vetor
    Randomize(Vet, N);

    // calcula media
    Avg = Average(Vet, N);
    printf("A media de todos os %d valores eh %.2f\n", N, Avg);

    // escreve os numeros na tela
    DisplayVet(Vet, N, Avg);

    // escreve o maior e menor na tela
    DisplayMaxMin(Vet, N);

    return(0);
}







