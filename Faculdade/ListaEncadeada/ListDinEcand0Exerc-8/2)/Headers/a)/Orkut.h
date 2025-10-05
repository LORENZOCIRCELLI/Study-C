#ifndef ORKUT_H
#define ORKUT_H

typedef struct NoAmigo {
    int id;
    struct NoAmigo* prox;
} NoAmigo;

typedef struct Pessoa {
    int id;
    NoAmigo* listaAmigos;
    struct Pessoa* prox;
} Pessoa;

typedef struct {
    Pessoa* usuarios;
} TipoOrkut;

#endif