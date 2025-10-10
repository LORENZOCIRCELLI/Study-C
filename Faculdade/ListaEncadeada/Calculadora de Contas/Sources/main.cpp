#include "../Headers/financial.h"
#include "../Headers/client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    Node_Client* clientes = inicializar_listac();
    Node* contas = inicializar_lista();
    char* filename = "LinkedList.txt";
    
    // Atualizar contas com dados do arquivo
    contas = desserialize(contas, filename);

    int answ = -1;

    while(answ != 0) {
        printf("\n1 - Criar um Cliente!\n");
        printf("2 - Listar Todos os Clientes!\n"); 
        printf("3 - Atualizar um Cliente!\n"); 
        printf("4 - Remover um Cliente!\n"); 
        printf("5 - Criar uma Conta!\n"); 
        printf("6 - Listar Todas as Contas!\n"); 
        printf("7 - Atualizar uma Conta!\n"); 
        printf("8 - Remover uma Conta!\n"); 
        printf("9 - Exibir a Balanca Atual de Gastos de um Cliente!\n"); 
        printf("0 - Sair!\n");
        printf("Escolha: ");
        scanf("%d", &answ);

        switch(answ) {
            case 1: {
                Cliente cliente = ler_cliente();
                criar_cliente(clientes, cliente);
                break;
            }
            case 2:{
                listar_clientes(clientes);
                break;
            }
            case 3:{
                atualizar_cliente(clientes);
                break;
            }
            case 4:{
                clientes = remover_cliente(clientes);
                break;
            }
            case 5:{
                Conta conta = ler_dados();
                contas = criar_conta(contas, conta);
                break;
            }
            case 6:{
                listar_contas(contas);
                break;
            }
            case 7:{
                atualizar_conta(contas);
                break;
            }
            case 8:{
                contas = remover_conta(contas);
                break;
            }
            case 9:{
                break;
            }
            case 0:
                printf("Salvando os arquivos...\n");
                serialize(contas);
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    }
    return 0;
}
