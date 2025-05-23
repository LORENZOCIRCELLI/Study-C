#include <stdio.h>

int main() {
    int x = 5;
    int *p = &x;
    int **pp = &p;

    printf("Valor de x: %d\n", **pp);
    printf("Endereço de x: %p\n", *pp);
    printf("Endereço de p: %p\n", pp);

    return 0;
}
