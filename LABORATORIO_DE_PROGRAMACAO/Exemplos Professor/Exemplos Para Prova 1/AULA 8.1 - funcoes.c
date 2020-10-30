#include <stdio.h>

/*
 * Faz a leitura de um vetor de inteiros
 */
void LeVetor(int Vetor[], int Tamanho)
{
    for(i = 0; i < Tamanho; i++) /* i = i + 1; */
    {
        printf("Digite o valor do elemento %d de 10: ", i+1);
        scanf("%d", &Vetor[i]);
    }
}

/*
 * Escreve o vetor na tela
 */
void EscreveVetor(int Vetor[], int Tamanho)
{
    putchar('\n');
    putchar('\n');
    printf("Os %d elementos digitados sao:\n", Tamanho);
    putchar('\n');
    for(i = 0; i < Tamanho; i++)
    {
        printf("%d", Vetor[i]);
        if(i < 9) printf(", ");
        else putchar('.');
    }
    putchar('\n');
    putchar('\n');
}

/*
 * Calcula a media do vetor
 */
float MediaVetor(int Vetor[], int Tamanho)
{
    // variavel temporaria para calcular a media
    float med;

    // calculos da media...

    // retorna a media calculada
    return(med);
}

#if 0
// Função padrao
// [tipo] -> valor que retorna (resultado)
//      void (nada), char, int, float, ponteiros...
// [par] --> parametros e valores que utiliza para executar
//      void (nada), char, int, float, ponteiros...
//      int Vetor[], float Vetor[], char String[] ...
[tipo] NomeDaFuncao([par1], [par2], ...)
{


    // retorna o resultado, caso tenha [tipo] de retorno
    return xxx;
}
#endif


int main(void)
{
    int i;
    int Numeros[10];
    float Media;

    // faz a leitura do vetor 'Numeros' com 10 valores.
    LeVetor(Numeros, 10);

    // escreve o vetor na tela
    EscreveVetor(Numeros, 10);

    // calcula a media
    Media = MediaVetor(Numeros, 10);

    return(0);
}
