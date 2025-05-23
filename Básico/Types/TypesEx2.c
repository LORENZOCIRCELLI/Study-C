#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    unsigned int x = UINT_MAX;
    short y = SHRT_MAX;
    long z = LONG_MAX;

    printf("Unsigned int: %u\n", x);
    printf("Short: %d\n", y);
    printf("Long: %ld\n", z);

    return 0;
}
