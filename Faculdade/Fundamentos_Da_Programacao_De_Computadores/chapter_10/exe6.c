#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string [100];
    char stringdouble [(strlen(string))*2];

    scanf("%[^\n]", string);

    for(int i = 0 ; i < strlen(string) ; i++){

        char a = string[i];
        printf("%c", a);
        printf("%c", a);


}

}
