#include <stdio.h>
#include <conio.h>

int **CriaMatriz(int Linha, int Coluna)
{
    // ponteiro para ponteiro para inteiro
    int **Temp;
    int i, j;

    // cria o vetor de linhas da matriz
    Temp = malloc(Linha * sizeof(*Temp)); // *Temp -> int* (ponteiro)

    // para cada linha desta matriz...
    for(i = 0; i < Linha; i++)
    {
        // ... cria um vetor de inteiros
        Temp[i] = malloc(Coluna * sizeof(**Temp)); // **Temp --> int
    }

    // inicializa com linha x coluna
    for(i = 0; i < Linha; i++)
    {
        for(j = 0; j < Coluna; j++)
        {
            // numero no formato LLCC
            Temp[i][j] = (i+1)*100 + j + 1;
        }
    }

    // ponteiro da matriz criada
    return(Temp);
}

void DestroiMatriz(int **Mat, int Linha, int Coluna)
{
    int i;

    // para cada linha desta matriz...
    for(i = 0; i < Linha; i++)
    {
        // ... cria um vetor de inteiros
        free(Mat[i]); // **Temp --> int
    }

    // cria o vetor de linhas da matriz
    free(Mat); // *Temp -> int* (ponteiro)
}

void ExibeMatriz(int **Mat, int Linha, int Coluna)
{
    int i, j;
    printf("Mat[][] = \n");

    for(i = 0; i < Linha; i++)
    {
        putchar(' ');
        for(j = 0; j < Coluna; j++)
        {
            printf("%04d ", Mat[i][j]);
        }
        putchar('\n');
    }
}

int main(void)
{
    const int TAM_L = 10;   // linha
    const int TAM_C = 15;   // coluna

    int **Mat;

    // cria a matriz dinamicamente
    Mat = CriaMatriz(TAM_L, TAM_C);

    // exibe esta matriz
    ExibeMatriz(Mat, TAM_L, TAM_C);

    // libera a memoria da matriz
    DestroiMatriz(Mat, TAM_L, TAM_C);

    return(0);
}
