#include "texture.hpp"

Texture::Texture(const char *filePath)
{
    loadTexture(filePath);
}

void Texture::loadTexture(const char *filePath)
{
    SDL_Surface* surf = SDL_LoadBMP(filePath);
        if (surf==NULL) { //echec de chargement texture
            //std::cout<<"erreur de chargement de texture: "<< SDL_GetError()<<std::endl;
        }
        else{
            glGenTextures(1,&textureID);
            //std::cout<<surf->format->BytesPerPixel<<std::endl;
            glBindTexture(GL_TEXTURE_2D,textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surf->w,surf->h, 0, GL_RGB,GL_UNSIGNED_BYTE,surf->pixels);
            glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
            glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
            SDL_FreeSurface(surf);
        }
}

void Texture::utiliser()
{
    glBindTexture(GL_TEXTURE_2D,textureID);
}

Texture::~Texture()
{
    glDeleteTextures(1,&textureID);
}
