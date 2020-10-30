#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <stdio.h>
#include <pthread.h>

void *threadC(void *arg){
    printf("C1\n");
    pthread_exit(arg);
}
void *threadD(void *arg){
    printf("D1\n");
    pthread_exit(arg);
}

void *threadB(void *arg)
{
    printf("B1\n");
    pthread_t thread_idD;
    pthread_create(&thread_idD, NULL, threadD, NULL);
    printf("B2\n");
    pthread_join(thread_idD, NULL);
    printf("B3\n");
    pthread_exit(arg);
}


int main(){
    printf("A1\n");
    pthread_t thread_idB;
    pthread_create(&thread_idB, NULL, threadB, NULL);
    printf("A2\n");
    pthread_t thread_idC;
    pthread_create(&thread_idC, NULL, threadC, NULL);
    pthread_join(thread_idC, NULL);
    printf("A3\n");
    pthread_join(thread_idB, NULL);
    printf("A4\n");
    exit(0);    
}