#include "input.hpp"

Input::Input()
{
    Quitter=false;
}

void Input::misAJour()
{
    while( SDL_PollEvent( &evenements ) != 0 ){
        if(evenements.type== SDL_QUIT)
            Quitter=true;
    }
}

bool Input::euLieu()
{
    return Quitter;
}
