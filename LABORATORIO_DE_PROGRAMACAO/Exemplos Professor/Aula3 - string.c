#include <stdio.h>
#include <string.h> // funções para manipulação de strings
#include <conio.h>

int main(void)
{
    int N1 = 35;
    char Str[10];
    int N2 = 44;

    printf("Digite uma string de ate 9 letras: ");
    scanf("%s", Str); // !!! STRING nao tem o & !!!

    printf("Voce digitou <%-9s> que tem %d letras.\n", Str, strlen(Str));
    printf("N1= %d e N2= %d\n", N1, N2);

    return(0);
}
