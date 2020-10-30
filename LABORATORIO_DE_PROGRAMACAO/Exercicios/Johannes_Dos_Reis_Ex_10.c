#include <stdio.h>


int main(void)
{
    FILE *pFile;
    char text[1000];
    unsigned long i = 0;
    unsigned long j = 0;
    char c;
    char name[40];
    printf("Digite o nome do arquivo: ");
    gets(name);
    pFile = fopen(name, "r");
    if(!pFile) // if(pFile == NULL)
    {
        printf("\nArquivo %s nao pode ser aberto para leitura!\n\n", name);
        exit(1);
    }
    fgets(text, 1000, pFile);
    while ((c = text[i++]) != '\0')
    {
        if(c == ' ')
        {
            text[j++] = '\n';
        }
        else if (isalnum(c) || c != "á" || c != "é" || c != "í" || c != "ó" ||
                   c != "ú" || c != "Á" || c != "É" || c != "Í" || c != "Ó" || c != "Ú")
        {
            text[j++] = c;
        }
    }
    text[j] = '\0';
    putchar('\n');
    fclose(pFile);
    pFile = pFile = fopen("banana-split.txt", "w");
    if(!pFile) // if(pFile == NULL)
    {
        printf("\nArquivo 'banana-split.txt' nao pode ser aberto para escrita!\n\n");
        exit(1);
    }
    i = 0;
    fputs(text, pFile);
    fclose(pFile);
    return 0;
}


