#include <stdio.h>
#include <stdlib.h>

char *my_getline() 
{
    int c, i = 0;
    size_t bufsize = 32;
    char *buffer = malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        return NULL;
    }
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i == bufsize - 1)
        {
            bufsize *= 2;
            char *newbuf = realloc(buffer, bufsize * sizeof(char));
            if (newbuf == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = newbuf;
        }
        buffer[i++] = (char)c;
    }
    buffer[i] = '\0';
    return buffer;
}
int main()
{
    printf("Enter some text: ");
    char *line = my_getline();
    if (line != NULL) 
    {
        printf("You entered: %s\n", line);
        free(line);
    } else {
        printf("Error: failed to read input.\n");
    }
    return 0;
}
