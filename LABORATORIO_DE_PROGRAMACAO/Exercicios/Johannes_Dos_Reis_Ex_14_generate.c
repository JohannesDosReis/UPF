#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void erro()
{
    printf("Parametro Invalido");
    exit(1);
}

int compare(char text1[], char text2[])
{
    int k = 0, iguais = 1;
    while (text1[k] != ' ' && text1[k] != '=')
    {
        if (text1[k] != text2[k]) iguais = 0;
        k++;
    }
    return iguais;
}

int read(char text[])
{
    int k = 0, j = 0;
    while (text[k] != '\0')
    {
        if (isdigit(text[k]))
            text[j++] = text[k];
        k++;
    }
    text[j] = '\0';
    return atoi(text);
}

int main(int argc, char *argv[])
{
    FILE *pFile;
    char text[20];
    int i = 1, row = 0, col = 0, rand_min = 0, rand_max = 0;
    argc--;
    if (argc != 4)
    {
        printf("Parametro Invalido\n");
        exit(1);
    }
    if (strcmp(argv[i], "-i") == 0)
    {
        i++;
        pFile = fopen(argv[i], "r");
        if (!pFile)
        {
            printf("\nArquivo '%s' nao pode ser aberto para leitura!\n\n", argv[i]);
            exit(1);
        }
        while (fscanf(pFile, "%s", text) != EOF)
        {
            if (compare(text,"row"))
                row = read(text);
            else if (compare(text,"col"))
                col = read(text);
            else if (compare(text,"rand_min"))
                rand_min = read(text);
            else if (compare(text,"rand_max"))
                rand_max = read(text);
        }
        fclose(pFile);
    }
    else
        erro();
    i++;
    if (strcmp(argv[i], "-o") == 0)
    {
        i++;
        srand(time(NULL));
        pFile = fopen(argv[i], "w");
        if (!pFile)
        {
            printf("\nArquivo '%s' nao pode ser aberto para escrita!\n\n", argv[i]);
            exit(1);
        }
        int c, l;
        fprintf(pFile,"%d %d\n", row, col);
        for (l = 0; l < row; l++)
        {
            for (c = 0; c < col; c++)
            {
                fprintf(pFile, "%d ", (rand()%(rand_max - rand_min)) + rand_min)+1;
            }
            fprintf(pFile, "\n");
        }
        fclose(pFile);
    }
    else
        erro();
    return 0;
}
/*Exercicio 14:

Faça tres programas que:
  1) generate.exe receba como parametro um nome de arquivo -i 'model.ini'
     -o 'matriz.dat' e crie uma matriz de acordo com os parametros neste
     arquivo.
  2) process.exe recebe como parametro -f 'matriz.dat' e -o 'operation'
     operation pode ser: 'average', 'max', 'min', 'display'. As operações
     exceto a 'display' devem retornar o valor via return(). A media pode
     ser retornada com 2 casas decimais em inteiro return(Media * 100)
  3) matriz.exe programa principal que faz a chamada para os outros dois

model.ini:
row=10
col=20
rand_min=10
rand_max=50

matriz.dat:
10 20
x x x x x x x x
x x x x x x x x
x x x x x x x x
x x x x x x x x
x x x x x x x x ...*/
