#ifndef LISTA_H
#define LISTA_H

typedef struct Data{
    int dia;
    int mes;
}Data;
typedef struct Contato{
    char nome[40];
    char telefone[15];
    char celular[15];
    char email[40];
    Data data;
}Contato;
typedef struct Node Node;

struct Node{
    Contato contato;
    Node* prox;
};

Node* cria_lista();
Node* insere_contato(Node* node, Contato contato);
void lista_contatos(Node* node);
Node* busca_contato(Node* node, char* nome);
Node* remove_contato(Node* node); 
void atualiza_contato(Node* node);
Contato le_contato();
void libera_lista(Node* node);

#endif