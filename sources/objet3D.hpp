#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <sstream>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.hpp"

#ifndef OBJET3D_HPP
#define OBJET3D_HPP

class Objet3D{
    GLuint vbo,vbi;
    std::vector<GLfloat> vertices;
    std::vector<unsigned int>indices;
    void loadObj(const char* filePath);
public:
    glm::vec3 position;
    glm::mat4 rotation;
    Shader *shader;
    Objet3D();
    void dessiner();
    ~Objet3D();
};

#endif
