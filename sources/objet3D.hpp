#ifndef OBJET3D_HPP
#define OBJET3D_HPP

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <vector>
#include <array>


#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "modelMatrix.hpp"
#include "camera.hpp"

class Objet3D{
    GLuint vbo,vbi,vao;
    std::vector<GLfloat> vertices;
    unsigned int normalOffset,textureOffset;
    std::vector<unsigned int>iVertices;
    void loadObj(const char* filePath);
    std::array<unsigned int,3> getIndices(std::string strIndices);
    void InitBuffers();
public:
    Objet3D();
    Objet3D(std::string filePath);
    Objet3D(std::vector<GLfloat> vertices,
            unsigned int normalOffset,
            unsigned int textureOffset,std::vector<unsigned int>iVertices);
    void dessiner(glm::mat4 mvpMatrix,Shader& shader);
    ~Objet3D();
};

#endif
