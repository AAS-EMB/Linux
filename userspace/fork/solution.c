#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t pid;
  int result;
  char *child_argv[] = {"ls", "-la", NULL};
  pid = fork();
  switch (pid) {
      case -1:
        perror("fork");
        exit(EXIT_FAILURE);
      case 0:
        printf("It's process child\n");
        printf("======================\n");
        printf("PID - %d PPID - %d\n", getpid(), getppid());
        printf("======================\n");
        execv("/bin/ls", child_argv);
        exit(EXIT_SUCCESS);
      default:
        printf("It's process parent\n");
        printf("======================\n");
        printf("PID - %d PPID - %d\n", getpid(), getppid());
        printf("======================\n");
        wait(&result);
  }
  return result;
}
