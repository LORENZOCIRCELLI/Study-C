#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int a, b, contador = 0, j = 0, var = 0;

    scanf("%d", &a);
    scanf("%d", &b);

    char palavra [a+1];
    char palavro [b+1];

    scanf(" %[^\n]", palavra);
    scanf(" %[^\n]", palavro);
    contador = sizeof(palavro);
    if(sizeof(palavra) > sizeof(palavro)){contador = sizeof(palavra);}

    for(int i = 0 ; i < contador ; i++){
        
        if(palavra[0] != palavro[0]){break;}
        while(palavra[i] == palavro[j]){j++;}

    }

    printf("%d", j);

    return 0;


}