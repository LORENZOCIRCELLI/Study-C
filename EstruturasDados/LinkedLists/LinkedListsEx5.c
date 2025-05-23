#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* prox;
};

struct No* remover(struct No* head, int chave) {
    if (head == NULL)
        return NULL;

    if (head->valor == chave) {
        struct No* temp = head;
        head = head->prox;
        free(temp);
        return head;
    }

    struct No* atual = head;
    while (atual->prox != NULL && atual->prox->valor != chave)
        atual = atual->prox;

    if (atual->prox != NULL) {
        struct No* temp = atual->prox;
        atual->prox = atual->prox->prox;
        free(temp);
    }

    return head;
}

int main() {
    struct No* lista = malloc(sizeof(struct No));
    lista->valor = 1;
    lista->prox = malloc(sizeof(struct No));
    lista->prox->valor = 2;
    lista->prox->prox = malloc(sizeof(struct No));
    lista->prox->prox->valor = 3;
    lista->prox->prox->prox = NULL;

    lista = remover(lista, 2);

    struct No* temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }

    return 0;
}
