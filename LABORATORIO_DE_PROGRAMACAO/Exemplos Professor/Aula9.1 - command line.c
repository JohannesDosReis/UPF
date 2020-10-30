#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * main
 */
int main(int argc, char *argv[])
{
    int i;
    printf("Executando: \"%s\" com %d parametros:\n", argv[0], argc-1);
    argc--;
    i = 1;
    while(argc)
    {
        printf("  Par: [%d] %s\n", i, argv[i]);

        argc--;
        i++;
    }

    system("pause");
    return(i);
}
