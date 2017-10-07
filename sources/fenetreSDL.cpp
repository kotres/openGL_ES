#include "fenetreSDL.hpp"

SDlenvironment::SDlenvironment()
:SDLwindow(NULL),GLcontext(NULL),valid(false)
{
    valid=initSDL();
    valid&=initGL();
    valid&=initGLEW();
}

bool SDlenvironment::initSDL()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout<<"SDL n'a pas pu etre initialise, erreur:"<<SDL_GetError()<<std::endl;
        return false;
    }
    SDLwindow = SDL_CreateWindow( "executable", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   600, 600, SDL_WINDOW_OPENGL );
    if(SDLwindow==NULL){
        std::cout<<"la fenetre n'as pas pu etre cree, erreur: "<<SDL_GetError()<<std::endl;
        return false;
    }
    return true;
}

bool SDlenvironment::initGL()
{
    GLcontext = SDL_GL_CreateContext(SDLwindow);
    if(GLcontext==NULL){
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
    /*int majVer,minVer;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,&majVer);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,&minVer);
    std::cout<<"version opengl:"<<majVer<<"."<<minVer<<std::endl;*/

    return true;
}

bool SDlenvironment::initGLEW()
{
    GLenum erreurGLEW = glewInit();
    if(erreurGLEW!=GLEW_OK){
        std::cout<<"erreur d'initialisation de GLEW, erreur "<<erreurGLEW<<std::endl;
        return false;
    }
    return true;
}

void SDlenvironment::updateSurface()
{
    SDL_GL_SwapWindow(SDLwindow);
    glClearColor(0.3f,0.3f,0.7f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
}

bool SDlenvironment::isValid()
{
    return valid;
}

SDlenvironment::~SDlenvironment()
{
    //destruction du contexte openGL
    SDL_GL_DeleteContext(GLcontext);

    //destruction de la fenetre
    SDL_DestroyWindow( SDLwindow );
    SDLwindow = NULL;

    //on quitte sdl
    SDL_Quit();
}

//TODO: faire ces 2 methodes correctement
SDlenvironment::SDlenvironment(const SDlenvironment& obj)
:SDLwindow(obj.SDLwindow),GLcontext(obj.GLcontext),valid(obj.valid)
{
}

SDlenvironment& SDlenvironment::operator=(const SDlenvironment& obj){
    this->SDLwindow=obj.SDLwindow;
    this->GLcontext=obj.GLcontext;
    this->valid=obj.valid;
    return *this;
}
