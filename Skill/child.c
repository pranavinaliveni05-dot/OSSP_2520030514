#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        printf("Child process executing ls...\n");
        execlp("ls", "ls", "-l", NULL);

        printf("Execution failed\n");
    }
    else {
        wait(NULL);
        printf("Parent process completed\n");
    }

    return 0;
}
