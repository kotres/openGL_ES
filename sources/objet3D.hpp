#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
//#include <sstream>
#include<boost/tokenizer.hpp>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.hpp"

#ifndef OBJET3D_HPP
#define OBJET3D_HPP

class Objet3D{
    GLuint vbo,vbi,vbNormales;
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normales;
    std::vector<unsigned int>iVertices;
    void loadObj(const char* filePath);
    void parseObjLine(std::string ligne, std::vector<GLfloat> &listeNormales);
    void parseIndices(std::vector<std::string> lineTokens,std::vector<GLfloat>& listeNormales);
public:
    glm::vec3 position;
    glm::mat4 rotation;
    Shader *shader;
    Objet3D();
    void dessiner();
    ~Objet3D();
};

#endif
