#include <stdio.h>

int main(void) {
  int repeticiones = 0;
  int cont = 0;
  printf("\ningresa la cantidad de repeticiones: ");
    scanf("%d", &repeticiones);
  
  while(cont <= repeticiones)
    {
      if(cont <= 0)
      {

        cont = 1;
      }
      printf("\nEl valor de cont: %d" ,cont);
      cont++;
    
      }
  return 0;
}