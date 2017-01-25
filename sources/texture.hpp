#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>

//classe texture pour charger les textures, marche seulement avec les bmp en ce moment

class Texture
{
    GLuint textureID;
    void loadTexture(const char *filePath);
public:
    Texture() {}
    Texture(const char *filePath);
    void utiliser();
    void detruire();
};

#endif
