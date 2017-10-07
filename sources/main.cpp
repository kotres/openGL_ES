#include <iostream>
#include "fenetreSDL.hpp"
#include "input.hpp"

int main( /*int argc, char* args[] */)
{
    SDlenvironment fen;
    Input inp;
    while(!inp.getInputState(QUITTER)){
    	inp.misAJour();
    	if(inp.getInputState(GAUCHE))
    		std::cout<<"gauche"<<std::endl;
    }
    return 0;
}
