#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    system("clear");

    float n = 0, k = 0, o = 0;

    int new = 0;

    scanf("%f", &n);
    scanf("%f", &k);

    if(n == 1){

        printf("\n\n%d\n\n", (int)k);

    }
    else{

        o = n -1.0;

        k = k - o;

        new = (int)(k / n) ;

        printf("%f", n);
        printf("%f", k);
        printf("%f", o);

        printf("\n\n%d\n\n", new);

    }

    return 0;

}