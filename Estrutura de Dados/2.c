#include <stdio.h>
#include <stdlib.h>

int var1, var2;

int main(){

  var1 = 10;
  var2 = 20;

  printf("Endereco 1: %p\n", (void*)&var1);

  printf("Endereco 2: %p\n", (void*)&var2);
 
  if(&var1 > &var2){

    printf("O maior endereco e: %p", (void*)&var1);

  }
  else{

    printf("O maior endereco e: %p", (void*)&var2);

  }

  return 0;

}
