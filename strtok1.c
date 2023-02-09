#include <stdio.h>
#include <string.h>

char **split_string(char *str, const char *delim) {
    int count = 0;
    char *token = strtok(str, delim);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }
    
    char **res = (char **) malloc(sizeof(char*) * (count + 1));
    int i;
    for (i = 0; i < count; i++) {
        res[i] = (char *) malloc(sizeof(char) * (strlen(str) + 1));
    }
    res[count] = NULL;
    
    token = strtok(str, delim);
    i = 0;
    while (token != NULL) {
        strcpy(res[i], token);
        i++;
        token = strtok(NULL, delim);
    }
    
    return res;
}

int main() {
    char str[] = "This is a test";
    const char *delim = " ";
    char **res = split_string(str, delim);
    
    int i;
    for (i = 0; res[i] != NULL; i++) {
        printf("%s\n", res[i]);
    }
    
    return 0;
}
