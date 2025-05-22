#include <stdio.h>
#include <string.h>

int main() {
    char str[500];
    printf("Digite a string: ");
    scanf("%s", str);

    char letraMaior = str[0];
    int tamanhoMaior = 1, tamanhoAtual = 1;

    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == str[i - 1]) {
            tamanhoAtual++;
        } else {
            if (tamanhoAtual > tamanhoMaior) {
                tamanhoMaior = tamanhoAtual;
                letraMaior = str[i - 1];
            }
            tamanhoAtual = 1;
        }
    }

    if (tamanhoAtual > tamanhoMaior) {
        tamanhoMaior = tamanhoAtual;
        letraMaior = str[strlen(str) - 1];
    }

    printf("maior %c, tamanho %d\n", letraMaior, tamanhoMaior);
    return 0;
}
