#include "fenetreSDL.hpp"

Fenetre::Fenetre()
{
    valide=false;
    fenetreSDL=NULL;
    contexteGL=NULL;

    //intialisation de sdl
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout<<"SDL n'a pas pu etre initialise, erreur:"<<SDL_GetError()<<std::endl;
    }
    else{
        //création de la fenetre
        fenetreSDL = SDL_CreateWindow( "fenetre SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                       LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_OPENGL );
        if(fenetreSDL==NULL){
            std::cout<<"la fenetre n'as pas pu etre cree, erreur: "<<SDL_GetError()<<std::endl;
        }
        else{
            //creation du contexte openGL
            contexteGL = SDL_GL_CreateContext(fenetreSDL);
            if(contexteGL==NULL){
                std::cout<<"le contexte openGL n'as pas pu etre cree, erreur: "<<SDL_GetError()<<std::endl;
            }
            else{
                //on n'utilise pas les fonctionnalitees opengl deprecies
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
                valide= true;
            }
        }
    }
}

void Fenetre::afficher()
{
    glClearColor(0.0,0.0,0.0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(fenetreSDL);
}

Fenetre::~Fenetre()
{
    //destruction du contexte openGL
    SDL_GL_DeleteContext(contexteGL);

    //destruction de la fenetre
    SDL_DestroyWindow( fenetreSDL );
    fenetreSDL = NULL;

    //on quitte sdl
    SDL_Quit();
}
