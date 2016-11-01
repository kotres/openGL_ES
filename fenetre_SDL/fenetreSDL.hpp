
#ifndef FENETRESDL_HPP
#define FENETRESDL_HPP
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <iostream>
#include <unistd.h>
#define HAUTEUR_FENETRE 300
#define LARGEUR_FENETRE 400


/* class Fenetre:
 * gere la creation et destruction de:
 * -un contexte SDL
 * -une fenetre SDL en double buffer
 * -une surface openGL
 * Doit etre appele en debut de programme
 */

class Fenetre{
    SDL_Window* fenetreSDL;
    SDL_GLContext contexteGL;
    bool valide;
    bool initSDL();
    bool initGL();
    bool initGLEW();
public:
    //FenetreSDL(int largeur,int hauteur);
    Fenetre();
    bool estValide();
    ~Fenetre();
    void afficher();
};
#endif
