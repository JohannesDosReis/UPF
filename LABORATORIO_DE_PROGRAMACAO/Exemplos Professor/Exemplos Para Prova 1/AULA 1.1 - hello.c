#include <stdio.h>

int main(void)
{
    int Dia, Mes, Ano;  // variaveis
    int n;

    Dia = 99;
    Mes = 99;
    Ano = 9999;

    printf("Digite a data de hoje: ");
    n = scanf("%d/%d/%d", &Dia, &Mes, &Ano);
    printf("Foram lidos %d valores!\n\n", n);

    printf("Hoje eh %s dia %02d/%02d/%04d\n",
           "Sabado", Dia, Mes, Ano);
    printf("A taxa eh de 50%%\n");

    return(0);
}

