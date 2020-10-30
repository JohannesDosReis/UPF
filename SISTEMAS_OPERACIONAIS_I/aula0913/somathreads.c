#include <pthread.h>
#include <stdio.h>

#define N 100000
#define NTHREADS 4

int vet[N];
long long sum = 0;

pthread_mutex_t x;

void *soma(void *args) {
  long long t = (long long)args;

  int tam = N / NTHREADS;
  int resto = N % NTHREADS;

  // int inicio;
  // int fim = -1;

  // if (t < resto) {
  //   inicio = t * tam + t;
  //   fim += (t + 1) * tam - 1 + (t + 1);
  // } else {
  //   inicio = t * tam + resto;
  //   fim += (t + 1) * tam - 1;
  // }

  int inicio = t * tam;
  int fim = (t + 1 != NTHREADS) ? inicio + tam - 1 : N - 1;

  long long somapart = 0;
  for (int i = inicio; i <= fim; i++) {
    somapart += vet[i];
  }

  pthread_mutex_lock(&x);
  sum += somapart;
  pthread_mutex_unlock(&x);

  printf("Thread: %lld | Inicio: %lld | Fim: %lld | Soma da parte: %lld\n", t,
         inicio, fim, somapart);
  pthread_exit(NULL);
}

int main() {
  FILE *in = fopen("numeros.in", "r");
  int n = 0;
  pthread_mutex_init(&x, NULL);

  while (n < N && fscanf(in, "%d", &vet[n]) == 1)
    n++;
  fclose(in);

  pthread_t th[NTHREADS];
  for (long long i = 0; i < NTHREADS; i++) {
    pthread_create(&th[i], NULL, soma, (void *)i);
  }

  for (int i = 0; i < NTHREADS; i++) {
    pthread_join(th[i], NULL);
  }

  pthread_mutex_destroy(&x);
  // for (int i = 0; i < N; i++) {
  //   sum += vet[i];
  // }

  printf("Leu %d valores\nSoma: %lld\n", n, sum);
  return 0;
}