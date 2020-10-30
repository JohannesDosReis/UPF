#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Multiplicacao
 */
int Mult(int A, int B)
{
    // 1*B == B
    if(A == 1)
        return(B);

    // B + (A-1)*B
    return(B + Mult(A-1, B));
}

/*
 * Divisao
 */
int Div(int A, int B)
{
    // impossibru!
    if(A < B)
        return(0);

    // 1 + (A-B)/B
    return(1 + Div(A-B, B));
}

/*
 * Modulo
 */
int Mod(int A, int B)
{
    // impossibru!
    if(A < B)
        return(A);

    // (A-B)%B
    return(Mod(A-B, B));
}

/*
 * main
 */
int main(void)
{
    int A, B;
    int M, D, R;

    printf("Escolha um numero A: ");
    scanf("%d", &A);

    printf("Escolha um numero B: ");
    scanf("%d", &B);

    M = Mult(A, B);
    D = Div(A, B);
    R = Mod(A, B);

    if(M != A*B) printf("\n** Error in MULT function! **\n");
    if(D != A/B) printf("\n** Error in DIV function! **\n");
    if(R != A%B) printf("\n** Error in MOD function! **\n");

    putchar('\n');
    printf("  A   B |    %c  %c  %c\n", 158, 246, 169);
    printf("%3d %3d | %4d %2d %2d\n", A, B, M, D, R);

    return(0);
}
