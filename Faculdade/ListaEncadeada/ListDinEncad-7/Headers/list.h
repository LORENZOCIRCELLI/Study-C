#ifndef LIST_H
#define LIST_H

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

struct elemento {
    struct aluno dados;
    struct elemento* prox;
};
typedef struct elemento Elemento;
typedef Elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
void imprime_lista(Lista* li);

int busca_maior_nota(Lista *li, struct aluno *al);
int insere_lista_ordenada_nome(Lista *li, struct aluno al);
int concatena_listas(Lista *li1, Lista *li2);
Lista* filtrar_aprovados(Lista *li);

#endif
