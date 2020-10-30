#include <stdio.h>

char Letra; // 's' '$' '@' 'M' 'L' '[' '?' '-' '<'
int Num;    // 10  -2  5  15400  -4300 ...
float Valor;// 5.3 -0.3 5.9998 10.00 ...

// char  ->  8 bits -> -128 a +127
// int   -> 16 bits -> -32768 a +32767
// int   -> 32 bits -> -2147483648 a +2147483647
// float -> 24+8 b  -> número de -8388608 a +8388607, expoente de -127 a +127

unsigned char Num2; // 8 bits sem sinal: 0 a 255
unsigned int Num3;  // 32 bits sem sinal: 0 a 4294967295
short int Num4;     // 16 bits
unsigned short int Num5; // 16 bits sem sinal
long int Num6;      // 32 bits
unsigned long int Num7;  // 32 bits sem sinal

// short e long não precisam de ser acompanhado de int:
// short int == short
// long int  == long

int main(void)
{

}
