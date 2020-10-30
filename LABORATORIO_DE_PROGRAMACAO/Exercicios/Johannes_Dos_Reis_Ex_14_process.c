#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void erro()
{
    printf("Parametro Invalido");
    exit(1);
}

int average(FILE *pFile)
{
    int number;
    float media;
    fscanf(pFile, "%f", &media);
    while (fscanf(pFile, "%d", &number) != EOF)
    {
        media = (media + number)/2;
    }
    return media*100;
}

int maximum(FILE *pFile)
{
    int number, larger;
    fscanf(pFile, "%d", &larger);
    while (fscanf(pFile, "%d", &number) != EOF)
    {
        if (number > larger)
            larger = number;
    }
    return larger;
}

int minimum(FILE *pFile)
{
    int number, smaller;
    fscanf(pFile, "%d", &smaller);
    while (fscanf(pFile, "%d", &number) != EOF)
    {
        if (number < smaller)
            smaller = number;
    }
    return smaller;
}

void show(FILE *pFile)
{
    char number;
    while (fscanf(pFile, "%c", &number) != EOF)
    {
        printf("%c",number);
    }
}

int main(int argc, char *argv[])
{
    FILE *pFile;
    int i = 1;
    argc--;
    if (argc != 4)
    {
        printf("Parametro Invalido\n");
        exit(1);
    }
    if (strcmp(argv[i], "-f") == 0)
    {
        i++;
        pFile = fopen(argv[i], "r");
        if (!pFile)
        {
            printf("\nArquivo '%s' nao pode ser aberto para leitura!\n\n", argv[i]);
            exit(1);
        }
    }
    else
        erro();
    i++;
    if (strcmp(argv[i], "-o") == 0)
    {
        i++;
        int media, maximo, minimo;
        if ((strlen(argv[i]) == strlen("average")) && (strcmp(argv[i],"average") == 0))
        {
            media = average(pFile);
            fclose(pFile);
            return media;
        }
        else if ((strlen(argv[i]) == strlen("max")) && (strcmp(argv[i],"max") == 0))
        {
            maximo = maximum(pFile);
            fclose(pFile);
            return maximo;
        }
        else if ((strlen(argv[i]) == strlen("min")) && (strcmp(argv[i],"min") == 0))
        {
            minimo = minimum(pFile);
            fclose(pFile);
            return minimo;
        }
        else if ((strlen(argv[i]) == strlen("display")) && (strcmp(argv[i],"display") == 0))
        {
            show(pFile);
            fclose(pFile);
            return 0;
        }
        else
            erro();
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
