#include <stdio.h>

int main(void)
{
    FILE *pFile;
    int size, i, j;
    pFile = fopen("matrix.inf", "r+");
    if(!pFile) // if(pFile == NULL)
    {
        printf("\nArquivo 'matrix.inf' nao pode ser aberto para leitura e escrita!\n\n");
        exit(1);
    }
    fscanf(pFile, "%d", &size);
    if(size < 0 || size > 35)
    {
        fprintf(pFile, "10");
        size = 10;
    }
    fclose(pFile);
    pFile = fopen("matrix.csv", "w");
    if(!pFile) // if(pFile == NULL)
    {
        printf("\nArquivo 'matrix.inf.csv' nao pode ser aberto para escrita!\n\n");
        exit(1);
    }
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(i == j) fprintf(pFile, "1");
            else fprintf(pFile, "0");
            if(j != size-1) fprintf(pFile, ";");
        }
        fputc('\n', pFile);
    }
    fclose(pFile);
    return 0;
}


