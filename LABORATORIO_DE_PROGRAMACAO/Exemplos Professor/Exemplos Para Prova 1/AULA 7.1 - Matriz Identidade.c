#include <stdio.h>

int main(void)
{
    int n, i, j;

    n = 5;

    // antes de desenhar a matriz, desenha o +-----+
    putchar(218);
    for(j = 1; j <= 2*n - 1; j = j + 1) putchar(196);
    putchar(191);
    putchar('\n');

    // para cada linha de 1 a N...
    for(i = 1; i <= n; i = i + 1)
    {
        // antes da primeira coluna, um |
        putchar(179);

        // para cada coluna de 1 a N ...
        for(j = 1; j <= n; j = j + 1)
        {
            // diagonal principal
            if(i == j) printf("1");
            else printf("0");

            // espaço entre elementos, exceto a ultima coluna
            if(j != n) putchar(' ');
        }

        // depois da ultima coluna, um |
        putchar(179);

        // ao final de cada linha, passa para a proxima
        putchar('\n');
    }

    // depois de desenhar a matriz, desenha o +-----+
    putchar(192);
    for(j = 1; j <= 2*n - 1; j = j + 1) putchar(196);
    putchar(217);
    putchar('\n');


    putchar('\n');


    return(0);
}
