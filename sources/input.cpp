#include "input.hpp"

Input::Input()
:avancer(false),reculer(false),gauche(false),droite(false),
pause(false),quitter(false),action(false),x(0),y(0)
{}

void Input::misAJour()
{
    SDL_Event evenements;
    while( SDL_PollEvent( &evenements ) != 0 ){
        /*if(evenements.type== SDL_QUIT)
            Quitter=true;*/
        switch (evenements.type) {
        case SDL_QUIT:
            quitter=true;
            break;
        case SDL_MOUSEBUTTONDOWN://faudra raffiner ici, on gere tous les boutons de souris en meme temps
            action=true;
            break;
        case SDL_MOUSEBUTTONUP://faudra raffiner ici, on gere tous les boutons de souris en meme temps
            action=false;
            break;
        case SDL_KEYDOWN:
            switch(evenements.key.keysym.sym){
            case SDLK_z:
                avancer=true;
                break;
            case SDLK_s:
                reculer=true;
                break;
            case SDLK_q:
                gauche=true;
                break;
            case SDLK_d:
                droite=true;
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch(evenements.key.keysym.sym){
            case SDLK_z:
                avancer=false;
                break;
            case SDLK_s:
                reculer=false;
                break;
            case SDLK_q:
                gauche=false;
                break;
            case SDLK_d:
                droite=false;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    SDL_GetMouseState(&x, &y);
}

int Input::getX()
{
    return x;
}

int Input::getY()
{
    return y;
}

bool Input::getInputState(inputName nomInput)
{
    switch (nomInput) {
    case AVANCER:
        return avancer;
        break;
    case RECULER:
        return reculer;
        break;
    case GAUCHE:
        return gauche;
        break;
    case DROITE:
        return droite;
        break;
    case QUITTER:
        return quitter;
        break;
    case PAUSE:
        return pause;
        break;
    case ACTION:
        return action;
        break;
    default:
        return false;
        break;
    }
}
