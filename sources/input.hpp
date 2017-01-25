#ifndef INPUT_HPP
#define INPUT_HPP
#include <SDL2/SDL.h>


// utilese pour le input utilisateur
// TODO: tous ce qui concerne les evenements fenetre et pouvoir
// configurer les touches a partir d'un .conf

enum inputName{
    AVANCER,
    RECULER,
    GAUCHE,
    DROITE,
    QUITTER,
    PAUSE
};

class Input{
    bool avancer,reculer,gauche,droite,pause,quitter;
    SDL_Event evenements;
    //const Uint8 *etatClavier;
    int x,y; //dx,dy,xPrecedent,yPrecedent;
public:
    Input();
    void misAJour();
    bool getInputState(inputName nomInput);
    int getX();
    int getY();
};

#endif
