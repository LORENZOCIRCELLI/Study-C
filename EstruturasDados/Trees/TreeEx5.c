#include <stdio.h>
#include <stdlib.h>

struct Node {
    int valor;
    struct Node *esq;
    struct Node *dir;
};

struct Node* novo(int valor) {
    struct Node* no = malloc(sizeof(struct Node));
    no->valor = valor;
    no->esq = no->dir = NULL;
    return no;
}

struct Node* minimo(struct Node* no) {
    while (no && no->esq != NULL)
        no = no->esq;
    return no;
}

struct Node* remover(struct Node* raiz, int valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->valor)
        raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover(raiz->dir, valor);
    else {
        if (raiz->esq == NULL) {
            struct Node* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            struct Node* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        struct Node* temp = minimo(raiz->dir);
        raiz->valor = temp->valor;
        raiz->dir = remover(raiz->dir, temp->valor);
    }

    return raiz;
}

int main() {
    struct Node* raiz = novo(10);
    raiz->esq = novo(5);
    raiz->dir = novo(15);

    raiz = remover(raiz, 10);
    printf("Raiz atual: %d\n", raiz->valor);

    return 0;
}
