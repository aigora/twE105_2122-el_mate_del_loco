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

void juego();
void GrabaDatos(Datos jugador);
void record(Datos points);
int Salida(int puntos, int n, int *end);
void final();
void imprime();