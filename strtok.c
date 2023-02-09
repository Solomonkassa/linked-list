#include <string.h>
#include <stdio.h>

char *split(char *str, const char *delim, char **nextp)
{
    if (str == NULL)
    {
        str = *nextp;
    }

    if (*str == '\0') 
    {
        return NULL;
    }

    char *start = str;
    char *p = strpbrk(start, delim);

    if (p == NULL) 
    {
        *nextp = strchr(start, '\0');
        return start;
    }

    *p = '\0';
    *nextp = p + 1;

    return start;
}

int main() 
{
    char input[] = "Hello, World! How are you today?";
    const char *delim = " ,!?";

    char *token, *nextp;
    for (token = split(input, delim, &nextp); token != NULL; token = split(NULL, delim, &nextp)) 
    {
        printf("Token: %s\n", token);
    }

    return 0;
}
