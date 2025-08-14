#include <stdio.h>

int var1, var2;

int main(){

  scanf("%d\n", &var1);
  scanf("%d\n", &var2);

  if(&var1 > &var2){

    printf("Maior endereco: %p\n", (void*)&var1);

  }else{

    
    printf("Maior endereco: %p\n", (void*)&var2);

  }

  return 0;

}
