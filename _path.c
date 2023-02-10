#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_directories_in_path() {
    char *path = getenv("PATH");
    char *token = strtok(path, ":");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
}

int main(int argc, char *argv[]) {
    print_directories_in_path();
    return 0;
}
