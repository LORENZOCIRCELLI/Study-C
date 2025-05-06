#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string [100];

    int n;

    scanf("%[^\n]", string);

    scanf("%i", &n);

    if(n > 5){

    printf("Número invalido!");

    }
    else{

        for(int i = 0 ; i < n ; i++){

            printf("%s ", string);


}


    }

}
