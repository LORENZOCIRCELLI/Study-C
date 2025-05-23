#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;

    printf("Valor: %d\n", *p);
    printf("Endereço: %p\n", p);

    return 0;
}
