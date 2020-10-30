#include <stdio.h>  // standard input/output -> Entrada e saida padrao
#include <conio.h>  // console extended I/O

int main(void)
{
    int condicao;

    // sintaxe:
    // if(condicao)

    // condicao:
    // Qualquer expressao ou numero que seja:
    //  0= falso ou 1= verdadeiro
    // A > B
    // Key == 12345
    // Clima == CHUVA || Preguica

    if(Clima == CHUVA || Preguica)
    {
        // comandos se for verdadeiro
        printf("Condicao verdadeira!\n");

        // verifica o nivel de preguica
        if(Preguica >= 50) //  50%
        {
            // ja era a aula!
            UPF.abort();
        }
        else
        {
            // vou de carro
            UPF.go(BY_CAR);
        }
    }
    else
    {
        // comandos se for falso
        printf("Condicao falsa/invalida!\n");

        // vou de bicicleta
        UPF.go(BY_BICYCLE);
    }


    // simples:
    if(condicao)
    {

    }

    // if e else
    if(condicao)
    {

    }
    else
    {

    }

    // composto / cascata
    if(condicao_1)
    {
        // executa se condicao_1 for verdadeira
    }
    else if(condicao_2) // if(!condicao_1 && condicao_2)
    {
        // executa se condicao_1 for falsa (else) e condicao_2 verdadeira
    }
    else if(condicao_3)
    {
        // if(!condicao_1 && !condicao_2 && condicao_3)
    }
    else
    {
        // executa se todas foram falsas
    }

    T = temperatura(LM_35);

    if(T < 0) printf("Congelou!\n");
    else if(T > 100) printf("Evaporou!\n");
    else printf("Ainda esta liquido\n");

}
