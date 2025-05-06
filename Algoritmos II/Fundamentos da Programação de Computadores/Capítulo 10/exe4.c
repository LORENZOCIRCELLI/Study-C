#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    
    char string [100], formatada[200];
    bool emPalavra = false;
    int i = 0, j = 0, palavras = 0;

    printf("Insira a sua frase: ");
    scanf("%[^\n]", string);

    while(string[i] != '\0'){

        if(string[i] != ' '){

            formatada[j++] = string[i];
            if(!emPalavra){
            
                palavras++;
                emPalavra = true;

            }
        }
            else if(emPalavra){

                formatada[j++] = ' ';
                emPalavra = false;

            }
            i++;

        

    }

    if(j> 0 && formatada[j-1] == ' '){

        j--;

    }
    formatada[j] = '\0';

    printf("Frase formatada: '%s'\n", formatada);
    printf("Número de palavras: %d\n", palavras);


}

