
#ifndef FENETRESDL_HPP
#define FENETRESDL_HPP
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <unistd.h>
#include <GL/gl.h>
#define HAUTEUR_FENETRE 300
#define LARGEUR_FENETRE 400


class Fenetre{
    SDL_Window* fenetreSDL;
    SDL_GLContext contexteGL;
public:
    //FenetreSDL(int largeur,int hauteur);
    Fenetre();
    bool valide;
    ~Fenetre();
    void afficher();
};
#endif
