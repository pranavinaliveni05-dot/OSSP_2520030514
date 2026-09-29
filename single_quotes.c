#include <stdio.h>
#include <string.h>

int main() {
    char input[100];

    printf("Enter text inside single quotes: ");
    fgets(input, sizeof(input), stdin);

    printf("Literal content: %s", input);

    return 0;
}
