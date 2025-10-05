#include "../../Headers/a/Orkut.h"

Pessoa* buscaOuCriaPessoa(int id, TipoOrkut* pOrkut) {
    Pessoa* atual = pOrkut->usuarios;
    while (atual != NULL) {
        if (atual->id == id)
            return atual;
        atual = atual->prox;
    }
    Pessoa* nova = (Pessoa*) malloc(sizeof(Pessoa));
    nova->id = id;
    nova->listaAmigos = NULL;
    nova->prox = pOrkut->usuarios;
    pOrkut->usuarios = nova;
    return nova;
}

void adicionaAmigo(Pessoa* p, int idAmigo) {
    NoAmigo* novo = (NoAmigo*) malloc(sizeof(NoAmigo));
    novo->id = idAmigo;
    novo->prox = p->listaAmigos;
    p->listaAmigos = novo;
}

void Relaciona(int Amigo1, int Amigo2, TipoOrkut* pOrkut) {
    Pessoa* p1 = buscaOuCriaPessoa(Amigo1, pOrkut);
    Pessoa* p2 = buscaOuCriaPessoa(Amigo2, pOrkut);
    adicionaAmigo(p1, Amigo2);
    adicionaAmigo(p2, Amigo1);
}
