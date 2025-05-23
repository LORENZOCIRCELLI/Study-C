#include <stdio.h>
#include <string.h>

int main() {
    char nome[20] = "Linguagem C";
    int tamanho = strlen(nome);

    printf("Nome: %s\n", nome);
    printf("Tamanho: %d\n", tamanho);

    return 0;
}
