#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool buscar(struct Node* raiz, int valor) {
    if (raiz == NULL)
        return false;

    if (valor == raiz->valor)
        return true;
    else if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    else
        return buscar(raiz->dir, valor);
}

int main() {
    struct Node *raiz = NULL;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 20);

    int valor = 4;
    if (buscar(raiz, valor))
        printf("Valor %d encontrado\n", valor);
    else
        printf("Valor %d não encontrado\n", valor);

    return 0;
}
