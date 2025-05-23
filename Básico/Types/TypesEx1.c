#include <stdio.h>
#include <stdbool.h>

int main() {

    int inteiro = 100;
    float real = 3.14;
    double grande_real = 2.718281828;
    char letra = 'C';
    bool verdadeiro = true;

    printf("int: %d\n", inteiro);
    printf("float: %.2f\n", real);
    printf("double: %.9f\n", grande_real);
    printf("char: %c\n", letra);
    printf("bool: %d\n", verdadeiro); // true é 1

    return 0;
}