#include <stdio.h>
#include <stdlib.h>

/*
 * main
 */
int main(void)
{
    int n;

    printf("Chamando nosso exemplo 9.1:\n");
    n = system("\"Aula9.1 - command line.exe\" -p COM3 -b 115200");
    printf("Retorno: %d\n", n);

    return(0);
}
