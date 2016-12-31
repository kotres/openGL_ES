#ifndef OBJET_SCENE_HPP
#define OBJET_SCENE_HPP
#include "objet3D.hpp"
#include "modelMatrix.hpp"
#include "camera.hpp"

class ObjetScene: public ModelMatrix{
public:
    unsigned int objet3D;
    unsigned int texture;
    ObjetScene(){}
    ObjetScene(unsigned int objet3D,unsigned int texture);
};

#endif
