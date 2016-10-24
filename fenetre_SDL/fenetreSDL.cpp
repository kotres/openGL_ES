#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <unistd.h>
#include <GL/gl.h>
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
    fenetreSDL = SDL_CreateWindow( "fenetre SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_OPENGL );
    if(fenetreSDL==NULL){
        std::cout<<"la fenetre n'as pas pu etre cree, erreur: "<<SDL_GetError()<<std::endl;
        return 0;
    }

    //creation du contexte openGL
    SDL_GLContext contexteGL = SDL_GL_CreateContext(fenetreSDL);
    if(contexteGL==NULL){
        std::cout<<"le contexte openGL n'as pas pu etre cree, erreur: "<<SDL_GetError()<<std::endl;
        return 0;
    }

    //on utilise pas les fonctionnalitees opengl deprecies
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    //on utlise opengl 3.2
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //verification des parametres
    int majVer,minVer;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,&majVer);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,&minVer);
    std::cout<<"version opengl:"<<majVer<<"."<<minVer<<std::endl;

    glClearColor(0.0,0.0,1.0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(fenetreSDL);

    sleep(2);

    //destruction du contexte openGL
    SDL_GL_DeleteContext(contexteGL);

    //destruction de la fenetre
    SDL_DestroyWindow( fenetreSDL );
    fenetreSDL = NULL;

    //on quitte sdl
    SDL_Quit();

	return 0;
}
