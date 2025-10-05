#include <stdio.h>
#include <stdbool.h>

struct produto {
    int codProd;
    char nomeProd[10];
    float valor;
    int qtdeEstoque;
};

bool produtoMenorPreco(struct produto lista[], int tamanho, struct produto *menor) {
    if (tamanho == 0) {
        return false;
    }

    *menor = lista[0];

    for (int i = 1; i < tamanho; i++) {
        if (lista[i].valor < menor->valor) {
            *menor = lista[i];
        }
    }

    return true;
}

int main() {
    struct produto lista[3] = {
        {101, "ProdutoA", 25.5, 10},
        {102, "ProdutoB", 15.0, 5},
        {103, "ProdutoC", 30.0, 8}
    };

    struct produto menor;

    if (produtoMenorPreco(lista, 3, &menor)) {
        printf("Produto de menor preco:\n");
        printf("Codigo: %d\n", menor.codProd);
        printf("Nome: %s\n", menor.nomeProd);
        printf("Valor: %.2f\n", menor.valor);
        printf("Quantidade em estoque: %d\n", menor.qtdeEstoque);
    } else {
        printf("Lista vazia.\n");
    }

    return 0;
}
