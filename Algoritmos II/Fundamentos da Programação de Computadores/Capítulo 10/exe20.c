#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char frase[500];
    char criptografada[2000] = ""; 
    char descriptografada[500] = "";

    printf("Digite uma frase: ");
    scanf("%[^\n]", frase); 

    printf("\nFrase criptografada (ASCII):\n");
    for (int i = 0; frase[i] != '\0'; i++) {
        char temp[10];
        sprintf(temp, "%d ", frase[i]); 
        strcat(criptografada, temp);
    }
    printf("%s\n", criptografada);

    printf("\nFrase descriptografada:\n");
    char *token = strtok(criptografada, " ");
    while (token != NULL) {
        int codigo = atoi(token);       
        char caractere = (char)codigo;   
        strncat(descriptografada, &caractere, 1);
        token = strtok(NULL, " ");
    }
    printf("%s\n", descriptografada);

    return 0;
}
