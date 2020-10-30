#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int main(){
    int n = 0;
    while (1){
        printf("%d\n", n++);
        pthread_yueld();        
    }
    return 0;
}