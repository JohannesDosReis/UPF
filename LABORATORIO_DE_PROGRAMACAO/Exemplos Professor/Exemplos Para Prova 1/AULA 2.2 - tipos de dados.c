#include <stdio.h>

int main(void)
{
    // variaveis: armazenam um valor que pode ser variavel
    // toda vez que precisar armazenar um valor ou informacao temporaria

    int Valor;          // numero inteiro, sem casa decimal.
                        // Ex: 10  -4   5   0   -210
    float Temp_kelvin;
    float Temperatura;  // numero real, com casa decimal.
                        // Ex: 10.4 -4  5.0005 0 -0.001
                        // Notacao cientifica: -3.45e3 (-3.45x10³)

    char Inicial;       // uma letra ou simbolo Sempre entre aspas simples
                        // Ex: 'M' 'm' '@' '0' '(' '*' '~' '<' '>' '?' ...

    char Palavra[50];   // uma palavra ou conjunto de letras/simbolos aspas duplas
                        // Ex: "Texto", "ELET" ".E.L.T.E.T." "You Mother&%$&&*"

    // variavel nao armazena unidade!!
    Temperatura = 22.7; // celcius
    Temp_kelvin = Temperatura + 273.16; // kelvin

    Valor = Temperatura; // ??? what happens? Valor vai guardar somente o 22

    return(0);
}




