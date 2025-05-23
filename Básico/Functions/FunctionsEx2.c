#include <stdio.h>

int quadrado(int x) {
    return x * x;
}

int main() {
    int valor = 4;
    int resultado = quadrado(valor);

    printf("Quadrado de %d é %d\n", valor, resultado);

    return 0;
}
