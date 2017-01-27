#ifndef OBJET_SCENE_HPP
#define OBJET_SCENE_HPP
#include "objet3D.hpp"
#include "modelMatrix.hpp"
#include "camera.hpp"
#include <glm/glm.hpp>

#define EPSILON 0.0001

//classe pour decrire un element d'une scene: sa forme, texture, position, etc..

class ObjetScene: public ModelMatrix{
protected:
    bool estPhysique;
    bool pointEstDansRectangle(float pointX, float pointY,
                               float carreLongueur,
                               float carreLargeur,
                               float carreCentreX,
                               float carreCentreY);//fonction a remplacer
public:
    unsigned int objet3D;
    unsigned int texture;
    ObjetScene(){}
    ObjetScene(unsigned int objet3D,unsigned int texture);
    ObjetScene(unsigned int objet3D, unsigned int texture,float longueur,float largeur);
    //on met les elements de collision ici vu que c'est pas encore necessaire
    //d'en faire une classe
    float longueur,largeur;//longueur pour x et largeur pour y
    bool enCollision(ObjetScene objSC);
};

#endif
