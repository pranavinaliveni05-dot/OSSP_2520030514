#include <stdio.h>
#include <stdlib.h>

void module1() {
    printf("Module 1: Input processing successful\n");
}

void module2() {
    printf("Module 2: Command processing successful\n");
}

void module3() {
    printf("Module 3: Output processing successful\n");
}

int main() {
    printf("Integrated System\n");

    module1();
    module2();
    module3();

    printf("All modules executed successfully\n");

    return 0;
}
