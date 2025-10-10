#include "../Headers/financial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Node* lista = inicializar_lista();    
    char* filename = "LinkedList.txt";
    
    // Atualizar lista com dados do arquivo
    lista = desserialize(lista, filename);

    int answ = 0;

    while(answ != 9) {
        printf("\n1 - Criar uma conta!\n");
        printf("2 - Listar as suas contas!\n"); 
        printf("3 - Media de todas as contas!\n"); 
        printf("4 - Remover uma conta!\n"); 
        printf("5 - Atualizar uma conta!\n"); 

        printf("9 - Sair!\n");
        printf("Escolha: ");
        scanf("%d", &answ);

        switch(answ) {
            case 1: {
                Conta conta = ler_dados();
                lista = criar_conta(lista, conta);
                break;
            }
            case 2:{
                listar_contas(lista);
                break;
            }
            case 3:{
                calcular_media(lista);
                break;
            }
            case 4:{
                lista = remover_conta(lista);
                break;
            }
            case 5:{
                atualizar_conta(lista);
                break;
            }
            case 9:
                printf("Salvando os arquivos...\n");
                serialize(lista);
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
