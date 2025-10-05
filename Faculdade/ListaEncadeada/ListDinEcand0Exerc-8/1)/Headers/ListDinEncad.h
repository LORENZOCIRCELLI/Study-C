#ifndef LISTDINENCAD_H
#define LISTDINENCAD_H

typedef struct {
    int dia;
    int mes;
} Data;

typedef struct {
    char nome[41];
    char telefone[16];
    char celular[16];
    char email[41];
    Data dataAniversario;
} Contato;

typedef struct elemento {
    Contato info;
    struct elemento* prox;
} Elemento;


Elemento* cria_agenda();
Elemento* insere_contato(Elemento* lista, Contato contato);
void lista_contatos(Elemento* lista);
Elemento* busca_contato(Elemento* lista, char* nome);
Elemento* remove_contato(Elemento* lista);
void atualiza_contato(Elemento* lista);
Elemento* remove_duplicados(Elemento* lista);
void libera_agenda(Elemento* lista);
Contato le_contato();
void exibe_contato(Contato contato);

#endif
