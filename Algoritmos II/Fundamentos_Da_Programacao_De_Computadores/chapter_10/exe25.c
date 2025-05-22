#include <stdio.h>
#include <string.h>

int main() {
    char frase[500], criptografada[500], descriptografada[500];
    int vogais[500], posicoes[500];
    int contadorVogais = 0;

    printf("Digite uma frase: ");
    scanf("%[^\n]", frase);

    int j = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        if (strchr("aeiouAEIOU", frase[i])) {
            vogais[contadorVogais] = frase[i];
            posicoes[contadorVogais] = i;
            contadorVogais++;
        } else {
            criptografada[j++] = frase[i];
        }
    }
    criptografada[j] = '\0';

    printf("\nFrase criptografada: %s\n", criptografada);

    for (int i = 0; i < contadorVogais; i++) {
        descriptografada[posicoes[i]] = vogais[i];
    }

    for (int i = 0; criptografada[i] != '\0'; i++) {
        if (descriptografada[i] == '\0') {
            descriptografada[i] = criptografada[i];
        }
    }

    printf("\nFrase descriptografada: %s\n", descriptografada);

    return 0;
}
