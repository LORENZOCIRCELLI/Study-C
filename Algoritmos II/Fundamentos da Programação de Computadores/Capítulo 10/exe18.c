#include <stdio.h>
#include <string.h>

int main() {
    char frase[500];
    char palavras[100][50];
    int totalPalavras = 0;

    printf("Digite uma frase: ");
    scanf("%[^\n]", frase); // 


    char *token = strtok(frase, " ");
    while (token != NULL && totalPalavras < 100) {
        strcpy(palavras[totalPalavras++], token);
        token = strtok(NULL, " ");
    }

    printf("\nFrase criptografada:\n");


    for (int i = 0; i < totalPalavras; i++) {
        int len = strlen(palavras[i]);
        int metade = len / 2 + len % 2; 

        for (int j = 0; j < metade; j++) {
            printf("%c", palavras[i][j]);
        }

        for (int j = metade; j < len; j++) {
            printf("?");
        }
        printf(" ");
    }

    printf("\n");
    return 0;
}
