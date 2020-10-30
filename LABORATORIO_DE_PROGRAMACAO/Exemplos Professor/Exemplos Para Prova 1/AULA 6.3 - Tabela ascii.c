#include <stdio.h>

int main(void)
{
    int i;

    printf("%3d %c %c ", 1, 1, 186);
    printf("%3d %c %c ", 2, 2, 186);
    printf("%3d %c %c ", 3, 3, 186);
    printf("%3d %c %c ", 4, 4, 186);
    printf("%3d %c %c ", 5, 5, 186);
    printf("%3d %c %c ", 6, 6, 186);
    putchar('\n');

    for(i = 12; i < 255; i++)
    {
        printf("%3d %c %c ", i, i, 186);
    }

    getchar();
    return(0);
}


