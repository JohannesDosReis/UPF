#include <stdio.h>

int AbreArquivo(int x)
{
    if(x > 100)
    {
        exit(2); // finaliza o programa
    }

    return(2); // finaliza a função apenas
}

int main(int ArgC, char *ArgV[])
{
    // tipo ARQUIVO para usar
    FILE *pFile;

    AbreArquivo(103);

    // Abre um arquivo: nome e modo de operação
    // arquivo escrita.txt em modo de escrita (write)
    pFile = fopen("escrita.txt", "w");
    if(!pFile) // if(pFile == NULL)
    {
        printf("\nArquivo 'escrita.txt' nao pode ser aberto para escrita!\n\n");
        exit(1);
    }

    // escrita
    fprintf(pFile, "Exemplo de escrita em arquivo!\n");
    fprintf(pFile, "Outra linha\n");
    fprintf(pFile, "Linha 3\n");
    fprintf(pFile, "Linha 4\n");
    fputs("Usando fputs()\n", pFile);
    fputc('\n', pFile);
    fputc('\n', pFile);
    fprintf(pFile, "Formato: %02d/%02d/%02d\n", 18, 9, 2017);


    fclose(pFile);

    return(0);
}


