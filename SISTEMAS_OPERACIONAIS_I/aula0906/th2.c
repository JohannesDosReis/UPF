#include <stdio.h>
#include <pthread.h>

volatile int count = 0;
pthread_mutex_t x;

void *incrementa(void *args){
    for (int i = 0; i < *(int *)args; i++){
        pthread_mutex_lock(&x);
        count++;
        pthread_mutex_unlock(&x);
    }
    pthread_exit(args);
}


int main() {
    pthread_t th1, th2,th3;
    pthread_mutex_init(&x, NULL);
    int n = 100000;
    pthread_create(&th1, NULL, incrementa, &n);
    pthread_create(&th2, NULL, incrementa, &n);
    pthread_create(&th3, NULL, incrementa, &n);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    
    printf("%d\n", count);
    
    pthread_mutex_destroy(&x);
    
    return 0;
}
