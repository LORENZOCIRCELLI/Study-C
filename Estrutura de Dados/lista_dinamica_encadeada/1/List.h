#define max 60
#define LIST_H

typedef struct{

  char nome[50];
  int idade;

}aluno;

typedef struct elemento *Lista;

Lista cria_lista();
void libera_lista(Lista *li);

void imprime_lista(Lista *li);


