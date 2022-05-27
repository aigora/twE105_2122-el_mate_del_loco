#include "Pruebas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
  char preguntas[200];
  int soluciones;
} calculo;

typedef struct
{
  char preguntas[200];
  char opciones[150];
  char soluciones;
} cuestionario;

//Funciones de las pruebas
  // 'M' Mesa (linea 29-86)
  // 'H' Ahorcado (linea 88-202)
  // 'D' CajaFuerte (linea 204-278)
  // 'N' Baul (linea 280-337 )
  // 'P' Preguntas (linea 339-380)
  // 'C' Calculo (linea 382-417)
  // 'R' Random (linea 419-469)


int Mesa(int *pass,int M)//Uso este puntero para contar que el jugador vaya haciendo todas las pruebas, asi sabremos si el jugador puede conseguir mas puntos
{                  //o ya ha terminado el juego, al no tener este la posibilidad de conseguir una puntuación mejor.
   int puntos=0,j; 
   FILE *fMesa;
   char c,opcion;
   
   fMesa = fopen("PruebaMesa.txt","r"); //Fichero para poder cambiar el contenido rapidamente y este más ordenado.
   if (fMesa == NULL)
   {
       printf("Error al abrir el fichero.\n");
    }
   else
   {
       while (fscanf(fMesa,"%c",&c) !=EOF)
       {
           printf("%c",c);
       }
       printf("\n");
    } 
    fclose(fMesa); 
   
   do
   {
      printf("Elige donde buscar: ");
      scanf(" %c",&opcion); 
      if (opcion != 'a' && opcion != 'b' && opcion != 'c')
      {
          printf("\nArgg pirata ese cajón esta cerrado con llave\n\n");
      } 
      //Se le pide al usuario que introduzca una opcion hasta que sea una valida.
   } while (opcion != 'a' && opcion != 'b' && opcion != 'c');

    
       switch (opcion)
   {
   case 'a':
        printf("\nEntre los papeles has encontrado una nota que pone 'perlita' ¿Sera alguna palabra en clave?..\n\n");
       break;
   case 'b':
       printf("\nAqui debajo solo hay botellas de ron vacias\n\n");
       break;
    case 'c':
       if (M==0) //Usamos esta variable para que solo se pueda conseguir los puntos una vez.
       {
            printf("\n¡¡¿COMO?!! !Has encontrado la famosa brujula de Jack Sparrow!\n");
            printf("Seguro que te ayuda a salir de aqui\n");
            puntos = 150;
            printf("\n+150 puntos\n\n");
            *pass+=1;
       }
        else
        printf("Aqui ya no hay nada interesante\n");
       break;
   default:
       break;
   }
   return puntos;//Tiene los puntos como output, los cuales se sumaran a los totales. El resto de pruebas seguiran el mismo procedimiento.
}

int Ahorcado(int *pass)
{
   int puntos = 45,fallos=0,i,l,error,fin=0;
   char letra,palabra[]="laperlanegra",word[13],adivinar;

   printf("\nBienvenido al juego del ahorcado, si no consigues adivinar la palabra, ¡¡Seras ahoracado por la armada Inglesa!!\n");
   printf("\nTienes 8 intentos, ¡necesitaras un lapiz y un papel!\n");
   printf("_ _   _ _ _ _ _   _ _ _ _ _\n\n");

  do
  {   
      do
      {
           printf("¿Que quieres adivinar la palabra(0) o una letra(1)\n");
           scanf(" %c",&adivinar);
           if (adivinar !='0' && adivinar != '1')
           {
             printf("\nOpcion no valida, vuelve a intentarlo\n");
           }
      } while (adivinar !='0' && adivinar != '1');
      
      if (adivinar == '0')
      {
          printf("\nIntroduce la palabra en minusculas y con todas las letras juntas: ");
          scanf("%13s",word);
          error = 0;
          for ( i = 0; i < 13; i++)
          {
              if (word[i] != palabra[i])
             {
                error = 1;
             } 
         }
        if (error == 0)
        {
            printf("\nSii, esa palabra es la correcta, y ademas ahora mismo estas subido en la perla negra.\n");
            fin=1; //booleano para terminar el bucle do-while al adivinar la palabra
            printf("\n\n+%d puntos\n\n",puntos);//Enseñamos los puntos que gana el jugador
        }
       else if(error == 1)
       {
           printf("\nNo,esa palabra es incorrecta, cuidado que te quedan menos intentos\n");
           fallos++;//Contamos los fallos para que a los 8 intentos se cierre la prueba.
           puntos -=5;
       } 
       else
       {
           printf("¡Se te han acabado los intentos!, la palabra secreta se la llevara Jack Sparrow a la tumba.\n\n");
       }  
      }
     else
      {
       printf("Introduce una letra en minusculas: ");
       scanf(" %c",&letra);
        l=0;
        for ( i = 0; i < 13; i++)
          {
            if (letra == palabra[i])
             {
              l=1;
             }   
          }
        if (l==1)
         {
          printf("\nSi!! la '%c' es correcta\n",letra);
          if (letra == 'l')
           {
             printf("Asi esta posicionada\n");
             printf("l _   _ _ _ l _   _ _ _ _ _\n\n");
           }
          else if (letra == 'a')
           {
             printf("Asi esta posicionada\n");
             printf("_ a   _ _ _ _ a   _ _ _ _ a\n\n");
           }
          else if (letra == 'p')
           {
              printf("Asi esta posicionada\n");
              printf("_ _   p _ _ _ _   _ _ _ _ _\n\n");
           }
          else if (letra == 'e')
           {
              printf("Asi esta posicionada\n");
              printf("_ _   _ e _ _ _   _ e _ _ _\n\n");
           }
          else if (letra == 'r')
          {
              printf("Asi esta posicionada\n");
              printf("_ _   _ _ r _ _   _ _ _ r _\n\n");
          }
          else if (letra == 'n')
          {
              printf("Asi esta posicionada\n");
              printf("_ _   _ _ _ _ _   n _ _ _ _\n\n");
          }
          else if (letra == 'g')
          {
              printf("Asi esta posicionada\n");
              printf("_ _   _ _ _ _ _   _ _ g _ _\n\n");
          }
        
        }
        else
         {
           printf("Esa letra no esta\n");
           fallos++;
           puntos -= 5;//se penaliza con 5 puntos por cada fallo
         }
      }
      
   } while (fallos < 8 && fin == 0);
  
   *pass+=1;
  return puntos;
}

