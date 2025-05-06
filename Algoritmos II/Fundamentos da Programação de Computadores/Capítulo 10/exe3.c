#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string [100];
    char stringnova [100];

    int j = 0;

    fgets(string, sizeof(string), stdin);

    for(int i = 0 ; i < strlen(string) ; i++){

        if(!(string[i] == ' ')){

            stringnova[j] = string[i]; 
            j++;   

        }

    }
    
    printf("%s", stringnova);


}
