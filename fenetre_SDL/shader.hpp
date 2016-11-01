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

class Shader{
    Shader();
    GLuint ProgramID;
    bool valide;
    std::string charger(std::string nomFichier);
    GLuint compiler(std::string nomFichier,	GLenum typeShader);
public:
    ~Shader();
    Shader(std::string nomVertex,std::string nomFragment);
    void utiliser();
    bool estValide();
};

#endif
