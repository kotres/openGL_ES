#ifndef OBJET3D_HPP
#define OBJET3D_HPP

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <vector>
#include <array>
//#include <sstream>
#include<boost/tokenizer.hpp>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "modelMatrix.hpp"
#include "camera.hpp"

class Objet3D{
    GLuint vbo,vbi,vao,shaderID;
    std::vector<GLfloat> vertices;
    unsigned int normalOffset,textureOffset;
    std::vector<unsigned int>iVertices;
    void loadObj(const char* filePath);
    void parseObjLine(std::string ligne, std::vector<std::array<GLfloat,3>> &listeNormales,
                      std::vector<std::array<GLfloat,2>>& listeTexture,
                      std::vector<GLfloat>& normales,
                      std::vector<GLfloat> &textures);
    void parseIndices(std::vector<std::string> lineTokens,
                      std::vector<std::array<GLfloat,3>>& listeNormales,
                      std::vector<std::array<GLfloat,2>> &listeTexture,
                      std::vector<GLfloat>& normales,
                      std::vector<GLfloat>& textures);
    void InitBuffers(Shader &shader);
public:
    Objet3D();
    Objet3D(std::string filePath, Shader &shader);
    Objet3D(std::vector<GLfloat> vertices,
            unsigned int normalOffset,
            unsigned int textureOffset,Shader &shader);
    void dessiner(glm::mat4 mvpMatrix);
    ~Objet3D();
};

#endif
