#include <stdio.h>
#include <stdlib.h>

struct Node {
    int valor;
    struct Node *esq;
    struct Node *dir;
};

struct Node* inserir(struct Node* raiz, int valor) {
    if (raiz == NULL) {
        struct Node* no = malloc(sizeof(struct Node));
        no->valor = valor;
        no->esq = no->dir = NULL;
        return no;
    }

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

int main() {
    struct Node *raiz = NULL;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);

    printf("Valores inseridos: 10, 5, 15\n");
    return 0;
}
