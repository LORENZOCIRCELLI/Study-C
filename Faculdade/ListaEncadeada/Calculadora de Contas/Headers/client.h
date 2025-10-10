#ifndef CLIENT_H
#define CLIENT_H
#include "financial.h"
typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Cliente{

    char nome[100];
    Data data_nascimento;
    char sexo;
    Node* contas;

}Cliente;

typedef struct Node_Client Node_Client;

struct Node_Client{
    Cliente cliente;
    Node_Client* prox;
    Node_Client* ant;
};

Node_Client* inicializar_listac();
Node_Client* criar_cliente(Node_Client* Node_Client, Cliente cliente);
Node_Client* remover_cliente(Node_Client* Node_Client);
void listar_clientes(Node_Client* Node_Client);
void atualizar_cliente(Node_Client* Node_Client);

Cliente ler_cliente();

#endif