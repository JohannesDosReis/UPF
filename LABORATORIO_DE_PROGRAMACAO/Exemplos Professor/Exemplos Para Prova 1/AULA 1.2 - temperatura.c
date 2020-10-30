#include <stdio.h>

int main(void)
{
    float Temp;   // temperatura
    char Unid;    // unidade da temperatura

    printf("Digite a temperatura ambiente: ");
    scanf("%f%c", &Temp, &Unid); // xxU 22C, 64F, 315K

    if(Unid == 'C' || Unid == 'c')
    {
        // converte de grau celcius pra kelvin
        Temp = Temp + 273.16;
        Unid = 'K';
    }

    printf("A temperatura esta em %.2f\370%c.\n",
           Temp, Unid);

    return(0);
}

