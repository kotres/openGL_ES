#include <SDL2/SDL.h>
#include <iostream>
#include <unistd.h>

#define HAUTEUR_FENETRE 300
#define LARGEUR_FENETRE 400

int main( int argc, char* args[] )
{
    //intialisation de sdl
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout<<"SDL n'a pas pu etre initialise, erreur:"<<SDL_GetError()<<std::endl;
        return 0;
    }
    //création de la fenetre
    SDL_Window* fenetreSDL=NULL;
    fenetreSDL = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_SHOWN );
    if(fenetreSDL==NULL){
        std::cout<<"la fenetre n'as pas pu etre cree, erreur: "<<SDL_GetError()<<std::endl;
        return 0;
    }

    sleep(2);
    //destruction de la fenetre
    SDL_DestroyWindow( fenetreSDL );
    fenetreSDL = NULL;

    //on quitte sdl
    SDL_Quit();

	return 0;
}
