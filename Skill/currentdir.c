#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char path[PATH_MAX];

    if (getcwd(path, sizeof(path)) != NULL) {
        printf("Current Directory: %s\n", path);
    }
    else {
        perror("getcwd");
        return 1;
    }

    printf("Program exiting...\n");

    return 0;
}


