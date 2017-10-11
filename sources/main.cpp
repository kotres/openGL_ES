#include <iostream>
#include "SDlenvironment.hpp"
#include "SDLinputHandler.hpp"

int main( /*int argc, char* args[] */)
{
    SDlenvironment fen;
    SDLinputHandler inp;
    while(!inp.getQuit()){
        inp.updateIputs();
        if(inp.getLeft())
    		std::cout<<"gauche"<<std::endl;
    }
    return 0;
}
