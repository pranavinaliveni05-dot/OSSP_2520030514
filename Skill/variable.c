#include <stdio.h>
#include <stdlib.h>

int main() {
    char variable[50];
    char *value;

    printf("Enter variable name: ");
    scanf("%49s", variable);

    value = getenv(variable);

    if (value != NULL)
        printf("Value: %s\n", value);
    else
        printf("Variable is undefined\n");

    return 0;
}