int CajaFuerte(int intentos,int *try, int *pass)//uso el puntero intentos para que estos se guarden aunque salgas de la prueba.
{
    char probar,clave[7]="perlita",combinacion[10];
    int i,error,j=0,puntos=0;
    *try=0;

    printf("\nEs una especie de caja fuerte, y parece que tiene una combinación de letras para abrise...\n");
      
    do
    {
        printf("\nSi quieres intentar adivinar la combinación introduce '1', en caso contrario introduce '0'\n");
        //Pido que el usuario elija adivinar o no, ya que solo tiene 3 intentos, asi tiene la oportunidad de buscar la contraseña.
        do
        {
            error = 0;
            scanf(" %c",&probar);
            if (probar != '1' && probar != '0')
            {
                printf("Input no valido, vielve a intentarlo.\n");
            }
            
        } while (probar != '1' && probar != '0');
        
        if (probar == '1')
        {
            
            printf("intento nº: %d\n",intentos);
            printf("Introduce la combinación: ");
            scanf("%10s",combinacion);
            for ( i = 0; i < 7; i++)
            {
                if (clave[i] != combinacion[i])
                {
                   error=1;
                }//Comprueba letra por letra si la clave es la correcta
                
            }
            if (error == 1 )//Si hay algun error lo comunica, da una pista y suma un intento.
            {
                printf("No se ha abierto...Parece que esa no es la combinación adecuada.\n");
                printf("Parece que si fallas más de tres veces se cerrara para siempre.\n");
                printf("Prueba a buscar por el camarote, el capitan sparrow esconde muchos secretos\n");
               *try+=1;
               probar = '0';
            }
            else if(error == 0)
            {
               printf("\n¡Has adivinado la combinación!, que suerte has tenido de encontrar esa nota en la mesa del Capitan Sparrow\n");
               printf("Has encontrado lo que queda del tesoro de Jack Sparrow, unos miseros %d puntos..\n",puntos);
               
               //Penaliza 10 puntos por intento fallido
               if (intentos == 1)
               {
                   puntos = 95;
               }
               else if (intentos == 2)
               {
                   puntos= 85;
               }
               else if (intentos == 3)
               {
                   puntos = 75;
               }
            
               printf("\n+%d puntos\n\n",puntos);
              *pass+=1;
            }
            if (intentos == 3 && error == 1)
             {
                printf("\nUps Parece que se ha cerrado para siempre, eso te pasa por jugartela y no buscar bien por el camarote\n\n");
               *pass+=1;
             }
        }
        else
        {
          printf("Vuelve cuando quieras intentarlo.\n");
        }
    } while (probar == '1' && intentos < 3 && pass == 0);
    return puntos;
}

int Baul(int *pass, int B)
{
    int puntos =0;
    FILE *fcofre;
    char c, opcion;
    fcofre = fopen("Cofre.txt","r");
    if (fcofre == NULL)
    {
        printf("Error al abrir el archivo.\n");
    }
    else
    {
        printf("\n\n");
        while (fscanf(fcofre,"%c",&c) !=EOF)
        {
            printf("%c",c);
        }
        printf("\n");
    }
    fclose(fcofre);

    do
    {
        printf("elige la bebida: ");
        scanf(" %c", &opcion);
        if(opcion!= 'a' && opcion!= 'b')
        {
            printf("\nEsa opción no existe\n\n");
        }

    } while (opcion != 'a' && opcion != 'b');

    switch (opcion)
    {
        case 'a':
            if (B==0)//con esta variable nos aseguramos que solo pueda escoger el ron una vez y no se sume puntos de mas
            {
            printf ("\n Te has atrevido a beberte el ron del capitan, te has ganado 30 puntos por valiente. \n");
            puntos=30;
            *pass=1;
            printf("\n+30 puntos\n\n");
            }
            else
            printf("Eres un borracho, no busques mas ron que ya te lo has bebido todo\n");
          break;

        case 'b':
            printf("\n¡Un pirata no bebe agua nunca!¡Que verguenza que vayas en este barco!\n");
            puntos=-5; //cada vez que elija el agua se le restan puntos, la podra elegir todas las veces que quiera
            printf("\n-5 puntos\n\n");
          break;
        default:
         break;

    }
    return puntos;
}

