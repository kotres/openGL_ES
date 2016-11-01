#include "shader.hpp"

Shader::Shader()
{
    ProgramID=0;
    valide=false;
}

Shader::Shader(std::string nomVertex, std::string nomFragment)
{
    compiler(nomVertex,vertex);
}

std::string Shader::charger(std::string nomFichier)
{
    std::ifstream fichier(nomFichier.c_str());
    if(!fichier){
        std::cout<<"erreur de chargement du fichier "<<nomFichier<<std::endl;
        valide=false;
        return NULL;
    }
    std::string contenu;
    while(fichier){
        std::string ligne;
        getline(fichier, ligne);
        contenu+=ligne+'\n';
    }
    fichier.close();
    return contenu;
}

GLuint Shader::compiler(std::string source,TypeShader typeShader)
{
    std::string fichier=charger(source);
    std::cout<<fichier<<std::endl;
    return 0;
}

bool Shader::estValide()
{
    return valide;
}

void Shader::utiliser()
{
    //glUseProgram(ProgramID);
    std::cout<<"patate"<<std::endl;

}

Shader::~Shader()
{
    //glDeleteProgram(ProgramID);
}
