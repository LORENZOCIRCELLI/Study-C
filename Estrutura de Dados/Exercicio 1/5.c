#include <stdio.h>
#include <stdlib.h>

int var1, var2; 

void analysis(int *var1 ,int *var2){

  int temp;

  if(!(*var1 > *var2)){

    temp = *var1;
    *var1= *var2;
    *var2 = temp;
    printf("\nConversao feita com sucesso!\n\n");

  }

}

int main(){

  scanf("%d", &var1);
  scanf("%d", &var2);

  analysis(&var1,&var2);

  printf("\nVar1: %d", var1);
  printf("\nVar2: %d\n\n", var2);

  return 0;

}
