/*
 * Problema do barbeiro dorminhoco.
 */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define N_CADEIRAS 10
#define N_BARBEIROS 2

sem_t barbeiro;
sem_t clientes;
sem_t mutex;

int cadeira_ocupadas = 0;

void *f_barbeiro(void *args) {

  while (1) {
    sem_wait(&clientes); // barbeiro vai ficar dormindo até aparecer um cliente
    // se passar por aqui, significa que o barbeiro acordou
    printf("Cortando os cabelos do clinte!\n");
    // lock no mutex
    sem_wait(&mutex);
    //
    cadeira_ocupadas--;
    // unlock mutex
    sem_post(&mutex);
    sleep(7);
    // barbeiro acabou um corte e ficou livre
    sem_post(&barbeiro);
    printf("Cliente cortou o cabelo e foi embora!\n");
    // demora 7 segundos para cortar os cabelos
  }
  pthread_exit(NULL);
}

void *f_cliente(void *args) {

  if (cadeira_ocupadas <= N_CADEIRAS) {
    printf("Cliente chegou barbearia!\n");
    printf("Cadeiras ocupadas: %d!\n", cadeira_ocupadas);
    // lock no mutex
    sem_wait(&mutex);
    cadeira_ocupadas++;
    // unlock no mutex
    sem_post(&mutex);
    // o cliente acorda o barbeiro se ele estiver dormindo
    sem_post(&clientes);

    // o cliente fica sentado até o barbeiro se liberar
    sem_wait(&barbeiro);

  } else {
    printf("Cliente chegou e saiu da barbearia (Cadeiras lotadas)\n");
  }
}

int main() {
  // Variaveis paraas threads
  pthread_t thr_clientes, thr_barbeiro;

  srand(time(NULL));

  // inicia com N baribeiros
  sem_init(&barbeiro, 0, N_BARBEIROS);
  // inicia com 0 CLIENTES
  sem_init(&clientes, 0, 0);
  // inicializa o mutex
  sem_init(&mutex, 0, 1);

  // cria um barbeiro
  for (int i = 0; i < N_BARBEIROS; i++)
    pthread_create(&thr_barbeiro, NULL, f_barbeiro, NULL);

  while (1) {
    // cria clientes
    pthread_create(&thr_clientes, NULL, f_cliente, NULL);
    // clientes chegam à barbearia em tempo aleatório
    sleep(rand() % 3 + 1);
  }

  return 0;
}