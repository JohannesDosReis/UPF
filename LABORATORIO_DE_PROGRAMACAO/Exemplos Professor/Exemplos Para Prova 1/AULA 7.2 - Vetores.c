#include <stdio.h>

int main(void)
{
    int i;
    int Numeros[10];

    for(i = 0; i <= 9; i++) /* i = i + 1; */
    {
        printf("Digite o valor do elemento %d de 10: ", i+1);
        scanf("%d", &Numeros[i]);
    }
    putchar('\n');
    putchar('\n');
    printf("Os 10 elementos digitados sao:\n");
    putchar('\n');
    for(i = 0; i <= 9; i++)
    {
        printf("%d", Numeros[i]);
        if(i < 9) printf(", ");
        else putchar('.');
    }
    putchar('\n');
    putchar('\n');

    return(0);
}
