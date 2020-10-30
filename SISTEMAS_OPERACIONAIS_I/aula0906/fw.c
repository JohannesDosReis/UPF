#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * volatile
 * intrução para o compilador não otimizar a variavel em registrador
 * **todos os acessos são na memória princial
 **/
/** 
 * register
 * instrução para o compilador otimizar a variavel em registrador
 * sempre tentar executar e registrador
 **/

volatile int count = 0;

int main() {
    pid_t pid;
    pid = fork();
    count++;
    if (pid > 0) 
    {
        wait(NULL);
        printf("%d\n", count);
    }
    
    return 0;
}


