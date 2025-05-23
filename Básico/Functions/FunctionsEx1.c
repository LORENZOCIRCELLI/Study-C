#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

void saudacao() {
    printf("Olá! Bem-vindo ao C!\n");
}

int main() {
    saudacao();
    int resultado = soma(10, 5);
    printf("Resultado da soma: %d\n", resultado);

    return 0;
}
