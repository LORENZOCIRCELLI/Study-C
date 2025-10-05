#include <stdio.h>
#include "../headers/List.h"

int main() {
    Lista* lista1 = cria_lista();
    struct aluno al;

    struct aluno alunos1[7] = {
        {1,"Maria",7.0,8.0,9.0},
        {2,"Joao",4.0,5.0,3.0},
        {3,"Ana",10.0,9.5,9.0},
        {4,"Carlos",2.0,3.0,4.0},
        {5,"Bruno",6.0,5.0,5.0},
        {6,"Paula",7.5,8.0,7.0},
        {7,"Lucia",4.0,4.5,4.0}
    };
    for(int i=0;i<7;i++)
        insere_lista_final(lista1, alunos1[i]);

    printf("Lista 1:\n");
    imprime_lista(lista1);

    if(busca_maior_nota(lista1, &al)){
        float media = (al.n1+al.n2+al.n3)/3.0;
        printf("Maior média: %s (%.1f)\n", al.nome, media);
    }

    Lista* lista2 = cria_lista();
    struct aluno alunos2[3] = {
        {8,"Fernando",9.0,8.0,7.0},
        {9,"Julia",6.0,7.0,8.0},
        {10,"Tiago",3.0,2.0,4.0}
    };
    for(int i=0;i<3;i++)
        insere_lista_final(lista2, alunos2[i]);

    concatena_listas(lista1, lista2);
    printf("Lista concatenada:\n");
    imprime_lista(lista1);

    Lista* aprovados = filtrar_aprovados(lista1);
    printf("Aprovados:\n");
    imprime_lista(aprovados);

    Lista* lista_ordenada = cria_lista();
    Elemento* no = *lista1;
    while(no != NULL){
        insere_lista_ordenada_nome(lista_ordenada, no->dados);
        no = no->prox;
    }
    printf("Lista ordenada por nome:\n");
    imprime_lista(lista_ordenada);

    libera_lista(lista1);
    libera_lista(lista2);
    libera_lista(aprovados);
    libera_lista(lista_ordenada);

    return 0;
}
