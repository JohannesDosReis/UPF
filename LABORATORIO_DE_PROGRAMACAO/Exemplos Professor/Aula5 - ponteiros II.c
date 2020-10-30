#include <stdio.h>
#include <conio.h>

void Foo1(int N)
{
    printf("\nFoo-1:\n");
    printf(" N= %d\n", N);
    N += 10;
    printf(" N= %d\n", N);
}

void Foo2(int *N)
{
    printf("\nFoo-2:\n");
    printf(" N= %d\n", *N);
    *N += 10;
    printf(" N= %d\n", *N);
}

int main(void)
{
    int B;
    int A;

    A = 5;
    B = 30;
    printf("Inicialmente A= %d\n\n", A);

    // executa funcao 1
    Foo1(A);
    printf("Depois de Foo-1, A= %d\n\n", A);

    // executa funcao 2
    Foo2(&A);
    printf("Depois de Foo-2, A= %d\n\n", A);

    return(0);
}
