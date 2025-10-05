#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/ListDinEncad.h"

int main() {
    Elemento* agenda = cria_agenda();
    int opcao;
    char nome[41];

    do {
        printf("\n==== AGENDA DE CONTATOS ====\n");
        printf("1 - Inserir Contato\n");
        printf("2 - Listar Contatos\n");
        printf("3 - Buscar Contato\n");
        printf("4 - Editar Contato\n");
        printf("5 - Remover Contato\n");
        printf("6 - Remover Contatos Duplicados\n");
        printf("7 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                Contato novo = le_contato();
                agenda = insere_contato(agenda, novo);
                printf("\nContato inserido com sucesso!\n");
                break;
            }
            case 2:
                lista_contatos(agenda);
                break;
            case 3: {
                printf("\nDigite o nome do contato a ser buscado: ");
                scanf(" %40[^\n]", nome);
                Elemento* encontrado = busca_contato(agenda, nome);
                if (encontrado != NULL) {
                    exibe_contato(encontrado->info);
                } else {
                    printf("\nContato nao encontrado!\n");
                }
                break;
            }
            case 4:
                atualiza_contato(agenda);
                break;
            case 5:
                agenda = remove_contato(agenda);
                break;
            case 6:
                agenda = remove_duplicados(agenda);
                break;
            case 7:
                printf("\nSaindo da agenda...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 7);

    libera_agenda(agenda);
    return 0;
}
