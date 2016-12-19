#ifndef OBJET_SCENE_HPP
#define OBJET_SCENE_HPP
#include "objet3D.hpp"
#include "modelMatrix.hpp"
#include "camera.hpp"

class ObjetScene: public ModelMatrix{
public:
    Camera* camera;
    Objet3D* objet3D;
    void dessiner();
};

#endif
