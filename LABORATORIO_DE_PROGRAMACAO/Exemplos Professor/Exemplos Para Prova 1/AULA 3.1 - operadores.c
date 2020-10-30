#include <stdio.h>  // standard input/output -> Entrada e saida padrao
#include <conio.h>  // console extended I/O

int main(void)
{
    int A, B, C;

    A = 7; // somente um = significa atribuir
    B = 2;  // definir o valor de uma variavel
    C = 0;

    printf("Valores iniciais: A= %d e B= %d\n", A, B);

    // operadores:
    //  + soma
    //  - subtração
    //  * multiplicação
    //  / divisao
    //  % modulo da divisao --> resto

    printf("A + B = %d\n", A+B); // podemos fazer contas
    printf("A - B = %d\n", A-B); // no proprio comando
    printf("A * B = %d\n", A*B); // printf!
    printf("A / B = %d\n", A/B);
    printf("A %% B = %d\n", A%B);   // resto!

    putchar('\n');

    printf("A > B = %d\n", A>B);    // maior que
    printf("A < B = %d\n", A<B);    // menor que
    printf("A >= B = %d\n", A>=B);  // maior igual
    printf("A <= B = %d\n", A<=B);  // menor igual
    printf("A == B = %d\n", A==B);  // igual a
    printf("A != B = %d\n", A!=B);  // diferente de

    putchar('\n');

    // && --> operacao E/AND
    // || --> operacao OU/OR
    // !  --> operacao INV/NOT

    printf("A > B || A > C = %d\n", (A>B)||(A>C));
    printf("A == B && A > C = %d\n", A == B && A > C);
    printf("!(A != B || A < C) = %d\n", !(A != B || A < C));

    putchar('\n');
    printf("A & B  = %d\n", A&B);   // AND bit a bit
    printf("A && B = %d\n", A&&B);  // AND de valores
    printf("A | C  = %d\n", A|C);   // OR bit a bit
    printf("A || C = %d\n", A||C);  // OR de valores

    return(0);
}
