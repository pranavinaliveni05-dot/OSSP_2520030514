#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child process is running...\n");
        sleep(2);
        printf("Child process completed.\n");
    }
    else {
        waitpid(pid, NULL, 0);
        printf("Parent: Child process completed.\n");
    }

    return 0;
}

