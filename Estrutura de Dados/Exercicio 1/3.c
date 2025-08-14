#include <stdio.h>

int var1, var2;

int main(){

  scanf("%d", &var1);
  scanf("%d", &var2);

  if(&var1 > &var2){

    printf("\nMaior endereco: %p\n", (void*)&var1);

  }else{

    
    printf("\nMaior endereco: %p\n", (void*)&var2);

  }

  return 0;

}
