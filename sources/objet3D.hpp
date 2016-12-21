#ifndef OBJET3D_HPP
#define OBJET3D_HPP

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <vector>
//#include <sstream>
#include<boost/tokenizer.hpp>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include "modelMatrix.hpp"
#include "camera.hpp"

class Objet3D{
    GLuint vbo,vbi,vbNormales,texture;
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normales;
    std::vector<GLfloat> textures;
    std::vector<unsigned int>iVertices;
    void loadObj(const char* filePath);
    void parseObjLine(std::string ligne, std::vector<GLfloat> &listeNormales,std::vector<GLfloat>& listeTexture);
    void parseIndices(std::vector<std::string> lineTokens, std::vector<GLfloat>& listeNormales, std::vector<GLfloat> &listeTexture);
    void loadTexture(const char *filePath);
public:
   // Camera *camera;
    Objet3D();
    Objet3D(const char* filePath);
    void dessiner(Shader sh, glm::mat4 mvpMatrix);
    ~Objet3D();
};

#endif
