#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char **CriaMatriz(int Linha, int Coluna)
{
	// ponteiro para ponteiro para inteiro
	char **Temp;
	int i, j;

	// cria o vetor de linhas da matriz
	Temp = malloc(Linha * sizeof(*Temp)); // *Temp -> char* (ponteiro)

	// para cada linha desta matriz...
	for (i = 0; i < Linha; i++)
	{
		// ... cria um vetor de inteiros
		Temp[i] = malloc(Coluna * sizeof(**Temp)); // **Temp --> char
	}

	// inicializa com linha x coluna
	for (i = 0; i < Linha; i++)
	{
		for (j = 0; j < Coluna; j++)
		{
			// numero no formato LLCC
			Temp[i][j] = '0';
		}
	}
	// ponteiro da matriz criada
	return(Temp);
}

void DestroiMatriz(char **Mat, int Linha, int Coluna)
{
	int i;

	// para cada linha desta matriz...
	for (i = 0; i < Linha; i++)
	{
		// ... cria um vetor de inteiros
		free(Mat[i]); // **Temp --> char
	}

	// cria o vetor de linhas da matriz
	free(Mat); // *Temp -> char* (ponteiro)
}

void ExibeMatriz(char **Mat, int Linha, int Coluna)
{
	int i, j;
	printf("Mat[][] = \n");
	putchar(201);
	for(i = 0; i < (Coluna*2)+2; i++)
    {
        putchar(205);
    }
    putchar(187);
    putchar('\n');
	for (i = 0; i < Linha; i++)
	{
	    putchar(186);
		putchar(' ');
		for (j = 0; j < Coluna; j++)
		{
			printf("%c ", Mat[i][j]);
		}
		putchar(' ');
		putchar(186);
		putchar('\n');
	}
	putchar(200);
	for(i = 0; i < (Coluna*2)+2; i++)
    {
        putchar(205);
    }
    putchar(188);
}

void CriarMinas(char **Mat, int Linha, int Coluna)
{
	int qtbomb, lb, cb;
	srand(time(NULL));
	qtbomb = (Linha * Coluna * 15) / 100;
	while (qtbomb)
	{
		lb = rand() % Linha;
		cb = rand() % Coluna;
		if (*(*(Mat + lb) + cb) != '*')
		{
			*(*(Mat + lb) + cb) = '*';
			qtbomb--;
		}
	}
}

void criaNumeros(char **Mat, int Linha, int Coluna)
{
	int i, j, k, l, a, ln, cl;
	for (i = 0; i < Linha; i++)
	{
		for (j = 0; j < Coluna; j++)
		{
			if (Mat[i][j] == '*')
			{
				for (k = -1; k < 2; ++k)
				{
					for (l = -1; l < 2; ++l)
					{
						ln = i + k;
						cl = j + l;
						if (ln >= 0 && cl >= 0 && ln < Linha && cl < Coluna && Mat[ln][cl] != '*')
							*(*(Mat + ln)+cl)+=1 ;
					}
				}
			}
		}
	}
	for (i = 0; i < Linha; i++)
	{
		for (j = 0; j < Coluna; j++)
		{
			if (*(*(Mat + i) + j) == '0')
				*(*(Mat + i) + j) = ' ';
		}
	}

}

int main()
{
	int TAM_L;   // linha
	int TAM_C;   // coluna
	int **Mat;
	printf("Digite um numero de linhas entre 5 e 24: ");
	scanf("%d", &TAM_L);
	while (TAM_L < 5 || TAM_L > 24)
	{
		printf("Valor Invalido\nTente Novamente: ");
		scanf("%d", &TAM_L);
	}
	TAM_C = TAM_L * 2;
	// cria a matriz dinamicamente
	Mat = CriaMatriz(TAM_L, TAM_C);
	//criar minas
	CriarMinas(Mat, TAM_L, TAM_C);
	//criar numeros
	criaNumeros(Mat, TAM_L, TAM_C);
	// exibe esta matriz
	ExibeMatriz(Mat, TAM_L, TAM_C);
	// libera a memoria da matriz
	DestroiMatriz(Mat, TAM_L, TAM_C);
	return 0;
}
