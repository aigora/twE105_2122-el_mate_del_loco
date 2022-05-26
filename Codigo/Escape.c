#include "Escape.h"
#include <stdio.h>

typedef struct 
{
  int dia,mes,anno;
}fecha;

typedef struct 
{
  char nombre[30];
  int puntuacion;
  fecha data;
}Datos;

//Funciones del programa
  // Juego (linea 4-65)
  // GrabaDatos (linea 68-)
  // GrabaRecord (linea )
  // Salida (linea )
  // Final (linea )
  // Imprime (linea )
 

void juego()
{
  int salir = 0; //Definimos un booleano para que el bucle continue hasta el final del juego.
  char prueba;
  int SumPoints=0,Pm,fin;//Pm sirve para controlar los puntos de la mesa y que solo se puedan conseguir 1 vez
  int PassN=0,PassC=0,PassH=0,PasR=0,PassP=0,PassM=0,PassD=0,TotalPass=0;//Para contar que se hacen todas las pruebas
  int N=0,C=0,H=0,R=0,P=0,M=0,D=3,intentosD=0;//Estas variables sirven para que solo se haga la prueba una vez
  Datos player;
  
   printf("Introduce tu nombre: ");
   scanf("%29s[^\n]", player.nombre);
   printf("\nIntroduce la fecha de hoy en formato 'dia mes año': ");
   scanf(" %d %d %d", &player.data.dia, &player.data.mes, &player.data.anno);
   printf("\n");
   GrabaDatos(player);
  do
  {
    /* Funcion Imprime */
    do
    {
       printf("\nIntroduce la letra en MAYUSCULA de la prueba deseada: ");
       scanf(" %c",&prueba);
       if (prueba != 'N' && prueba != 'C' && prueba != 'D' && prueba != 'H' && prueba != 'R' && prueba != 'P' && prueba != 'M' && prueba != 'S' )
       {
           printf("Prueba no valida, intentalo otra vez\n");
       }
       //Se repite hasta que se introduzca una prueba valida.
    } while (prueba != 'N' && prueba != 'C' && prueba != 'D' && prueba != 'H' && prueba != 'R' && prueba != 'P' && prueba != 'M' && prueba != 'S' ); 

    switch (prueba)
    {
    case 'N':
        /* Funcion Prueba Nevera */
        break;
    case 'C':
        /* Funcion Prueba Calculo */
        break;
    case 'D':
        if (D > intentosD)
     {  
        SumPoints = CajaFuerte(&intentosD,&PassD);
      if (PassD == 1)
        {
            TotalPass++;
        }
     }
        
        break;
    case 'H':
     if (H==0)
     {
         SumPoints +=Ahorcado(&PassH);
      if (PassH == 1)
        {
            TotalPass++;
        }
        H++;
     }
        break;
    case 'R':
        /* Funcion Prueba Random */
        break;
    case 'P':
        /* Funcion Prueba Preguntas */
        break;
    case 'M':
        
       Pm =  Mesa(&PassM,M);
        if (PassM == 1)
        {
            TotalPass++;
        }
        if (Pm == 150)
        {
           M=1;
        }
        
       SumPoints += Pm;
        break;
    case 'S':
      salir = Salida(SumPoints, TotalPass, &fin);//fin indicara el mensaje final del programa
        break;
    default:
        break;
    }

  } while (salir == 0);
  
  /* Funcion Final */

}

void GrabaDatos(Datos jugador)
{
  FILE *fGrabaDatos;
  
  fGrabaDatos = fopen("Archivos/Records.csv","a");
  //Abrimos el fichero en modo 'add' para que se guarden todas las partidas que se jueguen.
  if (fGrabaDatos == NULL)
  {
    printf("Error al abrir el fichero.\n");
  }
  else
  {
      fprintf("%s,%d,%i,%d,",jugador.nombre,jugador.data.dia,jugador.data.mes,jugador.data.anno);
  }
  fclose(fGrabaDatos);
}

void GrabaRecord(Datos points)
{
   FILE *fGrabaRecord;

  fGrabaRecord = fopen("Archivos/Records.csv","a");
  //Abrimos el fichero en modo 'add' para que se guarden todas las partidas que se jueguen.
  if (fGrabaRecord == NULL)
  {
    printf("Error al abrir el fichero.\n");
  }
  else
  {
      fprintf("%i\n",points.puntuacion);
  }
  fclose(fGrabaRecord);
}

int Salida(int puntos, int n, int *end)
{
    int salida=0;
  if (puntos > 300)
  {
      salida=1;
      end = 1;
  }
  else if (puntos < 300 && n == 7)//En este caso el jugador no tiene los puntos suficientes para salir,
 {                                //pero ya ha realizado todas las pruebas, por lo que no puede conseguir más
      salida=1;
      end = 2;
  }
  else
  {
    printf("No tienes suficientes puntos para salir\n");
    printf("Sigue investigando, el camarote del Capitan Jack Sparrow guarda más secretos\n");
  }
  return salida;
}