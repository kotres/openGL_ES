#include "input.hpp"

Input::Input()
{
    Quitter=false;
    x=0;
    y=0;
    /*dx=0;
    dy=0;
    xPrecedent=0;
    yPrecedent=0;*/
}

void Input::misAJour()
{
    while( SDL_PollEvent( &evenements ) != 0 ){
        if(evenements.type== SDL_QUIT)
            Quitter=true;
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

bool Input::euLieu()
{
    return Quitter;
}
