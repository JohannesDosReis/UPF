#include <stdio.h>
#include <string.h>

/*
 * Faz a leitura e valida uma string
 */
int ReadString(char *pStr)
{
    int i;
    int Tam;

    do
    {
        // faz a leitura
        puts("\nDigite uma string de ate 50 letras:\n");
        gets(pStr);

        // verifica o tamanho
        Tam = strlen(pStr);

    // somente strings de ate 50 letras
    }while(Tam > 50);

    // substitui caracteres nao alfa-numericos
    while(*pStr != 0) // ou '\0'
    {
        // se nao for alfanumerico, substitui por um espaço
        if(!isalnum(*pStr)) *pStr = ' ';
        pStr++;
    }

    // retorna
    return(Tam);
}

/*
 * Faz a leitura e valida uma string
 */
void DisplayString(char *pStr, char L)
{
    int Tam;
    int Letras;
    char *p;

    // calcula o tamanho da string
    Tam = strlen(pStr);

    // conta quantas vezes a letra L aparece na string
    p = pStr;
    Letras = 0;
    while(*p)
    {
        if(*p == L) Letras++;
        p++;
    }

    // escreve conforme o padrao
    printf("[%02d/%02d] >> %s\n", Letras, Tam, pStr);
    printf("           ");

    // completa com os ^
    p = pStr;
    while(*p)
    {
        if(*p == L) putchar('^');
        else putchar(' ');
        p++;
    }
    putchar('\n');
}

/*
 * MAIN
 */
int main(void)
{
    int i;
    char Strings[5][50];
    char L;

    // faz a leitura das 5 strings
    for(i = 0; i < 5; i++) ReadString(Strings[i]);

    printf("\nEscolha uma letra para pesquisar: ");
    scanf("\n%c", &L);

    while(!isalnum(L))
    {
        printf("\nEscolha outra letra para pesquisar, alfanumerica: ");
        scanf("\n%c", &L);
    }
    putchar('\n');

    // escreve todas as strings na tela
    for(i = 0; i < 5; i++) DisplayString(Strings[i], L);

    return(0);
}


