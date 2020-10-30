#include <stdio.h>  // standard input/output -> Entrada e saida padrao
#include <conio.h>  // console extended I/O
#include <string.h> // manipular strings

int main(void)
{
    // um texto de ate 100 letras
    // 101 pois o ultimo eh um marcador final
    char Texto[101];

    printf("Digite um texto: ");
    //scanf("%s", Texto); // Unica variavel que nao vai o & !!
    gets(Texto);    // le um texto por inteiro ate teclar enter.
    putchar('\n');

    printf("Voce digitou [%s] com %d letras\n", Texto, strlen(Texto));

    return(0);
}
