#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>

int main() {
    char *progname = "/bin/ls";
    char *argv[] = { progname, "-l", "-a", NULL };
    char *envp[] = { NULL };
    
    syscall( SYS_execve, progname, argv, envp );
    syscall(SYS_write, 1, "Hello, World\n", 14);

    // Minha pesquisa 
    /* int pid = syscall(SYS_fork);
    if (pid == 0) {
        syscall( SYS_execve, progname, argv, envp );
    } else wait(NULL);
    syscall(SYS_write, 1, "Hello, World\n", 14);
     */
    // para ver quais as systemcalls usar strace file
    
    syscall( SYS_exit, 0 );
}