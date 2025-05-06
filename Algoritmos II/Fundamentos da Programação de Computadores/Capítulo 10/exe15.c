#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string [100];
    char resultado[500];

    scanf("%[^\n]", string);

    for(int i = 0 ; i < strlen(string) ; i++){

    switch(string[i]){

        case '0':
            
            strcat(resultado, "zero");
            break;
        
        case '1':
            
            strcat(resultado, "um");
            break;

        case '2':
            
            strcat(resultado, "dois");
            break;

        case '3':
            
            strcat(resultado, "três");
            break;

        case '4':
            
            strcat(resultado, "quatro");
            break;

        case '5':
            
            strcat(resultado, "cinco");
            break;

        case '6':
            
            strcat(resultado, "seis");
            break;

        case '7':
            
            strcat(resultado, "sete");
            break;

        case '8':
            
            strcat(resultado, "oito");
            break;

        case '9':
            
            strcat(resultado, "nove");
            break;

        default:

            strncat(resultado, &string[i], 1);


        }

    }



    printf("%s", resultado);

}
