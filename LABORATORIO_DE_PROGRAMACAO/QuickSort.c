#define count 500

#include <stdio.h>

void Quick (int vetor[count], int inicio, int fim);


int main()
{
   int vetor[count];
   int i;
   srand(time(NULL));
   for (i = 0; i < count; ++i)
   {
      vetor[i] = rand() % 100;
   }
   printf("Vetor Desornedado\n");
   for (i = 0; i < count; ++i)
   {
      printf("%d\n", vetor[i]);
   }
   Quick(vetor, 0, count);
   printf("Vetor Ordenado\n");
   for (i = 0; i < count; ++i)
   {
      printf("%d\n", vetor[i]);
   }
   return 0;
}

void Quick(int vetor[count], int inicio, int fim){

   int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];

   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);

}
