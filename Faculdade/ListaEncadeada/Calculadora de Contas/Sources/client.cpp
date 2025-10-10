#include "../Headers/client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* inicializar_lista(Node* node){
    return NULL;
}

Node* criar_cliente(Node* node, Cliente cliente){
    
    Node* novo = (Node*) malloc(sizeof(Node));

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

    Node* atual = node;

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novo;
    novo->ant = atual;

    return node;

}

Node* remover_cliente(Node* node){
    if(node ==NULL){
        printf("A lista esta vazia!\n");
        return node;
    }
}