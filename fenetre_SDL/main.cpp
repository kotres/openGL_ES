#include "fenetreSDL.hpp"
#include "input.hpp"

int main( int argc, char* args[] )
{
    Fenetre fen;
    Input in;
    if(fen.estValide()==false)
        return 0;
    fen.afficher();
    while(in.euLieu()==false){
        SDL_Delay(15);
        in.misAJour();
    }
    return 0;
}
