#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char nome[50];
    int volume;
    float preco;
} Bebida;

typedef struct {
    Bebida dados[MAX];
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

int insere_bebida(Lista *l, Bebida b) {
    if (lista_cheia(l)) return 0;
    l->dados[l->tamanho++] = b;
    return 1;
}

int remove_bebida(Lista *l, char *nome) {
    if (lista_vazia(l)) return 0;
    int i, j;
    for (i = 0; i < l->tamanho; i++) {
        if (strcmp(l->dados[i].nome, nome) == 0) {
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
        printf("Nome: %s | Volume: %dml | Preco: R$%.2f\n",
               l->dados[i].nome, l->dados[i].volume, l->dados[i].preco);
    }
    printf("\n");
}

int main() {
    Lista l;
    inicializar_lista(&l);
    imprimir_lista(&l);

    Bebida bebidas[] = {
        {"Agua", 500, 1.50}, {"Refrigerante", 350, 3.00}, {"Suco", 300, 2.50},
        {"Cerveja", 600, 5.00}, {"Vinho", 750, 25.00}, {"Cha", 300, 2.00},
        {"Cafe", 200, 1.00}, {"Energetico", 250, 6.00}, {"Iogurte", 200, 3.50},
        {"Leite", 1000, 4.00}, {"Whisky", 1000, 150.00}
    };

    for (int i = 0; i < 11; i++) {
        insere_bebida(&l, bebidas[i]);
    }
    imprimir_lista(&l);

    remove_bebida(&l, "Refrigerante");
    imprimir_lista(&l);

    inicializar_lista(&l);
    imprimir_lista(&l);

    return 0;
}

