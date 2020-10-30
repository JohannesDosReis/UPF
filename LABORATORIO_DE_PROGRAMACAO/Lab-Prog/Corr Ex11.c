#include <stdio.h>

#define ERR_NONE        0
#define ERR_OUTPUT      1
#define ERR_INPUT       2
#define ERR_INPUT_WRITE 3

/*
 * Creates an output file with matrix data
 */
void GenerateOutputFile(int Sz, char PtBr)
{
    FILE *pFile;
    int i, j;

    pFile = fopen("matrix.csv", "w");
    if(!pFile)
    {
        printf("\nCould not save output file \"matrix.csv\"!\n\n");
        exit(ERR_OUTPUT);
    }

    for(i = 1; i <= Sz; i++)
    {
        for(j = 1; j <= Sz; j++)
        {
            if(i == j) fputc('1', pFile);
            else fputc('0', pFile);

            if(j < Sz) // not the last one?
            {
                if(PtBr) fputc(';', pFile); // Brazilian portuguese
                else fputc(',', pFile);     // English
            }
        }
        fputc('\n', pFile);
    }

    fclose(pFile);
}

/*
 * Creates an output file with matrix data
 */
int ReadMatrixSize(void)
{
    // tipo ARQUIVO para usar
    FILE *pFile;
    int N;

    // Abre um arquivo: nome e modo de operação
    // arquivo data-size.inf em modo de leitura (read)
    pFile = fopen("matrix.inf", "r");
    if(!pFile) // if(pFile == NULL)
    {
        printf("\nInput file \"matrix.inf\" could not be read!\n\n");
        exit(ERR_INPUT);
    }

    // le o valor do arquivo
    fscanf(pFile, "%d", &N);

    fclose(pFile);

    if(N < 1 || N > 35)
    {
        pFile = fopen("matrix.inf", "w");
        if(!pFile) // if(pFile == NULL)
        {
            printf("\nInput file \"matrix.inf\" could not be write!\n\n");
            exit(ERR_INPUT_WRITE);
        }

        // le o valor do arquivo
        fputs("10\n", pFile);
        N = 10;

        fclose(pFile);
    }

    return(N);
}


/*
 * Creates an output file with matrix data
 */
int main(int ArgC, char *ArgV[])
{
    int N;

    // read size
    N = ReadMatrixSize();

    // now generate output (true means PtBr -> ; separator)
    GenerateOutputFile(N, 1);

    puts("All done!\n");
    getchar();

    return(0);
}


