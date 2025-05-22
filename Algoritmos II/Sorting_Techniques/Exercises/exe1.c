#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int vetor[15], char *nome){


    printf("%s = [", nome);
    for(int i = 0 ; i< 14 ; i++){

        printf("%d, ", vetor[i]);


    }
    printf("%d]\n", vetor[14]);

}

void arruma_vetor(int vetor[15]){

    for(int i = 0 ; i < 15 ; i++){

        int aux = vetor[i];
        int j = i;
        while(j>0 && vetor[j-1] % 2 != 0){

            vetor[j] = vetor[j -1];
            j--;

        }
        vetor[j] = aux;

    }

}

int main(){

    int  vet[15];

    for(int i = 0 ; i < 15 ; i++){

        vet[i] = rand() % 100;

    }

    imprime_vetor(vet, "vetor");
    arruma_vetor(vet);
    imprime_vetor(vet, "vetor");

    return 0;

}