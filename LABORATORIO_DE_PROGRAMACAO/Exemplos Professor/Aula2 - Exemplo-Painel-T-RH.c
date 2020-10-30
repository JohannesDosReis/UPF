#include <stdio.h>      // standard input/output -> Entrada e saida padrao

// printf -> saida formatada
// scanf --> entrada formatada

int main(void)
{
    int T = 27;  // °C
    char U = 80; // %
    char Barra[] = { 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, '\0' };

    printf("%c%s%c\n", 201, Barra, 187);
    printf("%c  PRINTF  %c\n", 186, 186);
    printf("%c T= %3d%cC %c\n", 186, T, 248, 186);
    printf("%c U= %3u%%  %c\n", 186, U, 186);
    printf("+----------+\n");
}
