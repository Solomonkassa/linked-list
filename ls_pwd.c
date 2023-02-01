#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit program */

    while (should_run)
    {
        printf("osh>");
        fflush(stdout);

        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) if command included &, parent will invoke wait()
         */

        char input[MAX_LINE];
        if (fgets(input, MAX_LINE, stdin) == NULL)
            break;

        int background = 0;
        int length = strlen(input);
        if (input[length-1] == '\n')
            input[--length] = 0;

        if (length == 0)
            continue;

        if (strcmp(input, "exit") == 0)
            break;

        int i = 0;
        char *token = strtok(input, " ");
        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (i > 0 && strcmp(args[i-1], "&") == 0)
        {
            background = 1;
            args[--i] = NULL;
        }

        pid_t pid = fork();
        if (pid == 0)
        {
            execvp(args[0], args);
            printf("%s: command not found\n", args[0]);
            exit(0);
        }
        else
        {
            if (!background)
                waitpid(pid, NULL, 0);
        }
    }

    return 0;
}
