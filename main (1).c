#include <stdio.h>

// Este programa da la cantidad mayor de pesos o dolares, usa variables enteras, if, y funcion return
int mayor(int pesos, int dolares)// Creacion de la variable en enteros, pesos y dolares
{

  dolares = (dolares * 58);// Operación que multiplica 1 dolar por lo que pale en pesos
  if(pesos > dolares)
  {
    return pesos;
    }
  else{
    return dolares;
// Condicion con operación relacional, si pesos es mayor que dolares, opera la funcion de devolver la cantidad pesos a la pantalla, y else si no se cumple, devuelva la cantidad dolares
  
}
  }
int main(void) {// Inicia el programa
int numero = 0;// Creacion de variable numero
  numero = mayor(1000,10);// Asignacion de cantidad a las variables
  printf("%d\n", numero);// imprime la información en la pantalla
  
  return 0;// Termina el programa
}