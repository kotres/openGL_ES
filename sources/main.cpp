#include "fenetreSDL.hpp"
#include "input.hpp"
//#include "shader.hpp"
//#include "objet3D.hpp"
#include "scene.hpp"

int main( /*int argc, char* args[] */)
{
    Fenetre fen;
    Input in;
    //glewInit();
    Shader sh("shaders/vertexShader.vsh","shaders/fragmentShader.fsh");
    if(fen.estValide()==false)
        return 0;
    Objet3D obj3D("objets/mugul/mugul_a_roulettes.obj");
    //obj3D.translate(glm::vec3( 0.0,0.0,-5.0));
    //obj3D.scale(glm::vec3(5.0));
    //cam.shader=&sh;
    //obj3D.camera=&cam;
    Scene sc;
    sc.shaders.push_back(sh);
    //objsc.camera=&cam;
    sc.objets3D.push_back(obj3D);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            ObjetScene objetsc;
            //objetsc.camera=&cam;
            objetsc.translate(glm::vec3( (float)(i-5),(float)(j-5),-5.0));
            objetsc.scale(glm::vec3(0.5));
            objetsc.objet3D=0;
            sc.objetsScene.push_back(objetsc);
        }
    }
    float time=0.0;
    while(in.euLieu()==false){
        SDL_Delay(15);
        in.misAJour();
        sc.getCamera().rotate(0.010*(in.getY()-300),0.010*(in.getX()-300));
        /*obj3D.translate(glm::vec3( sin(time/900),-0.5+cos(time/800),-5.0));
        obj3D.rotate(time/500,time/693);
        obj3D.dessiner();*/
        for(int i=0;i<10*10;i++)
            sc.objetsScene.at(i).rotate(time*i/50000,time*i/69300);
        sc.dessiner();
        fen.afficher();
        time+=15;
    }
    return 0;
}
