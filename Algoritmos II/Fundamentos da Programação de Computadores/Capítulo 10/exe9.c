#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

    char string [100];

    char c;

    int i = 0;

    scanf("%[^\n]", string);
    scanf(" %c", &c);

    while(string[i] != c){

        i++;

    }

    printf("Na frase: [%s] o caractere '%c' aparece pela primeira vez na %d posicao", string, c, (i + 1));

}
