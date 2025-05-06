#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string [100];

    char c;

    int i = 0;

    int reg = 0;

    scanf("%[^\n]", string);
    scanf(" %c", &c);

    while(string[i] != '\0'){

        if(string [i] == c){

            reg = i;

        }
        i++;


    }

    printf("\n\nA ultima posicao que o caractere %c aparece na frase: [%s] e a %d\n\n", c, string, reg);

}
