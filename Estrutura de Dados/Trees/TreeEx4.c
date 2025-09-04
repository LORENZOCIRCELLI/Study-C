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

void emOrdem(struct Node* raiz) {
    if (raiz) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void preOrdem(struct Node* raiz) {
    if (raiz) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(struct Node* raiz) {
    if (raiz) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

int main() {
    struct Node* raiz = novo(10);
    raiz->esq = novo(5);
    raiz->dir = novo(15);

    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    return 0;
}
