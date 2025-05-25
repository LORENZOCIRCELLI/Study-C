#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int a, b, c, d;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);


    int num[] = {b,c,d};

    int size = sizeof(num)/sizeof(num[0]);

    for(int i = 1 ; i < size ; i++){

        int key = num[i];
        int j = i - 1;
        while(j >= 0 && num[j] > key) {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = key;
    }

    for(int i = 0 ; i < size ; i++){

        printf("\n\n%d", num[i]);

    }

    int j = 0;
    
    while(a - num[j] >= 0){

        a -= num[j];
        j++;

    }

    printf("\n\nOperacoes: %d\n", j-1);


    return 0;

}