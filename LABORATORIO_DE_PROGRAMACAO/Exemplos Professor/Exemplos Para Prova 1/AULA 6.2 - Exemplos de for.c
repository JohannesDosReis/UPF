#include <stdio.h>

int main(void)
{
    int n, i, j, s;
    char l;

    //ini: 1
    //fim: 6
    //pas: +1

    for(n = 1; n <= 10; n = n + 1)
    {
        printf("n=%d e n^2=%d\n", n, n*n);
    }

    putchar('\n');
    // ini: 15
    // fim:  5
    // pas: -2

    for(n = 15; n >= 5; n = n - 2)
    {
        printf("%d ", n);
    }

    putchar('\n');
    putchar('\n');
    putchar('\n');
    // ini: 'a'
    // fim: 'z'
    // pas: +1

    for(l = 'a'; l <= 'z'; l = l + 1)
    {
        printf("letra l='%c' codigo %02d\n", l, l);
    }

    putchar('\n');
    putchar('\n');

    for(i = 1; i <= 10; i = i + 1)              // para cada linha de 1 a 20...
    {
        for(j = 1; j <= 5; j = j + 1)          // para cada coluna de 1 a 10 ...
        {
            printf("(%02d,%02d)   ", i, j);     // escreva na tela o par (linha, coluna)
        }
        putchar('\n');                          // ao final de cada linha, passa para a proxima
    }

    putchar('\n');

    //ini: 1
    //fim: 6
    //pas: +1

    s = 0;
    for(n = 1; n <= 10; n = n + 1)
    {
        s = s + n;
        printf("n=%02d e soma=%d\n", n, s);
    }

    return(0);
}
