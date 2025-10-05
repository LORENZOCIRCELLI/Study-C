#include "../Headers/Lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    Node* lista = cria_lista();

    int opcao;
    char nome[41];

    do{
        printf("\n==== AGENDA DE CONTATOS ====\n");
        printf("1 - Inserir Contato\n");
        printf("2 - Listar Contatos\n");
        printf("3 - Buscar Contato\n");
        printf("4 - Editar Contato\n");
        printf("5 - Remover Contato\n");
        printf("7 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1: {
                Contato novo = le_contato();
                lista = insere_contato(lista, novo);
                break;
            }    
            case 2:{
                lista_contatos(lista);
                break;
            }
            case 3:{
                scanf(" %40[^\n]", nome);
                busca_contato(lista, nome);
                break;
            }
            case 4:{
                atualiza_contato(lista);
                break;
            }
            case 5:{
                lista = remove_contato(lista);
                break;
            }
            case 6:{
                printf("Saindo...\n");
                break;
            }
        }

    }while(opcao != 7);

    libera_lista(lista);

    return 0;
}