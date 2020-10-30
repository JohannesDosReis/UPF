#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    printf("Antes do fork\n");
    pid = fork();
    if (pid > 0) { // father pid is > 0
        printf("Depois do fork no pai (pid do filho=%d)\n", pid);
    } else { // child retun 0
        printf("Depois do fork no filho\n");
    }

    exit(0);
}