#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string [100];
    char nova_string[200];
    
    scanf("%[^\n]", string);

    for(int i = 0, j = 0 ; i < strlen(string) ; i++){

        if(string[i] == 'a' || string[i] == 'A'){

            nova_string[i] = '1';

        }
        else if(string[i] == 'a' || string[i] == 'A'){

            nova_string[j++] = '1';

        }
        else if(string[i] == 'e' || string[i] == 'E'){

            nova_string[j++] = '2';

        }
        else if(string[i] == 'i' || string[i] == 'I'){

            nova_string[j++] = '3';

        }
        else if(string[i] == 'o' || string[i] == 'O'){

            nova_string[j++] = '4';

        }
        else if(string[i] == 'u' || string[i] == 'U'){

            nova_string[j++] = '5';

        }
        else{


            nova_string[j++] = string[i];

        }



    }

    printf("%s\n\n  ", nova_string);

}
