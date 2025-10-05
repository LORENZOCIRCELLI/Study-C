#include <stdio.h>
#include <stdlib.h>
typedef struct lista {
    int num;
    char cor;
    struct lista *prox;
} Lista;

Lista* inserir_prioridade(Lista* l, Lista* no) {
    if (l == NULL) {
        no->prox = NULL;
        return no;
    }

    if (l->cor == 'V') {
        no->prox = l;
        return no;
    }

    Lista* aux = l;
    while (aux->prox != NULL && aux->prox->cor == 'A') {
        aux = aux->prox;
    }

    no->prox = aux->prox;
    aux->prox = no;

    return l;
}
Lista* inserir_fim(Lista* l, Lista* no) {
    if (l == NULL) {
        no->prox = NULL;
        return no;
    }
    Lista* aux = l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = no;
    no->prox = NULL;
    return l;
}
void imprimir(Lista* l) {
    while (l != NULL) {
        printf("%d-%c ", l->num, l->cor);
        l = l->prox;
    }
    printf("\n");
}

int main() {
    Lista* fila = NULL;
    Lista* n1 = malloc(sizeof(Lista)); n1->num = 10; n1->cor = 'V';
    fila = inserir_fim(fila, n1);
    Lista* n2 = malloc(sizeof(Lista)); n2->num = 11; n2->cor = 'V';
    fila = inserir_fim(fila, n2);
    Lista* n3 = malloc(sizeof(Lista)); n3->num = 5; n3->cor = 'A';
    fila = inserir_prioridade(fila, n3);
    Lista* n4 = malloc(sizeof(Lista)); n4->num = 12; n4->cor = 'V';
    fila = inserir_fim(fila, n4);
    Lista* n5 = malloc(sizeof(Lista)); n5->num = 6; n5->cor = 'A';
    fila = inserir_prioridade(fila, n5);

    imprimir(fila);
    return 0;
}
