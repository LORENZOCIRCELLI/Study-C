#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define STRLEN 50

typedef struct {
    char dados[MAX][STRLEN];
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

int insere_elem(Lista *l, char *elem) {
    if (lista_cheia(l)) return 0;
    strcpy(l->dados[l->tamanho++], elem);
    return 1;
}

int remove_elem(Lista *l, char *elem) {
    if (lista_vazia(l)) return 0;
    int i, j;
    for (i = 0; i < l->tamanho; i++) {
        if (strcmp(l->dados[i], elem) == 0) {
            for (j = i; j < l->tamanho - 1; j++) {
                strcpy(l->dados[j], l->dados[j+1]);
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
        printf("%s ", l->dados[i]);
    }
    printf("\n");
}

int main() {
    Lista l;
    inicializar_lista(&l);
    imprimir_lista(&l);

    char *frutas[] = {"maçã","banana","laranja","uva","limão","abacaxi","morango","melão","kiwi","manga","goiaba"};
    for (int i = 0; i < 11; i++) {
        insere_elem(&l, frutas[i]);
    }
    imprimir_lista(&l);

    remove_elem(&l, "banana");
    imprimir_lista(&l);

    inicializar_lista(&l);
    imprimir_lista(&l);

    return 0;
}

