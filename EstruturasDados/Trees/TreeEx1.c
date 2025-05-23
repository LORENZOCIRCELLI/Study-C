#include <stdio.h>
#include <stdlib.h>

struct Node {
    int valor;
    struct Node *esq;
    struct Node *dir;
};

struct Node* novoNo(int valor) {
    struct Node* no = malloc(sizeof(struct Node));
    no->valor = valor;
    no->esq = no->dir = NULL;
    return no;
}

int main() {
    struct Node *raiz = novoNo(10);
    printf("Raiz criada com valor: %d\n", raiz->valor);
    free(raiz);
    return 0;
}
