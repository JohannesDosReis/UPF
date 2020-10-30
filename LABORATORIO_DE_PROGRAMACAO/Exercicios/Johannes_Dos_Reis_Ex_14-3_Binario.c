#include <stdio.h>
#include <stdlib.h>

/*
 * main
 */
int main(void)
{
    int n;
    
    printf("Running 14-1:\n");
    n = system("\"Johannes_Dos_Reis_Ex_14-1_Binario.exe\" -i model.ini -o matrix.dat");

    printf("\nRunning 14-2:\n");
    system("\"Johannes_Dos_Reis_Ex_14-2_Binario.exe\" -f matrix.dat -o display");
    putchar('\n');

    n = system("\"Johannes_Dos_Reis_Ex_14-2_Binario.exe\" -f matrix.dat -o average");
    printf("Average is  : %.2f\n", (float)n * 0.01);


    n = system("\"Johannes_Dos_Reis_Ex_14-2_Binario.exe\" -f matrix.dat -o max");
    printf("Max value is: %d\n", n);


    n = system("\"Johannes_Dos_Reis_Ex_14-2_Binario.exe\" -f matrix.dat -o min");
    printf("Min value is: %d\n", n);



    system("pause");
    return(0);
}
