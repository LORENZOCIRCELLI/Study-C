#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[100];

    // Take input string
    fgets(string, sizeof(string), stdin);

    printf("%s", string);

    // Iterate through the string and print characters
    for (int i = 0; i < strlen(string); i++) { // Use i < strlen(string) to avoid out-of-bounds access
        if (string[i] == ' ') {  // Check for space character
            printf("\n");  // Print newline if space is encountered
        } else {
            printf("%c", string[i]);  // Print the character
        }
    }

    return 0;
}

