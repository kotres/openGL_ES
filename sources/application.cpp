#include "application.hpp"


void Application::applicationLoop()
{
    float time=0.0;
    std::cout<<"Detruiser tous les piliers"<<std::endl;
    while(input.getInputState(QUITTER)==false&&scene.objetsScene.size()>1){
        SDL_Delay(15);
        input.misAJour();
        scene.miseAJour(input);
        fenetre.afficher();
        time+=15;
    }
    std::cout<<"Bravo! vouz avez Reussi!"<<std::endl;
}
