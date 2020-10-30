#include <stdio.h>
#include <string.h> // funções para manipulação de strings
#include <conio.h>

int main(void)
{
    char Str1[31];
    char Str2[31];
    char Stringao[100];

    printf("Digite uma string de ate 30 letras: ");
    //scanf("%s", Str1); // !!! STRING nao tem o & !!!
    gets(Str1); // le toda a linha até o '\n' final
    printf("Digite uma string de ate 30 letras: ");
    scanf("%s", Str2); // !!! STRING nao tem o & !!!

    printf("Voce digitou <%-9s> que tem %d letras.\n", Str1, strlen(Str1));
    printf("Voce digitou <%-9s> que tem %d letras.\n", Str2, strlen(Str2));


    strcpy(Stringao, "Texto: [");
    puts(Stringao);
    strcat(Stringao, Str1);
    puts(Stringao);
    strcat(Stringao, ", e ");
    puts(Stringao);
    strcat(Stringao, Str2);
    puts(Stringao);
    strcat(Stringao, "] fim!");
    puts(Stringao);
    strcpy(Stringao, "Apaga tudo!");
    puts(Stringao);

    // a partir do final
    puts(&Stringao[strlen(Stringao)+1]);

    return(0);
}
