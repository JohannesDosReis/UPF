#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int i = 1;
	argc--;
	if(argc%2 != 0)
	{
		printf("Parametro Invalido\n");
		exit(1);
	}
	printf("Executando: \"%s\" com %d parametros:\n", argv[0], argc);
	while (argc)
	{
		if (strcmp(argv[i], "-d") == 0)
		{
			while (*(argv[i+1]) != NULL)
			{
				if (!isdigit(*(argv[i + 1])) && *(argv[i + 1]) != '-')
				{
					printf("Valor Invalido\n");
					exit(1);
				}
				argv[i + 1]++;
			}
		}
		else if (strcmp(argv[i], "-u") == 0)
		{
			while (*(argv[i + 1]) != NULL)
			{
				if (!isdigit(*(argv[i + 1])))
				{
					printf("Valor Invalido\n");
					exit(1);
				}
				argv[i + 1]++;
			}
		}
		else if (strcmp(argv[i], "-f") == 0)
		{
			while (*(argv[i + 1]) != NULL)
			{
				if (!isdigit(*(argv[i + 1])) && *(argv[i + 1]) != '.' && *(argv[i + 1]) != '-')
				{
					printf("Valor Invalido\n");
					exit(1);
				}
				argv[i + 1]++;
			}
		}
		else if (strcmp(argv[i], "-s") == 0)
		{

		}
		else
		{
			printf("Parametro Invalido!\n");
			exit(1);
		}
		i+=2;
		argc-=2;
	}
	printf("Tudo Certo");
	return 0;
}
/*Exercicio 13:				\\LCI-3-04

Faça um programa que receba varios parametros como argumento.
Os parametros devem ser:
	-d para inteiro: -d 14 -d -55
	-u para inteiro sem sinal: -u 2 -u 1200
	-f para float: -f 10.66 -f 22
	-s para string: -s "Nome" -s Fighter

	atoi, atof, atol ...

O programa deve verificar se os argumentos estao corretos, ou seja:
	O tipo de acordo com o parametro -x
	Se a ordem esta correta, -x sem parametro ou parametro sem -x

	No inicio deve escrever na tela quantos parametros foram repassados.*/