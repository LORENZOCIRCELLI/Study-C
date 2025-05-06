#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRAS 100
#define TAM_PALAVRA 50
#define TAM_FRASE 500

int main() {
    char frase[TAM_FRASE];
    char palavras[MAX_PALAVRAS][TAM_PALAVRA];
    int contagem[MAX_PALAVRAS] = {0};
    int totalPalavras = 0;

    printf("Digite uma frase: ");
    fgets(frase, TAM_FRASE, stdin);
    frase[strcspn(frase, "\n")] = '\0'; 

    char *palavra = strtok(frase, " ");
    while (palavra != NULL) {
        for (int i = 0; palavra[i]; i++) {
            palavra[i] = tolower(palavra[i]);
        }

        int encontrada = 0;
        for (int i = 0; i < totalPalavras; i++) {
            if (strcmp(palavra, palavras[i]) == 0) {
                contagem[i]++;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada && totalPalavras < MAX_PALAVRAS) {
            strcpy(palavras[totalPalavras], palavra);
            contagem[totalPalavras] = 1;
            totalPalavras++;
        }

        palavra = strtok(NULL, " ");
    }

    printf("\nOcorrências de cada palavra:\n");
    for (int i = 0; i < totalPalavras; i++) {
        printf("%s: %d\n", palavras[i], contagem[i]);
    }

    return 0;
}
