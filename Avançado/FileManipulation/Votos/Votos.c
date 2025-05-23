#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int pessoas[7] = {0};
    float porcentagem[7] = {0};
    char *nomes[7] = {"Felipe", "Giovana", "Alice", "Eva", "Bruno", "Carla", "Diego"};
    
    int totalVotos = 1000;

typedef struct {

    char nome [20];

} candidato;



candidato ListaDeCandidatos[1000];

typedef struct {

    char nome[20];
    int votos;
    float porcentagem;

}data;

data dados[7];


void load_db(char path [10]){

    FILE *file = fopen(path, "r");
    
    int i = 0;

    while(i < 1000 && fgets(ListaDeCandidatos[i].nome, sizeof(ListaDeCandidatos[i].nome), file) != NULL){

        ListaDeCandidatos[i].nome[strcspn(ListaDeCandidatos[i].nome, "\n")] = '\0';
        i++;

    }

    fclose(file);

}

void contadorDeVotos(){



    for(int i = 0 ; i < 1000 && ListaDeCandidatos[i].nome[0] != '\0'; i++){

        for(int j = 0 ; j < 7 ; j++){

            if(strcmp(ListaDeCandidatos[i].nome, nomes[j]) == 0){

                pessoas[j]++;

            }

        }


    }

        for(int i = 0; i < 7; i++){

            porcentagem[i] = (pessoas[i] * 100.0f) / totalVotos;

        }


    float totalValidacao = 0.0;


}

void segundoTurno(){
    int ctrl = 0;
    for(int i = 0 ; i < 7 ; i++){

        if(porcentagem[i] >= 50.0){

            ctrl = 1;

        }

    }
    if(ctrl == 0){

        printf("\t\tHAVERA SEGUNDO TURNO");

    }
    else{

        printf("\t\tNAO HAVERA SEGUNDO TURNO");

    }


}

void load_Data(){

    for(int i = 0 ; i < 7 ; i++){

        strcpy(dados[i].nome, nomes[i]);
        dados[i].votos = pessoas[i];
        dados[i].porcentagem = porcentagem[i];

    }

}

void insertion_sort(data array[], int n) {
    for (int i = 1; i < n; i++) {
        data key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j].votos < key.votos) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}



int main() {
    system("cls");
    load_db("votos.csv");
    contadorDeVotos();
    load_Data();

    insertion_sort(dados, 7);
    printf("\n-----------------------------------------------------\n");

    printf("\n\tRanking dos candidatos por votos:\n");
    
    printf("\n-----------------------------------------------------\n\n");

    printf("Nome\t\tVotos\t\t\tPorcentagem\t\t\n");

    for (int i = 0 ; i < 7 ; i++) {
        printf("%s\t\t%d votos \t\t(%.2f%%)\n", dados[i].nome, dados[i].votos, dados[i].porcentagem);
    }
    printf("\n-----------------------------------------------------\n");

    segundoTurno();
    printf("\n-----------------------------------------------------\n\n\n\n");


    return 0;
}