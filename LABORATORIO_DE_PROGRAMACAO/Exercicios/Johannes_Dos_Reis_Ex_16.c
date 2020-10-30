#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char **CreateMatrix(int *lin, int *col)
{
	char **Mat;
	int i;
	printf("Digite o tamanho da matriz\n");
	do
	{
		printf("Linhas: ");
		scanf("%d", lin);
	} while (*lin < 10 || *lin > 25);
	do
	{
		printf("Colunas: ");
		scanf("%d", col);
	} while (*col < 10 || *col > 75);
	Mat = malloc(*lin * sizeof(*Mat));
	for (i = 0; i < *lin; i++)
	{
		Mat[i] = malloc(*col * sizeof(**Mat));
	}
	return Mat;
}

void RemoveMatrix(char **Mat, int lin)
{
	int i;
	for (i = 0; i < lin; i++)
	{
		free(Mat[i]);
	}
	free(Mat);
}

void CreateWord(char **Mat, int lin, int col)
{
	char word[40];
	char dir;
	int size, l, c, count = 5, i, op = 0, j;
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			Mat[i][j] = (rand() % 26) + 97;
		}
	}
	do
	{
		printf("Digite uma palavra: ");
		getchar();
		gets(word);
		tolower(word);
		size = strlen(word);
		do
		{
			printf("Digite qual linha: ");
			scanf("%d", &l);
		} while (l > lin);
		do
		{
			printf("Digite qual coluna: ");
			scanf("%d", &c);
		} while (c > col);
		do
		{
			printf("Digite em qual Direcao: ");
			getchar();
			scanf("%c", &dir);
			tolower(&dir);
		} while (dir != 'v' && dir != 'h' && dir != 'd');
		if ((dir == 'v' || dir == 'd') && l + size > lin)
		{
			printf("Nao e possivel escrever nessa posicao\n");
			continue;
		}
		else if ((dir == 'h' || dir ==  'd') && c + size > col)
		{
			printf("Nao e possivel escrever nessa posicao\n");
			continue;
		}
		for (i = 0; i < size; i++)
		{
			Mat[l][c] = word[i];
			if (dir == 'v')
				l++;
			if (dir == 'h')
				c++;
			if (dir == 'd')
			{
				l++;
				c++;
			}
		}
		count--;
		if (count <= 0)
		{
			printf("Digite 1 para adicionar mais\nDigite 0 para sair\n");
			scanf("%d", &op);
		}
	} while (count > 0 || op != 0);
}

void showMatrix(char **Mat, int lin, int col)
{
	int i, j;
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%c", Mat[i][j]);
			if (col < 40)
				printf(" ");
		}
		printf("\n");
	}
}

int main()
{
	char **Mat;
	int lin, col;
	srand(time(NULL));
	Mat = CreateMatrix(&lin, &col);
	CreateWord(Mat, lin, col);
	showMatrix(Mat, lin, col);
	RemoveMatrix(Mat, lin);
	system("pause");
	return 0;
}
/*
Exercício 16: Word Hunter!		\\LCI-3-04

Neste exercicio vamos criar uma matriz de caça-palavras. Utilize uma matriz de no minimo 10x10 e no maximo 75x25
letras. Crie a matriz dinamicamente.

Se a matriz tiver menos de 40 colunas, escreva cada letra separada por um ' '.
Caso ela tenha mais de 40, deixe este espaço fora.

Peça ao usuário que digite:
	? uma palavra sem espaços (converter para minúsculo)
	? uma linha e coluna onde inserir esta palavra
	? uma letra 'v', 'h' ou 'd' simbolizando vertical, horizontal ou 	  diagonal.

Insira a palavra, letra por letra, na matriz de caracteres. Verifique o tamanho da palavra e caso ela possa ser inserida!
Caso não possa, peça ao usuario que tenta outra.
	? Ex: “cafeptospirose” possui 14 letras e nao pode ser inserida na posicao (20,18,v)

Insira no minimo 5 palavras nesta matriz. Nao será necessário verificar se as palavras se cruzam. Acima de 5,
pergunte ao usuario se deseja inserir mais.

Complete a matriz com caracteres aleatórios de 'a' a 'z'.

Deve ser implementado em funçoes:
? Obter o tamanho da matriz e retornar o ponteiro da matriz alocada;
? Obter uma palavra, posição e sentido;
? Desenhar a matriz na tela.
*/
