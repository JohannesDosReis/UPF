#include <stdio.h>

int main(int argc, char **argv, char **envp) { // envp mostra as variaveis de ambiente 
    printf("ARGC=%d\n\n", argc);
    int i;
    for (i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    printf("\n\n");
    for (i = 0; envp[i] != NULL; i++) {
        printf("envp[%d]: %s\n", i, envp[i]);
    }
    return 0;
}