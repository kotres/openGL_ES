#include "objet3D.hpp"


Objet3D::Objet3D()
{
    shader=nullptr;
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

    position=glm::vec3(0.0);
    rotation=glm::mat4(1.0);
}

void Objet3D::dessiner()
{
    shader->utiliser();
    glUniform3fv(glGetUniformLocation(shader->ID(),"position"), 1, glm::value_ptr(position));
    glUniformMatrix4fv(glGetUniformLocation(shader->ID(),"rotation"), 1,GL_FALSE,glm::value_ptr(rotation));
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

Objet3D::~Objet3D()
{
    glDeleteBuffers(1, &vbo);
}
