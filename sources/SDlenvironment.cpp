#include "SDlenvironment.hpp"

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
        std::cout<<"SDL2 could not be initialised:"<<SDL_GetError()<<std::endl;
        return false;
    }
    SDLwindow = SDL_CreateWindow( "executable", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   600, 600, SDL_WINDOW_OPENGL );
    if(SDLwindow==NULL){
        std::cout<<"the application window could not be created: "<<SDL_GetError()<<std::endl;
        return false;
    }
    return true;
}

bool SDlenvironment::initGL()
{
    GLcontext = SDL_GL_CreateContext(SDLwindow);
    if(GLcontext==NULL){
        std::cout<<"OpenGL context could not be initialised: "<<SDL_GetError()<<std::endl;
        return false;
    }
    //we want to use the OpenGL core profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    //using opengl 3.3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //activating depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    return true;
}

bool SDlenvironment::initGLEW()
{
    GLenum GLEWerror = glewInit();
    if(GLEWerror!=GLEW_OK){
        std::cout<<"GLEW could not be initialised: "<<GLEWerror<<std::endl;
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
    //OpenGL context destruction
    SDL_GL_DeleteContext(GLcontext);

    //window destruction
    SDL_DestroyWindow( SDLwindow );
    SDLwindow = NULL;

    //we quit SDL
    SDL_Quit();
}

//TODO: redo these 2 methods
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
