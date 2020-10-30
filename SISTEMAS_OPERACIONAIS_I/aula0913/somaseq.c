#include <stdio.h>

#define N 100000

int vet[N];
long long sum = 0;

int main() {
  FILE *in = fopen("numeros.in", "r");
  int n = 0;

  while (fscanf(in, "%d", &vet[n]) == 1)
    n++;
  fclose(in);

  for (int i = 0; i < N; i++) {
    sum += vet[i];
  }

  printf("Leu %d valores\nSoma: %lld\n", n, sum);
  return 0;
}