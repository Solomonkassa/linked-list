#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void) {
  char *args[MAX_LINE/2 + 1]; /* command line arguments */
  int should_run = 1; /* flag to determine when to exit program */

  while (should_run) {
    printf("osh> ");
    fflush(stdout);

    /**
     * After reading user input, the steps are:
     * (1) fork a child process
     * (2) the child process will invoke execvp()
     * (3) if command included &, parent will invoke wait()
     */
    char input[MAX_LINE];
    fgets(input, MAX_LINE, stdin);
    input[strlen(input) - 1] = '\0';

    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork();
    if (pid == 0) {
      /* Child process */
      execvp(args[0], args);
      printf("Error: Command not found\n");
      exit(0);
    } else if (pid < 0) {
      /* Error forking */
      printf("Error: Failed to create new process\n");
    } else {
      /* Parent process */
      if (!strcmp(input, "exit")) {
        should_run = 0;
      } else if (input[strlen(input) - 1] != '&') {
        waitpid(pid, NULL, 0);
      }
    }
  }
  return 0;
}
