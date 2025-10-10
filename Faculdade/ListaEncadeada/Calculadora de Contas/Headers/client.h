#ifndef CLIENT_H
#define CLIENT_H

typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Cliente{

    char nome[100];
    Data data_aniversario;
    char sexo;

}Cliente;

typedef struct Node Node;

struct Node{
    Cliente cliente;
    Node* prox;
    Node* ant;
};

Node* inicializar_lista();
Node* criar_cliente(Node* node, Cliente cliente);
Node* remover_cliente(Node* node);
void listar_clientes(Node* node);
void atualizar_cliente(Node* node);

Cliente ler_cliente();

#endif