#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "objetScene.hpp"
#include <glm/glm.hpp>

class Projectile: public ObjetScene{
public:
    unsigned int timeToLive;
    Projectile(glm::vec3 origine,float angle);
    void miseAJour();
};

#endif
