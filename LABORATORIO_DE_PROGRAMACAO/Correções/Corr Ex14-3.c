#include <stdio.h>
#include <stdlib.h>

/*
 * main
 */
int main(void)
{
    int n;

    printf("Running 14-1:\n");
    n = system("\"Corr Ex14-1.exe\" -i model.ini -o matrix.dat");

    printf("\nRunning 14-2:\n");
    system("\"Corr Ex14-2.exe\" -f matrix.dat -o display");
    putchar('\n');

    n = system("\"Corr Ex14-2.exe\" -f matrix.dat -o average");
    printf("Average is  : %.2f\n", (float)n * 0.01);

    n = system("\"Corr Ex14-2.exe\" -f matrix.dat -o max");
    printf("Max value is: %d\n", n);

    n = system("\"Corr Ex14-2.exe\" -f matrix.dat -o min");
    printf("Min value is: %d\n", n);



    return(0);
}
