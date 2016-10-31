#ifndef INPUT_HPP
#define INPUT_HPP
#include <SDL2/SDL.h>

/*enum inputName{
    HAUT,
    BAS,
    GAUCHE,
    DROITE,
    QUITTER,
};*/

class Input{
    bool /*Haut,Bas,Gauche,Droite,Pause,*/Quitter;
    SDL_Event evenements;
    //const Uint8 *etatClavier;
public:
    Input();
    void misAJour();
    bool euLieu(/*inputName nomInput*/);
};

#endif
