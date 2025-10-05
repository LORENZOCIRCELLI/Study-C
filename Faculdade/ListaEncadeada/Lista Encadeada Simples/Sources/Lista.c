#include "../Headers/Lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
Node* cria_lista(){
    return NULL;
}
Node* insere_contato(Node* node, Contato contato){
    Node* novo = (Node*) malloc(sizeof(Node));
    if(novo == NULL){
        printf("Falha ao alocar memória!");
        exit(1);
    }
    novo->contato = contato;
    novo->prox = NULL;
    if(node == NULL || strcmp(contato.nome, node->contato.nome)<0){
        novo->prox = node;
        return novo;
    }
    Node* atual = node;
    while(atual->prox != NULL && strcmp(contato.nome, atual->prox->contato.nome)>0){
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    return node;
}
void lista_contatos(Node* node){
    if(node == NULL){
        printf("A lista esta vazia");
        return;
    }
    Node* atual = node;
    int counter = 1;
    while(atual != NULL){

        printf("---------------------------------------\n");
        printf("Nome: %s\n", atual->contato.nome);
        printf("Telefone: %s\n", atual->contato.telefone);
        printf("Celular: %s\n", atual->contato.celular);
        printf("Email: %s\n", atual->contato.email);
        printf("Data: %d:%d\n", atual->contato.data.dia, atual->contato.data.mes);
        printf("---------------------------------------\n");

        atual = atual->prox;
        counter++;
    }
}

Node* busca_contato(Node* node, char* nome){
    if(node == NULL){
        printf("Lista vazia!");
        return NULL;
    }
    Node* atual = node;
    while(atual != NULL){
        if(strcmp(atual->contato.nome, nome)==0){
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}
Node* remove_contato(Node* node){
    if(node == NULL){
        printf("Lista vazia");
        return node;
    }

    char nome[41];
    printf("Insira o nome do contato que deseja remover: ");
    scanf(" %40[^\n]", nome);

    if(strcmp(node->contato.nome, nome) == 0){
        Node* temp = node;
        node = node->prox;
        free(temp);
        printf("Contato removido com sucesso!\n");
        return node;
    }

    Node* atual = node->prox;
    Node*anterior = node;
    while(atual != NULL && strcmp(atual->contato.nome, nome) != 0){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("Contato não encontrado na agenda");
        return node;
    }

    anterior->prox = atual->prox;
    free(atual);
    printf("Contato removido com sucesso!");
    return node;
    
}

void atualiza_contato(Node* node){
    if(node == NULL){
        printf("Lista vazia!\n");
        return;
    }
    char nome[41];
    printf("Insira o nome do contato que você deseja atualizar: ");
    scanf(" %40[^\n]", nome);

    Node* contato = busca_contato(node, nome);
    if(contato == NULL){
        printf("O contato nao existe!\n");
        return;
    }

    printf("Nome: %s\n", contato->contato.nome);
    printf("Telefone: %s\n", contato->contato.telefone);
    printf("Celular: %s\n", contato->contato.celular);
    printf("Email: %s\n", contato->contato.email);
    printf("Data: %d/%d\n", contato->contato.data.dia, contato->contato.data.mes);

    printf("Insira os novos dados: \n");

    printf("Nome: ");
    scanf(" %40[^\n]", contato->contato.nome);
    printf("Telefone: ");
    scanf(" %15[^\n]", contato->contato.telefone);
    printf("Celular: ");
    scanf(" %15[^\n]", contato->contato.celular);
    printf("Email: ");
    scanf(" %40[^\n]", contato->contato.email);
    printf("Data: \n");
    printf("Dia: ");
    scanf("%d", &contato->contato.data.dia);
    printf("Mes: ");
    scanf("%d", &contato->contato.data.mes);

}


Contato le_contato(){
    
    Contato contato;
    
    printf("Nome: ");
    scanf(" %40[^\n]", contato.nome);
    printf("Telefone: ");
    scanf(" %14[^\n]", contato.telefone);
    printf("Celular: ");
    scanf(" %14[^\n]");
    printf("Email: ");
    scanf(" %40[^\n]", contato.email);
    printf("Data:\n");
    printf("Dia: ");
    scanf("%d", &contato.data.dia);
    printf("Mes: ");
    scanf("%d", &contato.data.mes);

    return contato;

}

void libera_lista(Node* node){
    Node* atual = node;
    Node* prox;
    while(atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}