int Test_pirata (int *pass)
{
    cuestionario vector[N];
  FILE *fpreguntas,*fopciones,*fsoluciones;
  int i = 0,x=0;
  char n;

  printf("\n\t\t\t\tTEST DEL PIRATA\n");
  printf("\t\tCADA PREGUTA TIENE TRES RESPUESTAS POSIBLES\n\tTODAS LAS RESPUESTAS DEBERAN ESTAR EN MINUSCULA PARA SER VALIDAS\n\n");

  fsoluciones = fopen("Respuestas_test_pirata.txt","r");
  if (fsoluciones == NULL)
   {
       printf("Error al abrir el fichero.\n");
    }
  fpreguntas = fopen("Preguntas_test_pirata.txt", "r");
  if (fpreguntas == NULL)
   {
       printf("Error al abrir el fichero.\n");
    }
  fopciones = fopen("Opciones_test_pirata.txt", "r");
  if (fopciones == NULL)
   {
       printf("Error al abrir el fichero.\n");
    }

  while(fscanf(fpreguntas, "%[^\n]\n", vector[i].preguntas) !=EOF && fscanf(fopciones,"%[^\n]\n",vector[i].opciones) != EOF && fscanf(fsoluciones,"%[^\n]\n",&vector[i].soluciones) !=EOF)
    {
      printf("%s\n\n%s\n\n",vector[i].preguntas,vector[i].opciones);

      scanf(" %c",&n);
      if (n==vector[i].soluciones)
        x+=5;

       i++;
    }
   pass=1;
  fclose(fpreguntas);
  fclose(fopciones);
  fclose(fsoluciones);
    return x;
}

int Test_calculo (int *pass)
{


  cuestionario vector[N];
  FILE *fpreguntas,*fsoluciones;
  int i = 0,x=0,n;


  printf("\t\t\tTEST CALCULO\n");

   fpreguntas = fopen("Preguntas_test_calculo.txt", "r");
  if (fpreguntas == NULL)
  {
    printf("Error al abrir el fichero.\n");
  }
   fsoluciones = fopen("Respuestas_test_calculo.txt","r");
  if (fsoluciones == NULL)
  {
    printf("Error al abrir el fichero.\n");
  }
  while(fscanf(fpreguntas, "%[^\n]\n", vector[i].preguntas) !=EOF && (fscanf(fsoluciones,"%d\n",&vector[i].soluciones) !=EOF))
    {
      printf("%s\n\n",vector[i].preguntas);

      scanf(" %d",&n);
      if (n==vector[i].soluciones)
         x+=5;// por cada pregunta acertada obtiene 5 puntos

       i++;
    }
   *pass+=1;
  fclose(fpreguntas);
  fclose(fsoluciones);
    return x;
}

int Rand(int *pass)
{
      int adivinar,intentos=0, num, puntos=55;
  char *end;
  char test[100];

    srand(time(NULL));   
    num =rand() %30+1;
do
{
     do
  {
      printf("Adivina el numero: ");
      scanf("%d",&adivinar);
      if (!fgets(test,sizeof test, stdin)) //Uso fgets para que cuando introduzca una letra no de error
        break;
    
     test[strlen(test)-1] = '\0';

     if ((adivinar < 1 || adivinar > 30) && (end != test + strlen(test))) //Hasta que no entre un int valido no cierra el bucle
     {
         printf("Input no valido\n");
     }
     
      
  } while ((adivinar < 1 || adivinar > 30) && (end != test + strlen(test)));
 
   intentos++;//cuenta solo los intentos validos
  if (adivinar == num)
  {
     printf("\nSi!! ¡Lo has adivinado! era el %d\n",num);
     printf("\nLo has conseguido en %d intentos\n",intentos);
     printf("\n+%d puntos\n\n",puntos);
  }
  else
  {
    printf("¡Ese no es, vuelve a intentarlo!\n");
    puntos -=5;//Si el numero adivinado no es el correcto lo indica y penaliza con 5 puntos a los puntos totales
  }  
  
} while (adivinar != num && intentos < 10);//termina al adivinar el numero o al llegar a los 10 intentos
   
  if (adivinar !=  num)
  {
      printf("No has conseguido adivinarlo, el numero era %d\n",num);
      puntos = 0;
  }
    *pass+=1;

    return puntos;
  }
