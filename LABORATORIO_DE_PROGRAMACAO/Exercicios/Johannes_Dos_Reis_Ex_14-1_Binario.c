#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ERR_NONE        0
#define ERR_OUTPUT      1
#define ERR_INPUT       2
#define ERR_INPUT_WRITE 3
#define ERR_INPUT_PAR   4
#define ERR_PAR_ERROR   5

// parametroas para criar uma matriz
struct TMatrix
{
    int row;
    int col;
    int rand_min;
    int rand_max;
};

/*
 * Creates an output file with matrix data
 */
void GenerateOutputFile(char* Name, struct TMatrix *Par)
{
    FILE *pFile;
    int i, j;

    pFile = fopen(Name, "wb");
    if(!pFile)
    {
        printf("\nCould not save output file \"%s\"!\n\n", Name);
        exit(ERR_OUTPUT);
    }

    fwrite(&Par->row, sizeof(int), 1, pFile);
    fwrite(&Par->col, sizeof(int), 1, pFile);

    for(i = 0; i < Par->row; i++)
    {
        for(j = 0; j < Par->col; j++)
        {
            int rnd;

            // gera numero aleatorio
            rnd = rand() % (Par->rand_max - Par->rand_min + 1) + Par->rand_min;

            // insere o valor
            fwrite(&rnd, sizeof(int), 1, pFile);
        }
    }


    fclose(pFile);
}

/*
 * Creates an output file with matrix data
 */
int ReadMatrixSize(char* FileName, struct TMatrix* Par)
{
    // tipo ARQUIVO para usar
    FILE *pFile;
    int N;
    char Linha[50];

    // Abre um arquivo: nome e modo de operação
    // arquivo data-size.inf em modo de leitura (read)
    pFile = fopen(FileName, "r");
    if(!pFile) // if(pFile == NULL)
    {
        printf("\nInput file \"%s\" could not be read!\n\n", FileName);
        exit(ERR_INPUT);
    }
    while (fscanf(pFile, "%s", Linha) != EOF)
    {
        char *p;

        // verifica o que tem nessa linha
        p = strchr(Linha, '=');
        if(p)
        {
            *p = '\0';
            p++;

            // converte o restante para a quantidade de linhas
            if(strncmp(Linha, "row", 3) == 0) Par->row = atoi(p);

            // converte o restante para a quantidade de colunas
            if(strncmp(Linha, "col", 3) == 0) Par->col = atoi(p);

            // converte o restante para a quantidade de linhas
            if(strncmp(Linha, "rand_min", 8) == 0) Par->rand_min = atoi(p);

            // converte o restante para a quantidade de linhas
            if(strncmp(Linha, "rand_max", 8) == 0) Par->rand_max = atoi(p);
        }
    }

    fclose(pFile);

    printf("Parametros:\n");
    printf("  Row   : %d\n", Par->row);
    printf("  Col   : %d\n", Par->col);
    printf("  Min   : %d\n", Par->rand_min);
    printf("  Max   : %d\n", Par->rand_max);

    return(N);
}


/*
 * Creates an output file with matrix data
 */
int main(int ArgC, char *ArgV[])
{
    int N;
    int i;

    char FileIn[50];
    char FileOut[50];

    struct TMatrix Par;

    srand(time(0));

    if(ArgC != 5)
    {
        printf("call %s -i 'input.ini' -o 'output.dat'\n", ArgV[0]);
        exit(ERR_INPUT_PAR);
    }

    for(i = 1; i <= 3; i += 2)
    {
        // devemos receber um '-'
        if(ArgV[i][0] != '-') exit(ERR_PAR_ERROR);

        // argumento de entrada?
        if(ArgV[i][1] == 'i')
        {
            // outro parametro?
            if(ArgV[i+1][0] == '-') exit(ERR_PAR_ERROR);

            // copia o mome do arquivo de entrada
            strcpy(FileIn, ArgV[i+1]);
        }
        // argumento de saida?
        else if(ArgV[i][1] == 'o')
        {
            // outro parametro?
            if(ArgV[i+1][0] == '-') exit(ERR_PAR_ERROR);

            // copia o mome do arquivo de saida
            strcpy(FileOut, ArgV[i+1]);
        }
        else
        {
            // outro parametro?
            exit(ERR_PAR_ERROR);
        }

    }

    // parametros
    printf("Input file : %s\n", FileIn);
    printf("Output file: %s\n", FileOut);

    ReadMatrixSize(FileIn, &Par);

    GenerateOutputFile(FileOut, &Par);

    return(0);
}


