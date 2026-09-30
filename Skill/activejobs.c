 #include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 == 0) {
        sleep(5);
        return 0;
    }

    pid2 = fork();

    if (pid2 == 0) {
        sleep(3);
        return 0;
    }

    printf("Active Jobs:\n");
    printf("Job 1 PID: %d\n", pid1);
    printf("Job 2 PID: %d\n", pid2);

    wait(NULL);
    wait(NULL);

    printf("All jobs completed\n");

    return 0;
}
