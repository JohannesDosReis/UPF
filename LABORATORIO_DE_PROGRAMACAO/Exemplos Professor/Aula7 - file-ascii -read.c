#include <stdio.h>


int main(int ArgC, char *ArgV[])
{
    int N;

    // tipo ARQUIVO para usar
    FILE *pFile;

    // Abre um arquivo: nome e modo de operação
    // arquivo data-size.inf em modo de leitura (read)
    pFile = fopen("data-size.inf", "r");
    if(!pFile) // if(pFile == NULL)
    {
        printf("\nArquivo 'data-size.inf' nao pode ser aberto para leitura!\n\n");
        exit(1);
    }

    // le o valor do arquivo
    fscanf(pFile, "%d", &N);

    while(N)
    {
        printf("%02d", N);
        N--;
        if(N) printf(", ");
        else putchar('.');
    }
    putchar('\n');

    fclose(pFile);
    getchar();

    return(0);
}


