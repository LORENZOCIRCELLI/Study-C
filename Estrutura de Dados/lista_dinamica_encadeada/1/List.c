#include "List.h"
struct elemento{

  struct aluno dados;
  struct elemento *prox;

}

typedef struct elemento Elem;

Lista *cria_lista(){

  Lista *li = (*Lista) malloc(sizeof(Lista))

  if(li != NULL){

    *li = NULL;

  }

  return li;

}

void libera_lista(Lista *li){

  if(li != NULL){


    Elem *no;
    while((*li) != NULL){

      *no = li;
      *li = *li->prox;
      free(no);

    }
    free(li)
  }

}

int lista_vazia(Lista *li){

  if(li == NULL){

    return 1;

  }
  if(*li == NULL){

    return 1;

  }

  return 0;

}

void imprime_lista(Lista *li){

  if(li == NULL || *li == NULL){

    printf("Lista Vazia!\n");
    return;

  }

  Elem *no = *li;
  while(no != NULL){

    printf("Matricula: %d\n", no->dados.matricula);
    printf("Nome: %s\n", no->dados.nome);
    printf("Nota1: %.2f\n", no->dados.n1);
    printf("Nota2: %.2f\n", no->dados.n2);
    printf("Nota3: %.2f\n", no->dados.n3);
    printf("----------------------------\n");

    no = no->prox;

  }

}

int insere_lista_ordenada(Lista *li, struct aluno al){

  if(li == NULL){

    return 0;

  }

  Elem *no = (Elem*) malloc(sizeof(Elem));

  if(no == NULL){

    return 0;

  }

  no -> dados = al;

  if((*li) == NULL){

    no -> prox = NULL;
    *li = no;
    return 1;

  }
  else{

    Elem *ant, *atual = *li;

    while(atual != NULL && atual -> dados.matricula < al.matricula){

      ant = atual;
      atual = atual->prox;

    }
    if(atual == *li){

      no->prox = (*li);
      *li = no;

    }else{

      no->prox = atual;
      ant-prox = no;

    }
    return 1;
  }

}

int insere_lista_final(Lista *li, struct aluno al){

  if(li == NULL){

    return 0;

  }
  Elem *no;
  no = (Elem*) malloc(sizeof(Elem));

  if()
  

}
