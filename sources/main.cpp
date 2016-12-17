#include "fenetreSDL.hpp"
#include "input.hpp"
//#include "shader.hpp"
#include "objet3D.hpp"

int main( /*int argc, char* args[] */)
{
    Fenetre fen;
    Input in;
    //glewInit();
    Shader sh("shaders/vertexShader.vsh","shaders/fragmentShader.fsh");
    if(fen.estValide()==false)
        return 0;
    Objet3D obj3D;
    Camera cam;
    cam.shader=&sh;
    obj3D.camera=&cam;
    float time=0.0;
    while(in.euLieu()==false){
        SDL_Delay(15);
        in.misAJour();
        cam.rotate(0.010*(in.getY()-300),0.010*(in.getX()-300));
        obj3D.translate(glm::vec3( sin(time/900),-0.5+cos(time/800),-5.0));
        obj3D.rotate(time/500,time/693);
        obj3D.dessiner();
        fen.afficher();
        time+=15;
    }

    //glDeleteBuffers(1, &vbo);
    return 0;
}
