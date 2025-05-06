#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){



    char string [100];
    char string_letras [100] = "";
   
    scanf("%[^\n]", string);

    for(int contador = 0; contador <strlen(string) ; contador++){

        char c = string[contador];

        char temp[2] = {c, '\0'}; 


        if(strchr(string_letras, c) == NULL && c != ' '){

            strcat(string_letras, temp);
        }

    }
    int n = strlen(string_letras);
    printf("Letras diferentes: %s\n", string_letras);
    printf("Numero de letras diferentes: %d\n", n);

    return 0;


}
