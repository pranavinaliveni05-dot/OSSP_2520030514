#include <stdio.h>
#include <unistd.h>

void show_system() {
    printf("OSSP Project Demo\n");
    printf("-----------------\n");
    printf("1. Command History\n");
    printf("2. Pipe Communication\n");
    printf("3. Process Management\n");
    printf("4. Signal Handling\n");
    printf("5. Memory Management\n");
}

int main() {
    printf("Project Repository Demo\n\n");

    show_system();

    printf("\nCurrent Process ID: %d\n", getpid());
    printf("Demo completed successfully\n");

    return 0;
}
