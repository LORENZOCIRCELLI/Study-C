#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string [100];
    int l = 0;
    int n = 0;
    int e =0;

    scanf("%[^\n]", string);

    for(int i = 0 ; string[i] != '\0' ; i++){

        if(string [i] == ' '){

            e++;

        }
        else if(strchr("1234567890", string[i])){

            n++;

        }
        else if(strchr("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz", string[i])){

            l++;

        }

    }
    printf("\nNumero de letras: %d\n", l);
    printf("Numero de numeros: %d\n", n);
    printf("Numero de espacos: %d\n", e);


}
