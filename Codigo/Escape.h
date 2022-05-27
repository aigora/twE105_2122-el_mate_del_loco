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

void juego();
void GrabaDatos(Datos jugador, int nivel);
void record(Datos points);
int Salida(int puntos, int n, int *end, int dificultad);
void final();
void imprime();
int dificultad();