#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    int ret;
    printf("A1\n");
    pid_t pidB = fork();
    if (pidB == 0) {
        printf("B1\n");
        pid_t pidD = fork();
        if (pidD == 0) {
            printf("D1\n");
        } else {
            printf("B2\n");
            waitpid(pidD, NULL, 0);
            printf("B3\n");
        }
    } else {
        printf("A2\n");
        pid_t pidC = fork();
        if (pidC == 0) {
            printf("C1\n");
        } else {
            waitpid(pidC, NULL, 0);
            printf("A3\n");
            waitpid(pidB, NULL, 0);
            printf("A4\n");
        }
    }
    exit(0);
}