#include <stdio.h>  // standard input/output -> Entrada e saida padrao
#include <conio.h>  // console extended I/O

int main(void)
{
    float Nota;
    char Resp;

    do
    {
        printf("Digite a nota da prova, entre 0 e 10: ");
        scanf("%f", &Nota);

        putchar('\n');

        while(Nota < 0 || Nota > 10)
        {
            printf("A nota %.1f esta errada!!\n", Nota);
            printf("Digite outra nota: ");
            scanf("%f", &Nota);
        }

        printf("\nDeseja digitar outra nota? [S/N]: ");
        scanf("\n%c", &Resp); // o \n para nao pegar o enter

    }while(Resp == 'S' || Resp == 's');

    return(0);
}
