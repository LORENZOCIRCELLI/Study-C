#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/List.h"

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    } else {
        Elemento *aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
    }
    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL) return;
    Elemento* no = *li;
    while(no != NULL){
        float media = (no->dados.n1 + no->dados.n2 + no->dados.n3)/3.0;
        printf("Mat:%-4d Nome:%-10s Notas:[%.1f, %.1f, %.1f] Media: %.1f\n",
               no->dados.matricula,
               no->dados.nome,
               no->dados.n1, no->dados.n2, no->dados.n3,
               media);
        no = no->prox;
    }
    printf("-------------------------\n");
}


int busca_maior_nota(Lista *li, struct aluno *al){
    if(li == NULL || *li == NULL) return 0;
    Elemento* no = *li;
    Elemento* melhor = no;
    float maior_media = (no->dados.n1 + no->dados.n2 + no->dados.n3)/3.0;

    no = no->prox;
    while(no != NULL){
        float media = (no->dados.n1 + no->dados.n2 + no->dados.n3)/3.0;
        if(media > maior_media){
            maior_media = media;
            melhor = no;
        }
        no = no->prox;
    }
    *al = melhor->dados;
    return 1;
}

int insere_lista_ordenada_nome(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL) return 0;
    no->dados = al;
    if((*li) == NULL){
        no->prox = NULL;
        *li = no;
        return 1;
    }
    Elemento *ant = NULL, *atual = *li;
    while(atual != NULL && strcmp(atual->dados.nome, al.nome) < 0){
        ant = atual;
        atual = atual->prox;
    }
    if(ant == NULL){
        no->prox = *li;
        *li = no;
    } else {
        no->prox = atual;
        ant->prox = no;
    }
    return 1;
}

int concatena_listas(Lista *li1, Lista *li2){
    if(li1 == NULL || li2 == NULL) return 0;
    if(*li2 == NULL) return 1;
    if(*li1 == NULL){
        *li1 = *li2;
        return 1;
    }
    Elemento* aux = *li2;
    while(aux != NULL){
        insere_lista_final(li1, aux->dados);
        aux = aux->prox;
    }
    return 1;
}

Lista* filtrar_aprovados(Lista *li){
    if(li == NULL) return NULL;
    Lista* nova = cria_lista();
    if(nova == NULL) return NULL;
    Elemento* no = *li;
    while(no != NULL){
        float media = (no->dados.n1 + no->dados.n2 + no->dados.n3)/3.0;
        if(media >= 5.0){
            insere_lista_final(nova, no->dados);
        }
        no = no->prox;
    }
    return nova;
}
