#include <stdio.h>

int main()
{
  char opcion;

  printf("\n  \t\t     ¡¡¡BIENVENIDOS AL MATE DEL LOCO!!!\n\
                 ¡EL MEJOR JUEGO DE AJEDREZ PROGRAMADO EN C!\n\
                             ¿LISTO PARA JUGAR?\n\n\
            \t a- Empezar Partida\n\
            \t b- Como Jugar\n\
            \t c- Salir del programa\n\
\nIntroduce la letra de la opción deseada: ");

 do
 {
    scanf(" %c",&opcion);
    
    switch (opcion)
    {
     case 'a':
      printf("Has elegido Jugar\n");
      break;

     case 'b':
      printf("Has elegido ver las instrucciones\n");
      break;

     case 'c':
      printf("¡¡GRACIAS POR PROBAR EL JUEGO, ESPERAMOS VERTE PRONTO!!\n");
      break;
  
     default:
      printf("Opción no válida, vuelva a introducir un número\n");
      break;
    }

 } while (opcion != 'c');

    return 0;
}
