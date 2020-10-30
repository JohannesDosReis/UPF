#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
 * Calcula a media de 'n' valores float
 */
float Media(int n, ...)
{
    int i = 0;
    double Soma = 0;

    // lista de argumentos repassados
    va_list args;

    // argumentos variaveis iniciam apos o 'int n'
    va_start(args, n);

    while(i < n)
    {
        // soma o argumento
        Soma = Soma + va_arg(args, double);
        i++;
    }

    // finaliza a lista de argumentos
    va_end(args);

    return(Soma / n);
}

/*
 * main
 */
int main(void)
{
    int n;
    float m;

    printf("Calling \"Media(5, 1.1, 2.2, 3.3, 4.4, 5.5);\": ");
    m = Media(5, 1.1, 2.2, 3.3, 4.4, 5.5);
    printf("%.1f\n", m);

    printf("Calling \"Media(2, 5.0, 15.0);\": ");
    m = Media(2, 5.0, 15.0);
    printf("%.1f\n", m);

    return(0);
}
