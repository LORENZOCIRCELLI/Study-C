#include <stdio.h>

int varInt = 10;
char varChar = 'A';
float varFloat = 3.1415;

int* varIntPointer;
char* varCharPointer;
float* varFloatPointer;

int main(){

    varIntPointer = &varInt;
    varCharPointer = &varChar;
    varFloatPointer = &varFloat;

    printf("\nValor do inteiro: %d", varInt );
    printf("\nValor do char: %c", varChar);
    printf("\nValor do float: %f ", varFloat);

    *varIntPointer = 25;
    *varCharPointer = 'B';
    *varFloatPointer = 1.618;

    printf("\nValor do inteiro: %d", varInt );
    printf("\nValor do char: %c", varChar);
    printf("\nValor do float: %f ", varFloat);

    return 0;

}