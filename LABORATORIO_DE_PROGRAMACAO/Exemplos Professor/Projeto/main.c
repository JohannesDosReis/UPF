#include <stdio.h>
#include <stdlib.h>

#include "ops.h"

// Define um ponteiro para função do tipo:
// Recebe dois parametros int e retorna int
typedef int *pFuncOp(int,int);

/*
 * Função operacao
 */
int Exec(int A, int B, pFuncOp Op)
{
    int R;

    // chama a funcao normalmente
    R = Op(A, B);

    return(R);
}

int main()
{
    printf("Hello world!\n");
    int X = 10;
    int Y = 2;
    int R;

    printf("X= %d\nY= %d\n\n", X, Y);

    R = Exec(X, Y, Soma);
    printf("Exec(X, Y, Soma) resultou %d\n", R);

    R = Exec(X, Y, Dif);
    printf("Exec(X, Y, Dif) resultou %d\n", R);

    R = Exec(20, 5, Div);
    printf("Exec(20, 5, Div) resultou %d\n", R);

    R = Exec(X, 5, Mult);
    printf("Exec(X, 5, Mult) resultou %d\n", R);


    return 0;
}
