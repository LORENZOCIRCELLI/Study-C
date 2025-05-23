#include <stdio.h>

int main() {
    int a = 5, b = 10;
    float media = (a + b) / 2.0;
    char status = 'A';

    printf("Nota A: %d\n", a);
    printf("Nota B: %d\n", b);
    printf("Média: %.1f\n", media);
    printf("Status: %c\n", status);

    return 0;
}