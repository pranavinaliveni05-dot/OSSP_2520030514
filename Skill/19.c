#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("\nSIGINT received\n");
    printf("Interrupt handled safely\n");
}

int main() {
    signal(SIGINT, handle_sigint);

    printf("Program running...\n");
    printf("Press Ctrl+C to send SIGINT\n");

    while (1) {
        sleep(1);
    }

    return 0;
}
