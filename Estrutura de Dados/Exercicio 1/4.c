#include <stdio.h>

int var1 ,var2, temp;

void switchVariables(int*var1, int*var2){

  temp = *var1;
  *var1 = *var2;
  *var2 = temp;
  
}

int main(){

  scanf("%d", &var1);
  scanf("%d", &var2);
 
  printf("\nA: %d", var1);
  printf("\nB: %d\n\n", var2);
  
  switchVariables(&var1, &var2);

  printf("\nA: %d", var1);
  printf("\nB: %d\n\n", var2);
  
  return 0;

}
