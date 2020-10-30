#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *filho(void *args) {
    printf("%d\n", __LINE__);
    pthread_exit(NULL);
}


int main() {
    pthread_t f1, f2; 
    printf("%d\n", __LINE__);
    printf("%d\n", __LINE__);
    pthread_create(&f1, NULL, filho, NULL);
    printf("%d\n", __LINE__);
    pthread_create(&f2, NULL, filho, NULL);
    printf("%d\n", __LINE__);
    pthread_join(f1, NULL);
    printf("%d\n", __LINE__);
    pthread_join(f2, NULL);
    printf("%d\n", __LINE__);
    return 0;
}





// cdecl 
// explain function