#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa p = {"Ana", 25};

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);

    return 0;
}
