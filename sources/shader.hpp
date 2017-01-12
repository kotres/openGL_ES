#ifndef SHADER_HPP
#define SGADER_HPP
#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <fstream>
#include <iostream>

/*enum TypeShader{
    vertex,
    fragment,
    geometrie
};*/

#define INVERTEX 0
#define INNORMAL 1
#define INTEXTURE 2

class Shader{
    GLuint ProgramID;
    bool valide;
    std::string charger(std::string nomFichier);
    GLuint compiler(std::string nomFichier,	GLenum typeShader);
public:
    Shader();
    ~Shader();
    Shader(std::string nomVertex,std::string nomFragment);
    void utiliser();
    bool estValide();
    GLuint ID();
};

#endif
