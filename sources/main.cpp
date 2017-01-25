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
    sc.getCamera().translate(glm::vec3(0.0,0.0,2.0));
    while(in.getInputState(QUITTER)==false){
        SDL_Delay(15);
        in.misAJour();
        float rotx=0.010*(in.getX()-300);
        float roty=0.010*(in.getY()-300);
        sc.getCamera().rotate(roty,rotx);
        glm::mat3 rot=glm::mat3(glm::vec3(cos(rotx),-sin(rotx),0.0f),
                                glm::vec3(sin(rotx),cos(rotx),0.0f),
                                glm::vec3(0.0f));
        /*sc.getCamera().translateD(rot*glm::vec3((float)(in.getInputState(GAUCHE)-in.getInputState(DROITE)),
                                            (float)(in.getInputState(AVANCER)-in.getInputState(RECULER)),
                                            0.0f));*/
        sc.getCamera().translateD(glm::vec3((float)(in.getInputState(GAUCHE)-in.getInputState(DROITE)),
                                                (float)(in.getInputState(AVANCER)-in.getInputState(RECULER)),
                                                0.0f),rotx);
        sc.dessiner();
        fen.afficher();
        time+=15;
    }
    return 0;
}
