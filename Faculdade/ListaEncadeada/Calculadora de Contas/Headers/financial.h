#ifndef FINANCIAL_H
#define FINANCIAL_H

typedef struct Conta{

    char nome[100];
    float valor;

}Conta;

typedef struct Node Node;

struct Node{
    Conta conta;
    Node* prox;
};

Node* inicializar_lista();
Node* criar_conta(Node* node, Conta conta);
void listar_contas(Node* node);
void atualizar_conta(Node* node);
Node* remover_conta(Node* node);
void calcular_media(Node* node);

/*
How to save the contents of a Linked List inside a .txt file
*/
void serialize(Node* node);
Node* desserialize(Node* node, char* path);

#endif