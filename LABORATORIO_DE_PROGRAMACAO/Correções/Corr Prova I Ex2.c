#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
 * Faz a leitura e valida o tamanho do vetor
 */
int ReadSize(void)
{
    int N;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    while(N < 10 || N > 100)
    {
        printf("O valor de N deve ser de 10 a 100. Escolha outro: ");
        scanf("%d", &N);
    }

    // retorna
    return(N);
}

/*
 * Aleatoriza o vetor
 */
void Randomize(float *Vet, int N)
{
    // percorre todos os elementos do vetor
    while(N)
    {
        // aleatorio: 1.0 ate 50.0 --> 10 ate 500
        *Vet = ((float)(rand() % (500-10)) + 10) * 0.1;

        // proximo
        Vet++;
        N--;
    }
}

/*
 * Aleatoriza o vetor
 */
float Average(float *Vet, int N)
{
    float Soma;
    float Total;

    Soma = 0;
    Total = (float)N;

    // percorre todos os elementos do vetor
    while(N)
    {
        // soma o valor
        Soma += *Vet;

        // proximo
        Vet++;
        N--;
    }

    // retorna a media
    return(Soma/Total);
}

/*
 * Escreve o vetor na tela
 */
void DisplayVet(float *Vet, int N, float Avg)
{
    int i, j;
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

    for(i = 0; i < linhas; i++)
    {
        // linha
        printf(" %2d %c", i*10, 179);

        // todas as colunas
        for(j = 0; j < 10; j++)
        {
            // ainda tem numeros?
            if(N)
            {
                putchar(' ');
                if(*Vet > Avg) putchar(24); // seta acima
                else if(*Vet < Avg) putchar(25); // seta abaixo
                else putchar(' '); // sem seta pois eh igual

                if(*Vet < 10.0) putchar('0');
                printf("%.1f ", *Vet);

                // proximo valor do vetor
                Vet++;
                N--;
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
void DisplayMaxMin(float *Vet, int N)
{
    int Max, Min, i;
    float *pMax, *pMin;

    // considera o primeiro sendo o maior e o menor
    Max = Min = i = 0;
    pMax = pMin = Vet;

    // pula o primeiro
    N--;
    Vet++;
    i++;

    while(N)
    {
        // eh maior que o maior?
        if(*Vet > *pMax)
        {
            pMax = Vet;
            Max = i;
        }

        // eh menor que o menor?
        if(*Vet < *pMin)
        {
            pMin = Vet;
            Min = i;
        }

        // proximo
        Vet++;
        i++;
        N--;
    }

    // escreve na tela
    putchar('\n');
    printf("O maior numero vale %.1f e esta na posicao %d.\n", *pMax, Max);
    printf("O menor numero vale %.1f e esta na posicao %d.\n", *pMin, Min);
}

/*
 * MAIN
 */
int main(void)
{
    int N;
    float *Vet;
    float Avg;

    // inicializa o gerador aleatorio
    srand(time(0));

    // obtem o tamanho do vetor
    N = ReadSize();

    // aloca memoria para o vetor
    Vet = malloc(N*sizeof(float));

    // aleatoriza o vetor
    Randomize(Vet, N);

    // calcula media
    Avg = Average(Vet, N);
    printf("A media de todos os %d valores eh %.2f\n", N, Avg);

    // escreve os numeros na tela
    DisplayVet(Vet, N, Avg);

    // escreve o maior e menor na tela
    DisplayMaxMin(Vet, N);

    // libera a memoria alocada
    free(Vet);

    return(0);
}







