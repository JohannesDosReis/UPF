#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *filho(void *args) {
    printf("F\n");
    // ponteiro para o valor de retorno
    pthread_exit(NULL);
}

int main() {
    printf("A\n");
    printf("B\n");
    pthread_t f1; 
    // Endereço da variavel para o id da thread, atributo (prioridade, etc...), nome da função filho, paremtros para a função
    pthread_create(&f1, NULL, filho, NULL);
    printf("C\n");
    // Identificar, endereço para retorno
    pthread_join(f1, NULL);
    return 0;
}





// cdecl 
// explain function