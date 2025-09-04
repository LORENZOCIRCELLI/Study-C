#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* prox;
};

struct No* inserirInicio(struct No* head, int valor) {
    struct No* novo = malloc(sizeof(struct No));
    novo->valor = valor;
    novo->prox = head;
    return novo;
}

int main() {
    struct No* lista = NULL;
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 10);

    struct No* temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }

    return 0;
}
