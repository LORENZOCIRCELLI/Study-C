#include <stdio.h>

union Dado {
    int i;
    float f;
    char c;
};

int main() {
    union Dado d;

    d.i = 10;
    printf("Inteiro: %d\n", d.i);

    d.f = 3.14;
    printf("Float: %.2f\n", d.f);

    d.c = 'A';
    printf("Char: %c\n", d.c);

    return 0;
}
