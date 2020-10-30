#include <stdio.h>
#include <stdlib.h>

int Mult(int A, int B);
int Div(int A, int B);
int Mod(int A, int B);

int main(void)
{
	int A, B, x;
	printf("Digite um numero inteiro: ");
	scanf("%d", &A);
	printf("Digite outro numero inteiro: ");
	scanf("%d", &B);
	printf("Multiplicacao = %d\n", Mult(A, B));
	if (A < B)
	{
		x = A;
		A = B;
		B = x;
	}
	if (B == 0)
	{
		printf("Nao e possivel dividir por zero\n");
		exit(1);
	}
	
	printf("Divisao = %d\n", Div(A, B));
	printf("Resto do maior pelo menor = %d\n", Mod(A, B));
	return 0;
}


int Mult(int A, int B)
{
	if (B == 0)
		return 0;
	else
		return A + Mult(A, B - 1);
}



int Div(int A, int B)
{
	if (A < B)
		return 0;
	else
		return 1 + Div(A - B, B);
}


int Mod(int A, int B)
{
	if (A < B)
		return A;
	else
		Mod(A - B, B);
}


/*
Exercicio 12: Multiply		\\LCI-3-04

Obtenha o valor de dois numeros inteiros A e B. feito

Faça a multiplicação de A por B de forma recursiva utilizando apenas somas. feito

Faça o calculo da divisao e
resto do maior pelo menor, de forma recursiva.

Funções:

int Mult(int A, int B);
int Div(int A, int B);
int Mod(int A, int B);
*/


