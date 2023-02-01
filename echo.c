#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LEN 100

int main() {
  char command[MAX_LEN];

  while (1) {
    printf("$ ");
    fgets(command, MAX_LEN, stdin);

    // Remove newline character from the end of the command
    command[strcspn(command, "\n")] = 0;

    // Parse the command
    char *argv[MAX_LEN];
    int argc = 0;
    char *token = strtok(command, " ");
    while (token != NULL) {
      argv[argc++] = token;
      token = strtok(NULL, " ");
    }

    // Handle the "echo" command
    if (strcmp(argv[0], "echo") == 0) {
      for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
      }
      printf("\n");
    }
  }

  return 0;
}
