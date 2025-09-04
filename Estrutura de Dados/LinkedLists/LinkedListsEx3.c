#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* prox;
};

void inserirFim(struct No** head, int valor) {
    struct No* novo = malloc(sizeof(struct No));
    novo->valor = valor;
    novo->prox = NULL;

    if (*head == NULL) {
        *head = novo;
        return;
    }

    struct No* temp = *head;
    while (temp->prox != NULL)
        temp = temp->prox;

    temp->prox = novo;
}

int main() {
    struct No* lista = NULL;
    inserirFim(&lista, 5);
    inserirFim(&lista, 15);

    struct No* temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }

    return 0;
}
