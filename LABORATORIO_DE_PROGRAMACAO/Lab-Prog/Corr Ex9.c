#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Leia um inteiro 'N' que deve ser no minimo 5 e no maximo 24.
 *
 */
int TableSize(int Min, int Max)
{
    int Sz;

    printf("Escolha o tamanho da matriz Nx2N: ");
    scanf("%d", &Sz);
    while(Sz < Min || Sz > Max)
    {
        printf("\nO tamanho minimo deve ser %d e o maximo %d.\n", Min, Max);
        printf("Escolha o tamanho da matriz Nx2N: ");
        scanf("%d", &Sz);
    }

    return(Sz);
}

/*
 * Crie, dinamicamente, uma matriz do tamanho N x 2N.
 *
 */
char** CreateTable(int Sz)
{
    char **Matrix;
    int Cols;


    // vetor de linhas
    Matrix = malloc(Sz*sizeof(*Matrix));

    // total de colunas
    Cols = 2 * Sz;

    while(Sz)
    {
        Sz--;

        // cria vetor de colunas
        Matrix[Sz] = malloc(Cols*sizeof(**Matrix));

        // preenche todas as colunas com ' '
        memset(Matrix[Sz], ' ', Cols);
    }

    return(Matrix);
}

/*
 * Destroi a matriz
 *
 */
void DeleteTable(char **Matrix, int Sz)
{
    char** p;

    // primeiro vetor linha
    p = Matrix;

    // para todas as linhas
    while(Sz)
    {
        // destroi o vetor desta linha
        free(*p);

        // proxima linha
        p++;
        Sz--;
    }

    // destroi a matriz
    free(Matrix);
}

/*
 * Preenche o campo minado com minas aleatorias
 */
void RandomMines(char **Matrix, int N, int Prct)
{
    int i, j;

    // ai nao ne ze!
    if(Prct >= 100) return;
    if(Prct < 0) return;

    // converte de porcentagem para quantidade aproximada
    Prct = (N*N*2*Prct + 50)/100;

    // preenche todas as quantidades de bombas
    while(Prct)
    {
        // obtem uma posicao aleatoria
        i = rand() % N;     // 0..N-1 linhas
        j = rand() % (2*N); // 0..2N-1 colunas

        // ja existe uma bomba naquela posicao?
        // se nao existe, cria uma
        if(Matrix[i][j] == ' ')
        {
            // cria uma bomba
            Matrix[i][j] = '*';

            // conta uma bomba a menos
            Prct--;
        }
    }
}

/*
 * Desenha na tela o campo minado
 */
void DrawTable(char **Matrix, int N)
{
    int i, j;

    putchar('\n');
    for(j = 0; j < 2*N; j++) printf("--");
    putchar('\n');

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < 2*N; j++)
        {
            printf("%c ", Matrix[i][j]);
        }
        putchar('\n');
    }

    for(j = 0; j < 2*N; j++) printf("--");
    putchar('\n');
}

/*
 * Completa com as dicas de bombas
 */
void FillHints(char **Matrix, int N)
{
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < 2*N; j++)
        {
            int Cont = 0;

            // aborta a iteração deste for(j) caso a posicao seja uma bomba
            if(Matrix[i][j] == '*') continue;

            // conta se existe bombas acima
            if(i)
            {
                if(j && Matrix[i-1][j-1] == '*') Cont++;
                if(Matrix[i-1][j] == '*') Cont++;
                if(j<(2*N-1) && Matrix[i-1][j+1] == '*') Cont++;
            }

            // na mesma linha
            if(j && Matrix[i][j-1] == '*') Cont++;
            if(j<(2*N-1) && Matrix[i][j+1] == '*') Cont++;

            // conta se existe bombas abaixo
            if(i < N - 1)
            {
                if(j && Matrix[i+1][j-1] == '*') Cont++;
                if(Matrix[i+1][j] == '*') Cont++;
                if(j<(2*N-1) && Matrix[i+1][j+1] == '*') Cont++;
            }

            // existe bomba?
            if(Cont)
            {
                // insere o caracter
                Matrix[i][j] = '0' + Cont;
            }

        }
    }

}

/*
 * main
 */
int main(void)
{
    int N;
    char **Mine;

    srand(time(0));

    // faz a leitura do tamanho desejado
    N = TableSize(5, 24);

    // cria a tabela do campo minado
    Mine = CreateTable(N);

    // Cria minas aleatorias
    RandomMines(Mine, N, 5);

    // desenha o campo minado na tela
    DrawTable(Mine, N);

    system("pause");
    FillHints(Mine, N);

    // desenha o campo minado na tela
    DrawTable(Mine, N);

    // destroi a tabela do campo minado
    DeleteTable(Mine, N);
}
