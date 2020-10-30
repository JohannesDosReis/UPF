#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  printf("P1\n");
  pid_t pid_P3 = fork();
  if (pid_P3 == 0) {
    printf("P3\n");
  } else {
    printf("P2\n");
    printf("P4\n");
    pid_t pid_P6 = fork();
    if (pid_P6 == 0) {
      printf("P6\n");
    } else {
      printf("P5\n");
      waitpid(pid_P6, NULL, 0);
      waitpid(pid_P3, NULL, 0);
      printf("P7\n");
    }
  }
  exit(0);
}
