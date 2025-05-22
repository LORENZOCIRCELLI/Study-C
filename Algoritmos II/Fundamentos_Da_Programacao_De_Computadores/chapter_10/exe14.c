#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

    char string [100];
    char string_nova [200];

    scanf("%[^\n]", string);

    for(int i = 0, j=0 ; string[i] != '\0' ; i++){

        if(strchr("AaEeIiOoUu", string[i])){

            string_nova[j++] = toupper(string[i]);


        }
        else if(string [i] == ' ' || string[i] == ',' || string[i] == '.'){string_nova[j++] = string[i];} 
        else{

            string_nova[j++] = tolower(string[i]);

        }


    }
    printf("\nFrase antes: %s\n", string);
    printf("Frase formatada: %s\n", string_nova);


}
