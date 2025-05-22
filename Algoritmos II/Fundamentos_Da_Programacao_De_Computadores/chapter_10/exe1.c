#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[100];


    printf("Insert the string: ");
    scanf("%[^\n]", string); 


    for (int i = 0; i < strlen(string); i++) {
        if (!strchr("AEIOUaeiou", string[i])) { 
            string[i] = '#';
        }
    }


    int contador = strlen(string);
    char reversed[100];
    int j = 0;

    for (int i = contador - 1; i >= 0; i--) {
        reversed[j++] = string[i];
    }
    reversed[j] = '\0'; 


    printf("Modified and reversed string: %s\n", reversed);

    return 0;
}

