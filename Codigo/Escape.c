#include "Escape.h"
#include "Pruebas.h"
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
  int SumPoints=0,Pm,fin,Pb;//Pm (igual que Pb) sirve para controlar los puntos de la mesa y que solo se puedan conseguir 1 vez
  int PassB=0,PassC=0,PassH=0,PassR=0,PassP=0,PassM=0,PassD=0,TotalPass=0;//Para contar que se hacen todas las pruebas
  int B=0,C=0,H=0,R=0,P=0,M=0,D=4,intentosD=1,try=0;//Estas variables sirven para que solo se haga la prueba una vez
  Datos player;
  
   printf("Introduce tu nombre: ");
   scanf("%29s[^\n]", player.nombre);
   printf("\nIntroduce la fecha de hoy en formato 'dia mes año': ");
   scanf(" %d %d %d", &player.data.dia, &player.data.mes, &player.data.anno);
   printf("\n");
   //GrabaDatos(player);
  do
  {
    imprime();
    do
    {
       printf("\nIntroduce la letra en MAYUSCULA de la prueba deseada: ");
       scanf(" %c",&prueba);
       if (prueba != 'B' && prueba != 'C' && prueba != 'D' && prueba != 'H' && prueba != 'R' && prueba != 'P' && prueba != 'M' && prueba != 'S' )
       {
           printf("Prueba no valida, intentalo otra vez\n");
       }
       //Se repite hasta que se introduzca una prueba valida.
    } while (prueba != 'B' && prueba != 'C' && prueba != 'D' && prueba != 'H' && prueba != 'R' && prueba != 'P' && prueba != 'M' && prueba != 'S' ); 

    switch (prueba)
    {
    case 'B':
       
        Pb = Baul(&PassB,B);//Permitimos busacar todas las veces que se quiera en el baul
      if (PassB == 1)
        {
          TotalPass++;
        }
      if (Pb == 30)
        {
           B=1; //Si se ha bebido el ron ya no se puede volver a beber ni recibir los puntos.
        }
       SumPoints +=Pb;
        break;
    case 'C':
        if (C == 0)
        {
          SumPoints +=Test_calculo (&PassC);
          if (PassC == 1)
          {
            TotalPass++;
          }
          C++;
        }
        else
         printf("\nEsta prueba ya la has completado\n");
        break;
    case 'D':
        if (D > intentosD) //Comprueba el numero de intentos
     {  
        SumPoints += CajaFuerte(intentosD,&try,&PassD);
      if (PassD == 1)
        {
            TotalPass++;
        }
      if (try == 1)
      {
        intentosD++;
      }
  
     }
      else
        printf("\nEsta prueba ya no se puede repetir.\n");  
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
     else
       printf("\nEsta prueba ya la has completado\n");
        break;
    case 'R':
        if (R == 0)
        {
          SumPoints += Rand(&PassR);
          if (PassR)
          {
            TotalPass++;
          }
          R++;
        }
        else
         printf("\nEsta prueba ya la has completado\n");
        break;
    case 'P':
      if (P == 0)
      {
        SumPoints += Test_pirata (PassD);
        if (PassP == 1)
        {
          TotalPass++;
        }
        P++;
      }
      else
        printf("\nEsta prueba ya la has completado\n");
        
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
  SumPoints = player.puntuacion;
  //GrabaRecord(player);
  final();

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

void final()//Esta funcion te abre un fichero u otro en funcion de si has ganado o perdido el juego
{
   FILE *fperder, *fenhorabuena;
   char c;
   int n=0;
  if (n==1)
  {
      fenhorabuena = fopen("Enhorabuena.txt","r");
   if (fenhorabuena == NULL)
   {
       printf("Error al abrir el fichero.\n");
    }
    else
   {
       printf("\n\n");
       while (fscanf(fenhorabuena,"%c",&c) !=EOF)
       {
           printf("%c",c);
       }
       printf("\n");
    }
    fclose(fenhorabuena);
  }
 else if(n==2)
  {
      fperder = fopen("Perder.txt","r");
   if (fperder == NULL)
   {
       printf("Error al abrir el fichero.\n");
    }
    else
   {
       printf("\n\n");
       while (fscanf(fperder,"%c",&c) !=EOF)
       {
           printf("%c",c);
       }
       printf("\n");
    }
    fclose(fperder);
  }
 else
    printf("Ha habido un error.\n");
}

void imprime()// funcion que imprime el mapa de la habitacion
{
    FILE *pf;
    char c;
    pf = fopen("Room.txt","r");
    if (pf== NULL)

    {
        printf("Error al abrir el fichero.\n");
    }
    else
    {
        printf("\n\n");
       while (fscanf(pf,"%c", &c) != EOF)
       {
            printf("%c",c);
        }
    }
    printf("\n");
    fclose(pf);
}
