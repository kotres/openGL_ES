#ifndef OBJET_SCENE_HPP
#define OBJET_SCENE_HPP
#include "objet3D.hpp"
#include "modelMatrix.hpp"
#include "camera.hpp"

//classe pour decrire un element d'une scene: sa forme, texture, position, etc..

class ObjetScene: public ModelMatrix{
public:
    unsigned int objet3D;
    unsigned int texture;
    ObjetScene(){}
    ObjetScene(unsigned int objet3D,unsigned int texture);
    //on met les elements de collision ici vu que c'est pas encore necessaire
    //d'en faire une classe
};

#endif
