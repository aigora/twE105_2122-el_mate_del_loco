#include <SDL/SDL.h> // Biblioteca principal
#include <iostream>
using namespace std;
int main(int argc, char** argv) {

 cout << "Inicializando SDL." << endl;

 // Inicializar subsistemas automáticos, Video y Audio
 if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) {

 cerr << "No se pudo inicializar SDL: " << SDL_GetError() << endl;
 return(-1);
 }
 cout << "SDL inicializada." << endl;
.
.
.
 cout << "Cerrando SDL." << endl;
 // Cerrando todos los subsistemas
 SDL_Quit();
 return(0);
}

