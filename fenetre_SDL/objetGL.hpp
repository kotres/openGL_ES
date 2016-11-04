#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include "shader.hpp"

#ifndef OBJETGL_HPP
#define OBJETGL_HPP

class ObjetGL{
    GLuint vbo;
    std::vector<GLfloat> vertices;
    //Shader shader;
public:
    ObjetGL();
    void dessiner();
    ~ObjetGL();
};

#endif
