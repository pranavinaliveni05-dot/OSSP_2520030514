#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *path;
    char *copy;
    char *dir;

    path = getenv("PATH");

    if (path == NULL) {
        printf("PATH variable not found\n");
        return 1;
    }

    copy = strdup(path);

    dir = strtok(copy, ":");

    while (dir != NULL) {
        char fullpath[500];

        snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, "ls");

        if (access(fullpath, X_OK) == 0) {
            printf("Executable found: %s\n", fullpath);
            free(copy);
            return 0;
        }

        dir = strtok(NULL, ":");
    }

    printf("Command not found\n");

    free(copy);

    return 0;
}
