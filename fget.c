#include <stdio.h>
#include <stdlib.h>

char *my_getline() {
    char *buffer = NULL;
    int bufsize = 32;
    int pos = 0;
    int c;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        return NULL;
    }

    while (1) {
        c = fgetc(stdin);
        if (c == EOF || c == '\n') {
            buffer[pos] = '\0';
            return buffer;
        } else {
            buffer[pos++] = (char)c;
            if (pos >= bufsize) {
                bufsize += 32;
                buffer = (char *)realloc(buffer, bufsize * sizeof(char));
                if (buffer == NULL) {
                    return NULL;
                }
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

char *my_getline() {
    char *buffer = NULL;
    int bufsize = 32;
    int pos = 0;
    int c;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        return NULL;
    }

    while (1) {
        c = fgetc(stdin);
        if (c == EOF || c == '\n') {
            buffer[pos] = '\0';
            return buffer;
        } else {
            buffer[pos++] = (char)c;
            if (pos >= bufsize) {
                bufsize += 32;
                buffer = (char *)realloc(buffer, bufsize * sizeof(char));
                if (buffer == NULL) {
                    return NULL;
                }
            }
        }
    }
}
