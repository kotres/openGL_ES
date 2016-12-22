#include "fenetreSDL.hpp"

Fenetre::Fenetre()
{
    valide=false;
    fenetreSDL=NULL;
    contexteGL=NULL;

    valide=initSDL();
    valide&=initGL();
    valide&=initGLEW();
}

bool Fenetre::initSDL()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout<<"SDL n'a pas pu etre initialise, erreur:"<<SDL_GetError()<<std::endl;
        return false;
    }
    fenetreSDL = SDL_CreateWindow( "executable", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_OPENGL );
    if(fenetreSDL==NULL){
        std::cout<<"la fenetre n'as pas pu etre cree, erreur: "<<SDL_GetError()<<std::endl;
        return false;
    }
    return true;
}

bool Fenetre::initGL()
{
    contexteGL = SDL_GL_CreateContext(fenetreSDL);
    if(contexteGL==NULL){
        std::cout<<"le contexte openGL n'as pas pu etre cree, erreur: "<<SDL_GetError()<<std::endl;
        return false;
    }
    //on n'utilise pas les fonctionnalitees opengl deprecies
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    //on utlise opengl 3.2
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //activation du depth test et on prend le fragment le plus proche
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    //verification des parametres
    int majVer,minVer;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,&majVer);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,&minVer);
    std::cout<<"version opengl:"<<majVer<<"."<<minVer<<std::endl;

    return true;
}

bool Fenetre::initGLEW()
{
    GLenum erreurGLEW = glewInit();
    if(erreurGLEW!=GLEW_OK){
        std::cout<<"erreur d'initialisation de GLEW, erreur "<<erreurGLEW<<std::endl;
        return false;
    }
    return true;
}

void Fenetre::afficher()
{
    SDL_GL_SwapWindow(fenetreSDL);
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
}

bool Fenetre::estValide()
{
    return valide;
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
