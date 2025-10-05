#define LISTAENCADEADA_H
#define MAX 10
typedef struct {
  int elementos[MA];
  int tamanho;
} Lista;
void inicializar_lista(Lista *lista);
int lista_vazia(Lista *lista);
int lista_cheia(Lista *lista);
int insere_elem(Lista *lista, int elem);
int remove_elem(Lista *lista, int elem);
void imprimir_lista(lista *lista);
