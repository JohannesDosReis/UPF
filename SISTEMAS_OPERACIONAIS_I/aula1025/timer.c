#include <stdio.h>
#include <unistd.h>

int main(){
    int n = 0;
    while (1){
        printf("%d\n", n++);
        // Micro seconds
        usleep(1000000); // 1 second
    }
    return 0;
}