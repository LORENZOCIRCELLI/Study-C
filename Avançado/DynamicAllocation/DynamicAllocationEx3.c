#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa *p = malloc(sizeof(struct Pessoa));

    p->idade = 30;
    sprintf(p->nome, "João");

    printf("Nome: %s, Idade: %d\n", p->nome, p->idade);

    free(p);
    return 0;
}
