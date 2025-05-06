#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    char string [100];
    char string2 [100];
    int contador = 0;
    int contador2 = 0;

    scanf("%[^\n]", string);
    scanf(" %[^\n]", string2);

    if(strlen(string) != strlen(string2)){

        printf("Uma sequência não é permutação da outra!");
        return 0;

    }
    qsort(string, strlen(string), sizeof(char), (int (*)(const void *, const void *)) strcmp);
    qsort(string2, strlen(string2), sizeof(char), (int (*)(const void *, const void *)) strcmp);

    if(strcmp(string, string2) == 0){printf("As cadeias são permutações uma da outra!\n");}
    else{printf("As cadeias não são permutações uma da outra\n");}


return 0;

}
