#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    ptr = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
        ptr[i] = i + 1;

    printf("Memory allocated successfully\n");

    free(ptr);

    printf("Memory released successfully\n");

    return 0;
}
