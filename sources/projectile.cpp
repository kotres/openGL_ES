#include "projectile.hpp"

Projectile::Projectile(glm::vec3 origine, float angle)
    :ObjetScene(0,0,2.0,2.0)
{
    translate(origine);
    rotationX=angle;
    timeToLive=100;
}

void Projectile::miseAJour()
{
    if(timeToLive!=0){
        timeToLive--;
        translateD(glm::vec3(0.0,1.0,0.0),rotationX);
    }
}
