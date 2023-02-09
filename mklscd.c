#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

int main() {
  char buffer[BUFFER_SIZE];  // buffer to store the input command

  while (1) {
    printf("> ");  // prompt for input
    fgets(buffer, BUFFER_SIZE, stdin);  // read input into buffer

    // Remove the newline character from the input string
    int len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }

    char *command = strtok(buffer, " ");  // get the first token (the command)
    char *arg = strtok(NULL, " ");  // get the second token (the argument)

    // Check the command and perform the corresponding action
    if (strcmp(command, "mkdir") == 0) {
      int status = mkdir(arg, 0700);  // create the directory with 0700 permissions
      if (status == -1) {
        perror("mkdir");  // print error message if there was a problem creating the directory
      }
    } else if (strcmp(command, "cd") == 0) {
      int status = chdir(arg);  // change the current working directory
      if (status == -1) {
        perror("cd");  // print error message if there was a problem changing the directory
      }
    } else if (strcmp(command, "pwd") == 0) {
      char *cwd = getcwd(NULL, 0);  // get the current working directory
      if (cwd != NULL) {
        printf("%s\n", cwd);  // print the current working directory
        free(cwd);  // free the memory used by the cwd string
      } else {
        perror("pwd");  // print error message if there was a problem getting the current directory
      }
    } else if (strcmp(command, "ls") == 0) {
      DIR *dir;
      struct dirent *ent;
      if (arg == NULL) {
        arg = ".";  // default to current directory if no argument is provided
      }
      dir = opendir(arg);  // open the directory
      if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {  // read each directory entry
          printf("%s\n", ent->d_name);  // print the entry name
        }
        closedir(dir);  // close the directory
      } else {
        perror("ls");  // print error message if there was a problem opening the directory
      }
    } else if (strcmp(command, "exit") == 0) {
      break;  // exit the loop and terminate the program
    } else {
      printf("Unknown command. Available commands: mkdir, cd, pwd, ls, exit\n");  // print error message for unknown commands
    }
  }
