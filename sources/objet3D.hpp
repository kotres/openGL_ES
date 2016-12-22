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
    GLuint vbo,vbi,vbNormales,vbTexture,texture;//to do: mettre tous les vbo dans un seul
    int vertexPosition,normalPosition,texturePosition;
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normales;
    std::vector<GLfloat> textures;
    std::vector<unsigned int>iVertices;
    void loadObj(const char* filePath);
    void parseObjLine(std::string ligne, std::vector<std::array<GLfloat,3>> &listeNormales,std::vector<std::array<GLfloat,2>>& listeTexture);
    void parseIndices(std::vector<std::string> lineTokens, std::vector<std::array<GLfloat,3>>& listeNormales, std::vector<std::array<GLfloat,2>> &listeTexture);
    void loadTexture(const char *filePath);
public:
   // Camera *camera;
    Objet3D();
    Objet3D(std::string filePath, Shader &shader);
    void dessiner(Shader sh, glm::mat4 mvpMatrix);
    ~Objet3D();
};

#endif
