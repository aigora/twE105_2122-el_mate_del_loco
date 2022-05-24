#include <stdio.h>
int main ()
{
  FILE *fbienvenida,*finstrucciones;
  int i;
  char opcion,c,nivel;

  fbienvenida = fopen("Archivos/Bienvenida.txt", "r");

  if (fbienvenida == NULL) 
  {
    printf("Ha habido un problema, por favor intentelo de nuevo\n");
    return -1;
  }
  else
  {
    while (fscanf(fbienvenida,"%c",&c) != EOF)
    {
      printf("%c",c);
    }
  }
  fclose(fbienvenida);

 do
 {
    printf("Elige la opción que desees del menu principal:");
    scanf(" %c",&opcion);
    
    switch (opcion)
    {
     case '1':
      printf("Has elegido Jugar,¡mucha suerte!\n\n");
      break;

     case '2':
      printf("Has elegido ver las instrucciones\n");

      finstrucciones = fopen("Archivos/Instrucciones.txt", "r");

      if (finstrucciones == NULL) 
       {
         printf("Ha habido un problema, por favor intentelo de nuevo\n");
          return -1;
       }
       else
         {
             while (fscanf(finstrucciones,"%c",&c) != EOF)
           {
              printf("%c",c);
           }
         }
        fclose(fbienvenida);
      printf("Introduce '1' para jugar o '3' para salir del programa\n\n");
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
