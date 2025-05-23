#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int recipeLoader(){

    FILE *file = fopen("itemList.csv", "r");

    if(file == NULL){return 2;}

    fscanf(file, )
    
}

int main(){

    int variable = recipeLoader();

    printf("%d", variable);


    return 0;

}