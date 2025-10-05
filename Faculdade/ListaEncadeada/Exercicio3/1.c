#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

void inicializar_lista(Lista *l) {
    l->tamanho = 0;
}

int lista_vazia(Lista *l) {
    return l->tamanho == 0;
}

int lista_cheia(Lista *l) {
    return l->tamanho == MAX;
}

int insere_elem(Lista *l, int elem) {
    if (lista_cheia(l)) return 0;
    l->dados[l->tamanho++] = elem;
    return 1;
}

int remove_elem(Lista *l, int elem) {
    if (lista_vazia(l)) return 0;
    int i, j;
    for (i = 0; i < l->tamanho; i++) {
        if (l->dados[i] == elem) {
            for (j = i; j < l->tamanho - 1; j++) {
                l->dados[j] = l->dados[j+1];
            }
            l->tamanho--;
            return 1;
        }
    }
    return 0;
}

void imprimir_lista(Lista *l) {
    if (lista_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

int main() {
    Lista l;
    inicializar_lista(&l);
    imprimir_lista(&l);

    int valores[] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
    for (int i = 0; i < 11; i++) {
        insere_elem(&l, valores[i]);
    }
    imprimir_lista(&l);

    remove_elem(&l, 8);
    imprimir_lista(&l);

    inicializar_lista(&l);
    imprimir_lista(&l);

    return 0;
}

