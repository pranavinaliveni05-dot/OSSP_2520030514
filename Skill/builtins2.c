#include <stdio.h>
#include <string.h>

void execute_command(char *command) {
    if (strcmp(command, "pwd") == 0) {
        printf("Executing PWD\n");
    }
    else if (strcmp(command, "cd") == 0) {
        printf("Executing CD\n");
    }
    else if (strcmp(command, "exit") == 0) {
        printf("Executing EXIT\n");
    }
    else {
        printf("Invalid built-in command\n");
    }
}

int main() {
    char command[50];

    printf("Enter command: ");
    scanf("%49s", command);

    execute_command(command);

    return 0;
}

