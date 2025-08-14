#include <stdio.h>
int main(){

        int counter = 0;
        int a,b;

        scanf(" %d", &a);
        char a1[a];
        scanf(" %[^\n]", a1);
        scanf(" %d", &b);
        char a2[b];
        scanf(" %[^\n]", a2);

        if(a1[0] == a2[0]){
        while(a1[counter] == a2[counter] && counter < (sizeof(a1)/sizeof(a1[0]))){

            counter++;

        }
        }

        printf("%d", counter);

}