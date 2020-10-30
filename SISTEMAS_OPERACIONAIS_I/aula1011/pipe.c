#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pipefd[2];
  pid_t cpid;
  char str[100];

  pipe(pipefd);

  cpid = fork();
  if (cpid == 0) {    /* Child reads from pipe */
    close(pipefd[1]); /* Close unused write end */
    read(pipefd[0], str, sizeof(str));
    for (char *p = str; *p; p++)
      *p = toupper(*p);

    write(STDOUT_FILENO, str, strlen(str));
    close(pipefd[0]);
    _exit(EXIT_SUCCESS);
  } else {            /* Parent writes argv[1] to pipe */
    close(pipefd[0]); /* Close unused read end */
    fgets(str, sizeof(str), stdin);

    write(pipefd[1], str, strlen(str));

    close(pipefd[1]); /* Reader will see EOF */
    wait(NULL);       /* Wait for child */
    exit(EXIT_SUCCESS);
  }
}