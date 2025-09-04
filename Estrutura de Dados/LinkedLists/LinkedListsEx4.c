#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* prox;
};

int buscar(struct No* head, int chave) {
    while (head != NULL) {
        if (head->valor == chave)
            return 1;
        head = head->prox;
    }
    return 0;
}

int main() {
    struct No* lista = malloc(sizeof(struct No));
    lista->valor = 8;
    lista->prox = malloc(sizeof(struct No));
    lista->prox->valor = 12;
    lista->prox->prox = NULL;

    int achou = buscar(lista, 12);
    printf("Valor encontrado: %s\n", achou ? "Sim" : "Não");

    return 0;
}
