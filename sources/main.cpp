#include "fenetreSDL.hpp"
#include "input.hpp"
//#include "shader.hpp"
#include "objet3D.hpp"

int main( int argc, char* args[] )
{
    Fenetre fen;
    Input in;
    //glewInit();
    Shader sh("shaders/vertexShader.vsh","shaders/fragmentShader.fsh");
    if(fen.estValide()==false)
        return 0;

    //coordonnees du triangle
    /*GLfloat coord[]={
        -0.5f, -0.5f, 0.5f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    //creation du vbo
    GLuint vbo;
    glGenBuffers(1, &vbo);
    //c'est un type array
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //on y met les coordonnees du triangle
    glBufferData(GL_ARRAY_BUFFER, sizeof(coord), coord, GL_DYNAMIC_DRAW);

    //on dit a opengl comment l'interpreter
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);*/

    //sh.utiliser();
    Objet3D obj3D;
    obj3D.shader=&sh;
    obj3D.scale=glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    float time=0.0;
    while(in.euLieu()==false){
        SDL_Delay(15);
        in.misAJour();
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        obj3D.translation=glm::translate(glm::mat4(1.0),glm::vec3( 0.5*sin(time/900),0.5*cos(time/800),0.0));
        obj3D.rotation[1].y=cos(time/500);
        obj3D.rotation[1].z=sin(time/500);
        obj3D.rotation[2].y=-sin(time/500);
        obj3D.rotation[2].z=cos(time/500);
        obj3D.dessiner();
        fen.afficher();
        time+=15;
    }

    //glDeleteBuffers(1, &vbo);
    return 0;
}
