 #include <stdio.h>

int main() {
    char input[200];

    printf("Enter text with escape sequences: ");
    fgets(input, sizeof(input), stdin);

    printf("Parsed input: %s", input);

    return 0;
}
