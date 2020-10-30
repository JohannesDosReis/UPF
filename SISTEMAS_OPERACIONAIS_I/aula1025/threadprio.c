#include <stdio.h>
#include <unistd.h>
#include <sched.h>


struct sched_param

int main(){
    int n = 0;
    while (1){
        printf("%d\n", n++);
        sched_yield();
    }
    return 0;
}