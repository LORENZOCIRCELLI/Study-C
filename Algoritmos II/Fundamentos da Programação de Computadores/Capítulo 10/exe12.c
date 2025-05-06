#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string [100];
    char string_nova [200];
    char mes [20];

    printf("Insira a sua data de aniversário (dd/MM/yyyy): ");
    scanf("%[^\n]", string);

    if(string[3] == '0' && string[4] == '1'){

        strcpy(mes, "JANEIRO");

    }
    else if(string[3] == '0' && string[4] == '2'){

        strcpy(mes, "FEVEREIRO");


    }
    else if(string[3] == '0' && string[4] == '3'){

        strcpy(mes, "MARÇO");


    }
    else if(string[3] == '0' && string[4] == '4'){

        strcpy(mes, "ABRIL");


    }
    else if(string[3] == '0' && string[4] == '5'){

        strcpy(mes, "MAIO");


    }
    else if(string[3] == '0' && string[4] == '6'){

        strcpy(mes, "JUNHO");


    }
    else if(string[3] == '0' && string[4] == '7'){

        strcpy(mes, "JULHO");


    }

    else if(string[3] == '0' && string[4] == '8'){

        strcpy(mes, "AGOSTO");


    }
    else if(string[3] == '0' && string[4] == '9'){

        strcpy(mes, "SETEMBRO");


    }
    else if(string[3] == '1' && string[4] == '0'){

        strcpy(mes, "OUTUBRO");


    }
    else if(string[3] == '1' && string[4] == '1'){

        strcpy(mes, "NOVEMBRO");


    }
    else if(string[3] == '1' && string[4] == '2'){

        strcpy(mes, "DEZEMBRO");


    }
    else{

        printf("mes invalido!\n");
        return 1;

    }

    snprintf(string_nova, sizeof(string_nova), "%.2s/%s/%.4s", string, mes, string + 6);

    printf("%s", string_nova);



}
