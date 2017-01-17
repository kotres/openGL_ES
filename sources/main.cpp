#include "fenetreSDL.hpp"
#include "input.hpp"
//#include "shader.hpp"
//#include "objet3D.hpp"
#include "scene.hpp"

int main( /*int argc, char* args[] */)
{
    Fenetre fen;
    Input in;
    Shader sh("shaders/vertexShader.vsh","shaders/fragmentShader.fsh");
    if(fen.estValide()==false)
        return 0;
    Scene sc;
    sc.shader=sh;
    float time=0.0;
    sc.getCamera().translate(glm::vec3(0.0,0.0,0.0));
    while(in.getInputState(QUITTER)==false){
        SDL_Delay(15);
        in.misAJour();
        sc.getCamera().translateD(glm::vec3((float)(in.getInputState(GAUCHE)-in.getInputState(DROITE)),
                                            0.0f,
                                            (float)(in.getInputState(AVANCER)-in.getInputState(RECULER))));
        sc.getCamera().rotate(0.010*(in.getY()-300),0.010*(in.getX()-300));
        sc.dessiner();
        fen.afficher();
        time+=15;
    }
    return 0;
}
