#include <stdio.h>

int main() {
    int numero = 3;

    if (numero > 0) {
        printf("Positivo\n");
    } else if (numero < 0) {
        printf("Negativo\n");
    } else {
        printf("Zero\n");
    }

    int i = 0;
    do {
        printf("i = %d\n", i);
        i++;
    } while (i < 3);

    return 0;
}
