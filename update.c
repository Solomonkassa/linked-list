#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100
int main()
{
   char command[MAX_COMMAND_LENGTH];

    int status;
    

    while (1)
    {
        printf("#cisfun$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove the newline character from the end of the command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) 
        {
            exit(0);
        }

        pid_t pid = fork();

        if (pid == 0)
        {
            // Child process
            char* args[] = {command, NULL};
            execve(command, args, NULL);
            // If execve returns, there was an error
               perror (" ");
            exit(1);
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
