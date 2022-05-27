#define N 30

typedef struct 
{
  int dia,mes,anno;
}fecha;

typedef struct 
{
  char nombre[30];
  int puntuacion;
  char dificultad[30];
  fecha data;
}Datos;

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


int Mesa(int *pass,int M);
int Ahorcado(int *pass);
int CajaFuerte(int intentos, int *try, int *pass);
int Test_pirata (int *pass);
int Test_calculo (int *pass);
int Baul(int *pass, int B);
int Rand(int *pass);
void GrabaDatos(Datos jugador, int nivel);
void record(Datos points);
int Salida(int puntos, int n, int *end, int dificultad);
void final(int n);
void imprime();
int dificultad();
void juego();