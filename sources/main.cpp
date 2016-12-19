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
    Objet3D obj3D("objets/bunny.obj");
    //obj3D.translate(glm::vec3( 0.0,0.0,-5.0));
    //obj3D.scale(glm::vec3(5.0));
    Camera cam;
    cam.shader=&sh;
    //obj3D.camera=&cam;
    Scene sc;
    sc.cameras.push_back(cam);
    ObjetScene objsc;
    objsc.camera=&cam;
    objsc.translate(glm::vec3( 0.0,0.0,-5.0));
    objsc.objet3D=&obj3D;
    sc.objetsScene.push_back(objsc);
    sc.objets3D.push_back(obj3D);
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            ObjetScene objetsc;
            objetsc.camera=&cam;
            objetsc.translate(glm::vec3( (float)(i-12),(float)(j-12),-5.0));
            objetsc.objet3D=&obj3D;
            sc.objetsScene.push_back(objetsc);
        }
    }
    float time=0.0;
    while(in.euLieu()==false){
        SDL_Delay(15);
        in.misAJour();
        cam.rotate(0.010*(in.getY()-300),0.010*(in.getX()-300));
        /*obj3D.translate(glm::vec3( sin(time/900),-0.5+cos(time/800),-5.0));
        obj3D.rotate(time/500,time/693);
        obj3D.dessiner();*/
        sc.dessiner();
        fen.afficher();
        time+=15;
    }

    //glDeleteBuffers(1, &vbo);
    return 0;
}
