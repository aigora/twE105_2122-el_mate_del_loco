#include <stdio.h>
int main ()
{
  FILE *fbienvenida;
  int i,opcion;

  fbienvenida = fopen("Bienvenida.txt", "r");
  if (fbienvenida == NULL) {
    printf("Ha habido un problema, por favor intentelo de nuevo\n");
    return -1;
  }


 do
 {
    scanf(" %i",&opcion);
    
    switch (opcion)
    {
     case '1':
      printf("Has elegido Jugar,¿mucha suerte!\n");
      break;

     case '2':
      printf("Has elegido ver las instrucciones\n");
      break;

     case '3':
      printf("¡¡GRACIAS POR PROBAR EL JUEGO, ESPERAMOS VERTE PRONTO!!\n");
      break;
  
     default:
       printf("El numero introducido no corresponde con ninguna opcion, por favor seleccione otro numero.\n");
      
    }

 } while (opcion != '3');

    return 0;
}
