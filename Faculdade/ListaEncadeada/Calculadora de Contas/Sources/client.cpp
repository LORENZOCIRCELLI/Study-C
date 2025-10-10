#include "../Headers/client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node_Client* inicializar_listac(){
    return NULL;
}

Node_Client* criar_cliente(Node_Client* node, Cliente cliente){
    
    Node_Client* novo = (Node_Client*) malloc(sizeof(Node_Client));

    if(novo == NULL){
        printf("Falha ao alocar memoria para a operacao!\n");
        return node;
    }

    novo->cliente = cliente;
    novo->prox = NULL;
    novo->ant = NULL;

    if(node == NULL){
        return novo;
    }

    Node_Client* atual = node;

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novo;
    novo->ant = atual;

    return node;

}

Node_Client* remover_cliente(Node_Client* node){

    if(node ==NULL){
        printf("A lista esta vazia!\n");
        return node;
    }

    char nome[100];
    printf("Insira o nome do cliente que deseja remover: ");
    scanf(" %99[^\n]", nome);

    Node_Client* atual = node;

    while(atual != NULL && strcmp(atual->cliente.nome, nome)!=0){
        atual=atual->prox;
    }

    if(atual==NULL){
        printf("Cliente nao encontrado!\n");
        return node;
    }

    if(atual->ant != NULL){
        atual->ant->prox=atual->prox;
    }else{
        node = atual->prox;
    }

    if(atual->prox!=NULL){
        atual->prox->ant = atual->ant;
    }

    free(atual);
    return node;

}

Cliente ler_cliente(){
    Cliente cliente;
    printf("Insira o nome do cliente: ");
    scanf(" %^99[^\n]", cliente.nome);
    printf("Insira a sua data de nascimento(formato: dd/mm/yy): ");
    scanf("%d/%d/%d", &cliente.data_nascimento.dia,&cliente.data_nascimento.mes,&cliente.data_nascimento.ano);
    printf("Insira o seu sexo(formato: M ou F): ");
    scanf(" %c", &cliente.sexo);
    return cliente;
}

void listar_clientes(Node_Client* node){
    
    if(node == NULL){
        printf("A lista esta vazia!\n");
        return;
    }
    Node_Client* atual = node;

    while(atual!=NULL){
        printf("-----------------------------------\n");
        printf("Cliente:\n");
        printf("Nome: %s\n", atual->cliente.nome);
        printf("Data de nascimento: %d/%d/%d\n", atual->cliente.data_nascimento.dia,atual->cliente.data_nascimento.mes,atual->cliente.data_nascimento.ano);
        printf("Sexo: %c\n", atual->cliente.sexo);
        printf("-----------------------------------\n");
        atual=atual->prox;
    }
    return;
}

void atualizar_cliente(Node_Client* node){
    if(node == NULL){
        printf("A lista esta vazia!\n");
        return;
    }
    char nome[100];
    printf("Insira o nome do cliente que deseja atualizar: ");
    scanf(" %99[^\n]", nome);
    Node_Client*atual = node;

    while(atual!=NULL && strcmp(nome, atual->cliente.nome)!=0){
        atual = atual->prox;
    }

    printf("Insira o nome: ");
    scanf(" %99[^\n]", atual->cliente.nome);
    printf("Insira a sua data de nascimento(formato: dd/mm/yy): ");
    scanf("%d/%d/%d", &atual->cliente.data_nascimento.dia,&atual->cliente.data_nascimento.mes,&atual->cliente.data_nascimento.ano);    
    printf("Insira o seu sexo: ");
    scanf(" %c", &atual->cliente.sexo);
    return;
}