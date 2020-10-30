#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ERR_NONE 0
#define ERR_OUTPUT 1
#define ERR_INPUT 2
#define ERR_INPUT_WRITE 3
#define ERR_INPUT_PAR 4
#define ERR_PAR_ERROR 5

// // parametroas para criar uma matriz
// struct TMatrix
// {
//     int row;
//     int col;
//     int rand_min;
//     int rand_max;
// };

// /*
//  * Creates an output file with matrix data
//  */
// void GenerateOutputFile(char* Name, struct TMatrix *Par)
// {
//     FILE *pFile;
//     int i, j;

//     pFile = fopen(Name, "w");
//     if(!pFile)
//     {
//         printf("\nCould not save output file \"%s\"!\n\n", Name);
//         exit(ERR_OUTPUT);
//     }

//     fprintf(pFile, "%d %d\n", Par->row, Par->col);

//     for(i = 0; i < Par->row; i++)
//     {
//         for(j = 0; j < Par->col; j++)
//         {
//             int rnd;

//             // gera numero aleatorio
//             rnd = rand() % (Par->rand_max - Par->rand_min + 1) +
//             Par->rand_min;

//             // verifica se tem apenas 1 digito
//             if(rnd < 10) fprintf(pFile, " ");

//             // verifica se tem apenas 2 digitos e o maximo eh maior que 100
//             if(rnd < 100 && Par->rand_max >= 100) fprintf(pFile, " ");

//             // insere o valor
//             fprintf(pFile, "%d ", rnd);
//         }

//         // fim de linha
//         fprintf(pFile, "\n");
//     }

//     fclose(pFile);
// }

float get_float(const char *str) {
  /* First skip non-digit characters */
  /* Special case to handle negative numbers and the `+` sign */
  while (*str && !(isdigit(*str) ||
                   ((*str == '-' || *str == '+') && isdigit(*(str + 1)))))
    str++;

  /* The parse to a double */
  return strtod(str, NULL);
}

float *readFile(char *fileName) {
  FILE *pFile;
  char line[100];
  float values[10];
  pFile = fopen(fileName, "r");
  if (!pFile) {
    // if(pFile == NULL)
    printf("\nInput file \"%s\" could not be read!\n\n", fileName);
    exit(ERR_INPUT);
  }
  fgets(line, 100, pFile);
  while (!feof(pFile)) {
    int i = 0;
    const char *tests[] = {" Demand Fetches",      "  Fraction of total",
                           " Demand Misses",       "  Demand miss rate",
                           "   Compulsory misses", "   Capacity misses",
                           "   Conflict misses",   "   Compulsory fraction",
                           "   Capacity fraction", "   Conflict fraction"};
    // char *p = strchr(line, '=');
    // if(p)
    int str_cmp = strcmp(line, "l2-ucache\n");
    if (str_cmp == 0) {
      while (i < 10) {
        fgets(line, 100, pFile);
        int len = strlen(tests[i]);
        str_cmp = strncmp(line, tests[i], len);
        if (str_cmp == 0) {
          // printf("%f\n", get_float(line));
          values[i] = get_float(line);
          i++;
        }
      }
      fclose(pFile);
      return values;
    }
    fgets(line, 100, pFile);
  }
  fclose(pFile);
}

// /*
//  * Creates an output file with matrix data
//  */
// int ReadMatrixSize(char* FileName, struct TMatrix* Par)
// {
//     // tipo ARQUIVO para usar
//     FILE *pFile;
//     int N;
//     char Linha[50];

//     // Abre um arquivo: nome e modo de opera��o
//     // arquivo data-size.inf em modo de leitura (read)
//     pFile = fopen(FileName, "r");
//     if(!pFile) // if(pFile == NULL)
//     {
//         printf("\nInput file \"%s\" could not be read!\n\n", FileName);
//         exit(ERR_INPUT);
//     }

//     // le uma linha do arquivo
//     fgets(Linha, 50, pFile);
//     while(!feof(pFile))
//     {
//         char *p;

//         // verifica o que tem nessa linha
//         p = strchr(Linha, '=');
//         if(p)
//         {
//             *p = '\0';
//             p++;

//             // converte o restante para a quantidade de linhas
//             if(strncmp(Linha, "row", 3) == 0) Par->row = atoi(p);

//             // converte o restante para a quantidade de colunas
//             if(strncmp(Linha, "col", 3) == 0) Par->col = atoi(p);

//             // converte o restante para a quantidade de linhas
//             if(strncmp(Linha, "rand_min", 8) == 0) Par->rand_min = atoi(p);

//             // converte o restante para a quantidade de linhas
//             if(strncmp(Linha, "rand_max", 8) == 0) Par->rand_max = atoi(p);
//         }

//         // Le a proxima linha
//         fgets(Linha, 50, pFile);
//     }

//     fclose(pFile);

//     printf("Parametros:\n");
//     printf("  Row   : %d\n", Par->row);
//     printf("  Col   : %d\n", Par->col);
//     printf("  Min   : %d\n", Par->rand_min);
//     printf("  Max   : %d\n", Par->rand_max);

//     return(N);
// }

// L1 com 16 KiB+16 KiB, 8-way, 32 bytes/linha, LRU, write back.
// A L2 será unificada, 32 bytes/linha, write back

// d4-7/dineroIV -l1-dsize 16k -l1-isize 16k -l1-dassoc 8 -l1-ibsize 8
// -l1-dbsize 32 -l1-ibsize 32 -l2-usize {{var k}}k -l2-ubsize 32 -l2-uassoc 8
// -l2-urepl f -l2-uccc -informat d < 085.gcc.din

/*
 * Creates an output file with matrix data
 */
int main(int ArgC, char *ArgV[]) {
  int i;
  float values[100][100];
  for () readFile("teste.txt");

  // int N;
  // int i;

  // char FileIn[50];
  // char FileOut[50];

  // struct TMatrix Par;

  // srand(time(0));

  // if(ArgC != 5)
  // {
  //     printf("call %s -i 'input.ini' -o 'output.dat'\n", ArgV[0]);
  //     exit(ERR_INPUT_PAR);
  // }

  // for(i = 1; i <= 3; i += 2)
  // {
  //     // devemos receber um '-'
  //     if(ArgV[i][0] != '-') exit(ERR_PAR_ERROR);

  //     // argumento de entrada?
  //     if(ArgV[i][1] == 'i')
  //     {
  //         // outro parametro?
  //         if(ArgV[i+1][0] == '-') exit(ERR_PAR_ERROR);

  //         // copia o mome do arquivo de entrada
  //         strcpy(FileIn, ArgV[i+1]);
  //     }
  //     // argumento de saida?
  //     else if(ArgV[i][1] == 'o')
  //     {
  //         // outro parametro?
  //         if(ArgV[i+1][0] == '-') exit(ERR_PAR_ERROR);

  //         // copia o mome do arquivo de saida
  //         strcpy(FileOut, ArgV[i+1]);
  //     }
  //     else
  //     {
  //         // outro parametro?
  //         exit(ERR_PAR_ERROR);
  //     }

  // }

  // // parametros
  // printf("Input file : %s\n", FileIn);
  // printf("Output file: %s\n", FileOut);

  // ReadMatrixSize(FileIn, &Par);

  // GenerateOutputFile(FileOut, &Par);

  return (0);
}
