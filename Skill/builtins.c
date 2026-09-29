#include <stdio.h>
#include <string.h>

void pwd_command() {
    printf("PWD command executed\n");
}

void cd_command() {
    printf("CD command executed\n");
}

void exit_command() {
    printf("EXIT command executed\n");
}

int main() {
    char command[50];

    printf("Enter command: ");
    scanf("%49s", command);

    if (strcmp(command, "pwd") == 0)
        pwd_command();
    else if (strcmp(command, "cd") == 0)
        cd_command();
    else if (strcmp(command, "exit") == 0)
        exit_command();
    else
        printf("Invalid command\n");

    return 0;
}
