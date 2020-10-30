#include <stdio.h>
#include <stdlib.h>

#define ERR_NONE        0
#define ERR_OUTPUT      1
#define ERR_INPUT       2
#define ERR_INPUT_WRITE 3
#define ERR_INPUT_PAR   4
#define ERR_PAR_ERROR   5
#define ERR_INVALID_OP  6

// parametroas da matriz
struct TMatrix
{
	int row;
	int col;
	int **values;
};

/*
 * Creates an output file with matrix data
 */
void ReadMatrix(char* FileName, struct TMatrix *Par)
{
    // tipo ARQUIVO para usar
	FILE *pFile;
	int i, j;

    // Abre um arquivo: nome e modo de operação
    // arquivo data-size.inf em modo de leitura (read)
	pFile = fopen(FileName, "rb");
    if(!pFile) // if(pFile == NULL)
    {
    	printf("\nInput file \"%s\" could not be read!\n\n", FileName);
    	exit(ERR_INPUT);
    }

    // le o valor de linha e coluna do arquivo
    fread(&Par->row, sizeof(int),1,pFile);
    fread(&Par->col, sizeof(int),1,pFile);

    // cria o vetor de linhas
    Par->values = malloc(Par->row * sizeof(*Par->values));

    for(i = 0; i < Par->row; i++)
    {
        // cria o vetor de colunas
    	Par->values[i] = malloc(Par->col * sizeof(**Par->values));

    	for(j = 0; j < Par->col; j++)
    	{
    		int val;
    		fread(&val, sizeof(int),1,pFile);

    		Par->values[i][j] = val;
    	}
    }

    fclose(pFile);
}

/*
 * Creates an output file with matrix data
 */
void KillMatrix(struct TMatrix *Par)
{
	int i;

	for(i = 0; i < Par->row; i++)
	{
		free(Par->values[i]);
	}

	free(Par->values);
}

/*
 * Procura o maior e menor valor da matriz, de acordo com a operacao
 */
int MaxMinMatrix(struct TMatrix *Par, char Op)
{
	int pos_i = 0, pos_j = 0;
	int i, j;

	for(i = 0; i < Par->row; i++)
	{
		for(j = 0; j < Par->col; j++)
		{
			if((Op == '+' && Par->values[i][j] > Par->values[pos_i][pos_j]) ||
				(Op == '-' && Par->values[i][j] < Par->values[pos_i][pos_j]))
			{
				pos_i = i;
				pos_j = j;
			}
		}
	}

    // retorna o valor da posicao encontrada
	return(Par->values[pos_i][pos_j]);
}

/*
 * Average of all values
 */
float AverageMatrix(struct TMatrix *Par)
{
	float Avg = 0;
	int i, j;

	for(i = 0; i < Par->row; i++)
	{
		for(j = 0; j < Par->col; j++)
		{
			Avg += Par->values[i][j];
		}
	}

	Avg = Avg / (float)(Par->row * Par->col);

	return(Avg);
}

/*
 * Display matrix
 */
void DisplayMatrix(struct TMatrix *Par)
{
	int pos_i = 0, pos_j = 0;
	int i, j;

	printf("\nMatrix:\n");

	printf("    ");
	for(j = 0; j < Par->col; j++) { if(j) putchar(' '); printf("%3d", j+1); }
		putchar('\n');

	for(i = 0; i < Par->row; i++)
	{
		printf("%2d| ", i+1);
		for(j = 0; j < Par->col; j++)
		{
			if(j) putchar(' ');
			printf("%3d", Par->values[i][j]);
		}
		putchar('\n');
	}
}

/*
 * Creates an output file with matrix data
 */
int main(int ArgC, char *ArgV[])
{
	char Op;
	int i;
	struct TMatrix Par;
	int Ret = 0;
	float Avg;

	char FileIn[50];

	if(ArgC != 5)
	{
		printf("call %s -f 'matrix.dat' -o 'operation'\n", ArgV[0]);
		exit(ERR_INPUT_PAR);
	}

	for(i = 1; i <= 3; i += 2)
	{
        // devemos receber um '-'
		if(ArgV[i][0] != '-') exit(ERR_PAR_ERROR);

        // argumento de entrada?
		if(ArgV[i][1] == 'f')
		{
            // outro parametro?
			if(ArgV[i+1][0] == '-') exit(ERR_PAR_ERROR);

            // copia o mome do arquivo de entrada
			strcpy(FileIn, ArgV[i+1]);
		}
        // argumento de saida?
		else if(ArgV[i][1] == 'o')
		{
            // outro parametro?
			if(ArgV[i+1][0] == '-') exit(ERR_PAR_ERROR);

            // verifica qual operação a ser feita
			if(strncmp(ArgV[i+1], "display", 7) == 0) Op = 'd';
			else if(strncmp(ArgV[i+1], "average", 7) == 0) Op = 'a';
			else if(strncmp(ArgV[i+1], "max", 3) == 0) Op = '+';
			else if(strncmp(ArgV[i+1], "min", 3) == 0) Op = '-';
			else exit(ERR_INVALID_OP);
		}
		else
		{
            // outro parametro?
			exit(ERR_PAR_ERROR);
		}

	}

    // read size
	ReadMatrix(FileIn, &Par);

	switch(Op)
	{
		case 'd':
		DisplayMatrix(&Par);
		break;

		case 'a':
		Avg = AverageMatrix(&Par);
		Ret = (int)(Avg*100);
		break;

		case '+':
		case '-':
		Ret = MaxMinMatrix(&Par, Op);
		break;
	}

	KillMatrix(&Par);
	return(Ret);
}


