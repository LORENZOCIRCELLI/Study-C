#include <stdio.h>
#include <stdlib.h>

int main(){

    int* dynamic = malloc(10 * sizeof(int));
    char* longDynamic = malloc(sizeof(long));
    //dynamic = "a";
    printf("\n%d",  (int) sizeof(dynamic));
    printf("\n%d", (int) sizeof(longDynamic));
    free(dynamic);
    free(longDynamic);

}