#include <stdio.h>
#include <string.h>

char *_getenv(const char *name) 
{
    extern char **environ;
    int i;
    int len = strlen(name);
    
    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=') 
        {
            return &environ[i][len + 1];
        }
    }
    return NULL;
}

int main(int argc, char **argv) 
{
    char *value = _getenv("PATH");
    
    if (value != NULL)
    {
        printf("PATH=%s\n", value);
    }
    else 
    {
        printf("PATH not found\n");
    }
    return 0;
}
