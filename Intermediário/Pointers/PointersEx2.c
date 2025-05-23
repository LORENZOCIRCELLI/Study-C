#include <stdio.h>

void dobrar(int *n) {
    *n = *n * 2;
}

int main() {
    int valor = 7;
    dobrar(&valor);
    printf("Dobrado: %d\n", valor);

    return 0;
}
