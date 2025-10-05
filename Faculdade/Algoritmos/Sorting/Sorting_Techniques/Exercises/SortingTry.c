#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort(int array[], int n){

    for(int i = 1 ; i < n ; i++){

        int key = array[i];
        int j = i -1;

        while(j >= 0 && array[j] > key){

            array[j+1] = array[j];
            j--;

        }
        array[j+1] = key;

    }

}

void selection_sort_array(char *array, int n){

    for(int i = 1 ; i < n ; i++){

        char *key = array[i];
        int j = i - 1;

        while(j >= 0 && strcmp(array[j], key) > 0){

            array[j+1] = array[j];
            j--;

        }

        array[j+1] = key;

    }

}

int main(){

    selection_sort();

    return 0;

}