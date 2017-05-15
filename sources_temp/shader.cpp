#include "shader.hpp"

Shader::Shader()
{
    ProgramID=0;
    valide=false;
}

Shader::Shader(std::string nomVertex, std::string nomFragment)
{
    GLuint vertexShaderObject, fragmentShaderObject;
    valide=true;
    vertexShaderObject=compiler(nomVertex,GL_VERTEX_SHADER);
    fragmentShaderObject=compiler(nomFragment,GL_FRAGMENT_SHADER);


    ProgramID = glCreateProgram();

    glAttachShader(ProgramID, vertexShaderObject);
    glAttachShader(ProgramID, fragmentShaderObject);

    glBindAttribLocation(ProgramID, INVERTEX, "InVertex");
    glBindAttribLocation(ProgramID, INNORMAL, "InNormal");
    glBindAttribLocation(ProgramID, INTEXTURE, "InTexture");

    glLinkProgram(ProgramID);

    GLint success;
    GLchar LogLink[512];
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(ProgramID, 512, NULL, LogLink);
        valide=false;
        std::cout<<"erreur de link programme:"<<std::endl<<LogLink;
    }
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

GLuint Shader::compiler(std::string nomFichier,	GLenum typeShader)
{
    GLuint ShaderObject;

    ShaderObject = glCreateShader(typeShader);


    std::string source=charger(nomFichier);
    const char* sourcec=source.c_str();
    const GLint longueur=GLint(source.length());

    glShaderSource(ShaderObject, 1, &sourcec, &longueur);

    glCompileShader(ShaderObject);

    GLint success;
    GLchar LogCompilation[512];
    glGetShaderiv(ShaderObject, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(ShaderObject, 512, NULL, LogCompilation);
        std::cout << "erreur de compilation du shader "<<nomFichier<<std::endl
                  << LogCompilation << std::endl;
        valide=false;
        return 0;
    }
    return ShaderObject;
}

bool Shader::estValide()
{
    return valide;
}

void Shader::utiliser()
{
    glUseProgram(ProgramID);
    //std::cout<<"patate"<<std::endl;
}

GLuint Shader::ID()
{
    return ProgramID;
}


void Shader::detruire()
{
    glDeleteProgram(ProgramID);
}
