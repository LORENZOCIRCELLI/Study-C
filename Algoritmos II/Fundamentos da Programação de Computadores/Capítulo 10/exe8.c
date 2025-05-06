#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

    char string [100];

    char character;

    int contador = 0;

    printf("Insira aqui a sua frase: ");
    scanf("%[^\n]", string);
    printf("Insira o caractere: ");
    scanf(" %c", &character);

    for(int i = 0 ; i < strlen(string) ; i++){

        if(string[i] == character || string[i] == toupper(character)){

            contador++;

        }


    }

    if(contador == 0){

        printf("Esse caractere não está presente na frase!");

    }
    else{

        printf("Esse caractere está presente na frase %d vezes!", contador);

    }

}
