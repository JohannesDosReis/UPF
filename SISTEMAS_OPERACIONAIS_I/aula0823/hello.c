#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/wait.h>

int main() {
    char *progname = "/bin/ls";
    char *argv[] = { progname, "-l", "-a", NULL };
    char *envp[] = { NULL };
    int ret;

    pid_t pid = fork();
    if (pid < 0) {
        printf("Erro no fork\n");
    }
    if (pid == 0) { // child process
        execve( progname, argv, envp );
    } else 
    {
        // wait( NULL ); 
        // ret will receive the value returned by the child process
        // wait( &ret ); 
        waitpid(pid, &ret, 0); 
        // wait for the child with this pid 
        printf("Filho pid %d terminou com o código %d\n", pid, ret); 
        write( 1, "Hello, World\n", 14);
    }

    exit(0);
}