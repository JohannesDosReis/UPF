#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void show(int op);

int main(void)
{
	int op = 0;
	unsigned char c;
	char org[20], dest[20], comm[70];
	show(op);
	do
	{
		do
		{
			c = _getch();
			if (c == 0xE0)
			{
				c = _getch();
				if (c == 0x48  && op > 0)//up
					op--;
				else if (c == 0x50 && op < 5) //down
					op++;
			}
			show(op);
		} while (c != 0x0D);
		switch(op)
		{
			case 0:	
			{
				printf("\nDigite o arquivo origem: ");
				gets(org);
				printf("Digite o arquivo destino: ");
				gets(dest);
				sprintf(comm,"Johannes_Dos_Reis_Ex_14_generate.exe -i %s -o %s", org, dest);
				system(comm);
			}
			break;
			case 1: 
			{
				sprintf(comm,"Johannes_Dos_Reis_Ex_14_process.exe -f  %s -o average", dest);
				printf("Media = %.2f", (float)(system(comm)/100));
			}
				break;
			case 2: 
			{
				sprintf(comm,"Johannes_Dos_Reis_Ex_14_process.exe -f  %s -o max", dest);
				printf("Maximo = %d",system(comm));
			}
				break;
			case 3: 
			{
				sprintf(comm,"Johannes_Dos_Reis_Ex_14_process.exe -f  %s -o min", dest);
				printf("Minimo =  %d",system(comm));
			}
				break;
			case 4: 
			{
				sprintf(comm,"Johannes_Dos_Reis_Ex_14_process.exe -f  %s -o display", dest);
				system(comm);
			}
				break;
		}
	}while(op != 5);
	printf("\n");
	return 0;
}

void show(int op)
{
	int i;
	char Frases[6][28] = { "Gerar Matriz", "Media Matriz", "Maximo Matriz", "Mostrar Minimo", "Mostrar Matriz", "Sair" };
	system("cls");
	printf("Escolha uma opcao\n");
	for (i = 0; i < 6; i++)
	{
		if (i == op) printf("%c", 26);
		else printf(" ");
		printf(" %s\n", Frases[i]);
	}
}

/*Exercicio 14:

Faça tres programas que:
1) generate.exe receba como parametro um nome de arquivo -i 'model.ini'
-o 'matriz.dat' e crie uma matriz de acordo com os parametros neste
arquivo.
2) process.exe recebe como parametro -f 'matriz.dat' e -o 'operation'
operation pode ser: 'average', 'max', 'min', 'display'. As operações
exceto a 'display' devem retornar o valor via return(). A media pode
ser retornada com 2 casas decimais em inteiro return(Media * 100)
3) matriz.exe programa principal que faz a chamada para os outros dois

model.ini:
row=10
col=20
rand_min=10
rand_max=50

matriz.dat:
10 20
x x x x x x x x
x x x x x x x x
x x x x x x x x
x x x x x x x x
x x x x x x x x ...*/
