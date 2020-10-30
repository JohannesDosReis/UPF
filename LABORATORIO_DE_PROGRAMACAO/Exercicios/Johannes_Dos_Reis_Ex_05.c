#include <stdio.h>
#include <conio.h>
#include <windows.h>


int main(void)
{
    unsigned char l;
    char tent[6], senha[6]= {'1','2','3','4','5'};
    int cont = 0, i, certo = 0;
    printf("Digite a senha com 5 numeros\n");
    do
    {
        l = getch();
        if(l != 0xE0)
        {
            tent[cont] = l;
            printf("*");
            cont++;
        }
        else
        {
            l = getch();
            if(l == 0x47)
            {
                certo = 1;
                for (i = 0; i < 5; ++i)
                {
                    if (tent[i] != senha[i] || cont > 5)
                    {
                        printf("\n+------------------------------+\n");
                        printf("|  *** YOU SHALL NOT PASS ***  |\n");
                        printf("+------------------------------+\n");
                        cont = 0;
                        certo = 0;
                        Sleep(2500);
                        system("cls");
                        printf("Digite a senha com 5 numeros\n");
                        break;
                    }
                }
            }
        }
    }
    while(certo == 0);
    printf("\n+------------------------------+\n");
    printf("|      Access GRANTED!!        |\n");
    printf("+------------------------------+\n");
    return 0;
}
