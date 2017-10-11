#include "MainApplication.hpp"

MainApplication::MainApplication()
    :sdlEnvironment(),inputs()
{}

void MainApplication::execute()
{
    inputs.updateIputs();
    while(!inputs.getQuit()){
        SDL_Delay(100);
        inputs.updateIputs();
    }
}
