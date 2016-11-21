#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.hpp"

#ifndef OBJET3D_HPP
#define OBJET3D_HPP

class Objet3D{
    GLuint vbo;
    std::vector<GLfloat> vertices;
public:
    glm::vec4 position;
    Shader *shader;
    Objet3D();
    void dessiner();
    ~Objet3D();
};

#endif
