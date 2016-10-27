#include "fenetreSDL.hpp"

int main( int argc, char* args[] )
{
    Fenetre fen;
    if(fen.valide==false)
        return 0;
    fen.afficher();
    sleep(2);

    return 0;
}
