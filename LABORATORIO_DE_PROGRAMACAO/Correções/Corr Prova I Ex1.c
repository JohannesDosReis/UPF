#include <stdio.h>
#include <string.h>

/*
 * Faz a leitura e valida uma string
 */
char *ReadString(void)
{
    int i;
    int Tam;
    char Str[100];
    char *pStr;

    do
    {
        // faz a leitura
        puts("\nDigite uma string de at 50 letras:\n");
        gets(Str);

        // verifica o tamanho
        Tam = strlen(Str);

    // somente strings de ate 50 letras
    }while(Tam > 50);

    // substitui caracteres nao alfa-numericos
    pStr = Str;
    while(*pStr != NULL)
    {
        // se nao for alfanumerico, substitui por um espaço
        if(!isalnum(*pStr)) *pStr = ' ';
        pStr++;
    }

    // aloca memoria para a string dinamica
    pStr = malloc(Tam + 1);

    // copia
    strcpy(pStr, Str);

    // retorna
    return(pStr);
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
    char *Strings[5];
    char L;

    // faz a leitura das 5 strings
    for(i = 0; i < 5; i++) Strings[i] = ReadString();

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

    // desaloca toda a memoria
    for(i = 0; i < 5; i++) free(Strings[i]);

    return(0);
}


