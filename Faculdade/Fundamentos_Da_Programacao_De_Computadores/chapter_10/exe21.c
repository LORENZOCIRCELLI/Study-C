#include <stdio.h>
#include <string.h>

int main() {
    char frase[500];
    char palavras[100][50];
    int totalPalavras = 0;

    printf("Digite uma frase: ");
    scanf("%[^\n]", frase);

    char *token = strtok(frase, " ");
    while (token != NULL && totalPalavras < 100) {
        strcpy(palavras[totalPalavras++], token);
        token = strtok(NULL, " ");
    }

    char temp[50];
    strcpy(temp, palavras[0]);
    strcpy(palavras[0], palavras[totalPalavras - 1]);
    strcpy(palavras[totalPalavras - 1], temp);

    printf("\nFrase criptografada:\n");
    for (int i = 0; i < totalPalavras; i++) {
        printf("%s", palavras[i]);
        if (i < totalPalavras - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
