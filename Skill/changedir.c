#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char path[PATH_MAX];

    printf("Enter directory path: ");
    scanf("%s", path);

    if (chdir(path) == 0)
        printf("Directory changed successfully\n");
    else
        perror("chdir");

    return 0;
}





