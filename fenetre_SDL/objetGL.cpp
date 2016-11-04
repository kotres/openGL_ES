#include "objetGL.hpp"


ObjetGL::ObjetGL()
{
    //shader=Shader("vertexShader.vsh","fragmentShader.fsh");
    vertices={
        -0.5f, -0.5f, 1.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    glGenBuffers(1, &vbo);
    //c'est un type array
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //on y met les coordonnees du triangle
    glBufferData(GL_ARRAY_BUFFER, vertices.size()* sizeof(vertices),
                 &vertices.front(), GL_DYNAMIC_DRAW);
    //on dit a opengl comment l'interpreter
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
}

void ObjetGL::dessiner()
{
   // shader.utiliser();
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(
       0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

ObjetGL::~ObjetGL()
{
    glDeleteBuffers(1, &vbo);
}
