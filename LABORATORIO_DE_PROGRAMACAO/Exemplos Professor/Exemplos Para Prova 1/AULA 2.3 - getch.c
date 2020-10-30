#include <stdio.h>  // standard input/output -> Entrada e saida padrao
#include <conio.h>  // console extended I/O

int main(void)
{
    unsigned char L1, L2 ...
    int Key, V1, V2 ...
    unsigned char C;

    // considera sem ser tecla de comando
    C = 0x00;

    // pede-se para digitar uma letra
    printf("Digite uma letra: ");

    // faz a leitura desta letra
    L1 = getch(); printf("*");
    L2 = getch(); printf("*");
    L3 = getch(); printf("*");
    L4 = getch(); printf("*");
    L5 = getch(); printf("*");

    V1 = L1 - '0'; // converte de letra para valor decimal, 0-9
    V2 = L2 - '0'; // segundo digito..

    // agrupa todos os digitos, de acordo com sua potencia
    Key = V1*10000 + V2*1000 + ...

    // se a letra for um comando (0xE0), obtem outra letra
    if(L1 == 0xE0)
    {
        // guarda o valor do comando
        C = L1;

        // le a proxima letra (automaticamente)
        L1 = getch();
    }

    // escreve na tela a letra e o comando
    printf("%c (0x%02X) CMD= 0x%02X\n", L1, L1, C);
}
