#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* prox;
};

int main() {
    struct No* primeiro = malloc(sizeof(struct No));
    primeiro->valor = 10;
    primeiro->prox = NULL;

    printf("Valor do nó: %d\n", primeiro->valor);

    free(primeiro);
    return 0;
}
