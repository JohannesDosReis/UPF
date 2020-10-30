#include <stdio.h>
//V = R*i
//P = V*i
//P = R*i*i
//P = U2/R
//http://www.comofazerascoisas.com.br/como-calcular-o-resistor-adequado-para-um-led.html
int main(void)
{
    int p, pd, resistor, i;
    printf("Digite a potencia do aparelho: ");
    scanf("%d", &p);
    i = (p/127);
    resistor = (220-127)/ i;
     pd = ((220-127)*(220-127))/resistor;
    printf("Ira precisar de um resistor com %d Ohms e a potencia dissipada por ele sera de %dW\n", resistor, pd);
    return 0;
}
