#include "ListDinEncad.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

  struct aluno al, a[4] = {
    {2, "Andre", 9.5, 77.8, 8.5},
    {4, "Ricardo", 7.5, 8.7,6.8},
    {1, "Bianca", 9.7,6.7,8.4},
    {3, "Ana", 5.7,6.1,7.4}
  };

  Lista *li = cria_lista();
  printf("Tamanho: %d\n\n\n", tamanho_lista(li));
  int i;
  for(i = 0; i < 4 ; i++){

    insere_lista_ordenada(li, a[i]);

  }
  return 0;

}
