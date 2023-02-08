#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream) 
{
  
    char *buf = NULL;
    size_t size = 0;
    int c;
    size_t i = 0;

    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }

    while ((c = fgetc(stream)) != EOF)
      {
        if (i + 1 >= size) 
        {
            size = size == 0 ? 128 : size * 2;
            buf = (char *)realloc(buf, size * sizeof(char));
            
            if (buf == NULL) 
            {
                return -1;
            }
        }
        
        buf[i++] = (char)c;
        
        if (c == '\n') 
        {
            break;
        }
    }

    if (i == 0 && c == EOF) 
    {
        return -1;
    }

    buf[i] = '\0';
    *lineptr = buf;
    *n = size;

    return i;
}

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t n = 0;
    ssize_t len;
    printf ("$ ");
    while ((len = getline(&line, &n, stdin)) != -1) 
    {
        
        printf("Line read (length %ld): %s", len, line);
        printf ("$ ");
    }

    free(line);

    return 0;
}
