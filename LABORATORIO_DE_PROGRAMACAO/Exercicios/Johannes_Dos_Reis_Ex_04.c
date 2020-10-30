#include <stdio.h>

int main(void)
{
    int i, t;
    float temp, p;
    char pch;
    printf("Digite uma posição para a chave entre 0 e 5: ");
    do
    {
        scanf("\n%c", &pch);
        if(pch < '0' || pch > '5') printf("\nPosicao invalida tente novamente!\n");
    }while(pch < '0' || pch > '5');
    t = pch - '0';
    p = t/5.0;
    printf("O aquecedor na posicao %c a %02.0f%% e dissipando %03.0f Watts ", pch, p*100, 750*p);
    printf("[");
    for(i = 0; i < 10; i++)
    {
        if(i <= p*10)
        {
            printf("%c", 219);
        }else
        {
            printf(" ");
        }
    }
    printf("]\nQual a temperatura externa? ");
    scanf("%f", &temp);
    temp+= ((750*p)*0.0125);
    printf("\nCom o aquecedor, a temperatura e de %02.1f%cC\n", temp, 248);
}
