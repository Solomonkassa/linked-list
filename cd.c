#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    char *new_dir = "/tmp";
    int result = chdir(new_dir);
    if (result == -1) {
        perror("chdir");
        return 1;
    }
    printf("Working directory changed to %s\n", new_dir);
    return 0;
}
