#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_LEN 100

int main() {
    while (1) {
        char cmd[MAX_LEN];
        char *args[MAX_LEN];
        int i = 0;
        printf("$ ");
        fgets(cmd, MAX_LEN, stdin);
        cmd[strlen(cmd) - 1] = '\0';
        args[i] = strtok(cmd, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        if (strcmp(args[0], "exit") == 0) {
            break;
        }
        int pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            }
        } else {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
