#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigtstp(int sig) {
    printf("\nSIGTSTP received\n");
    printf("Process suspension request handled\n");
}

int main() {
    signal(SIGTSTP, handle_sigtstp);

    printf("Process Group ID: %d\n", getpgrp());
    printf("Program running...\n");
    printf("Press Ctrl+Z to send SIGTSTP\n");

    while (1)
        sleep(1);

    return 0;
}
