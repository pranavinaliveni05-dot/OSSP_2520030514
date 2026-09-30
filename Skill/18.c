#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process started\n");
        raise(SIGSTOP);
        printf("Child process resumed\n");
        return 0;
    }

    sleep(1);

    printf("Child process stopped\n");
    printf("Sending SIGCONT to resume child\n");

    kill(pid, SIGCONT);

    wait(NULL);

    printf("Child process completed\n");

    return 0;
}
