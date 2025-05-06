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


    for (int i = 0; i < totalPalavras; i += 2) {
        if (i + 1 < totalPalavras) {
            char *p1 = palavras[i];
            char *p2 = palavras[i + 1];
            int len1 = strlen(p1);
            int len2 = strlen(p2);
            int maxLen = len1 > len2 ? len1 : len2;


            for (int j = 0; j < maxLen; j++) {
                if (j < len1) {
                    printf("%c", p1[j]);
                }
                if (j < len2) {
                    printf("%c", p2[len2 - 1 - j]);
                }
            }
            printf(" ");
        } else {
      
            int len = strlen(palavras[i]);
            for (int j = len - 1; j >= 0; j--) {
                printf("%c", palavras[i][j]);
            }
        }
    }

    printf("\n");
    return 0;
}
