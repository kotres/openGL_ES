#include "objetScene.hpp"

ObjetScene::ObjetScene(unsigned int objet3D, unsigned int texture)
{
    this->objet3D=objet3D;
    this->texture=texture;
    longueur=0;
    largeur=0;
    estPhysique=false;
}

ObjetScene::ObjetScene(unsigned int objet3D, unsigned int texture, float longueur, float largeur)
{
    this->objet3D=objet3D;
    this->texture=texture;
    this->longueur=longueur;
    this->largeur=largeur;
    if(this->longueur>EPSILON && this->largeur>EPSILON)
        estPhysique=true;
    else
        estPhysique=false;
}

bool ObjetScene::pointEstDansRectangle(float pointX, float pointY,
                                       float carreLongueur,
                                       float carreLargeur,
                                       float carreCentreX,
                                       float carreCentreY)
{
    if(pointX>carreCentreX-carreLongueur/2&&pointX<carreCentreX+carreLongueur/2){
        if(pointY>carreCentreY-carreLargeur/2&&pointY<carreCentreY+carreLargeur/2)
            return true;
    }
    return false;
}

bool ObjetScene::enCollision(ObjetScene objSC)
{
    if(this->estPhysique==false||objSC.estPhysique==false)
        return false;
    float sonX,sonY,saLongueur,saLargeur;
    sonX=objSC.getPosition().x;
    sonY=objSC.getPosition().y;
    saLongueur=objSC.longueur;
    saLargeur=objSC.largeur;
    if(pointEstDansRectangle(position.x-longueur/2,position.y-largeur/2,saLongueur,saLargeur,sonX,sonY))
        return true;
    if(pointEstDansRectangle(position.x-longueur/2,position.y+largeur/2,saLongueur,saLargeur,sonX,sonY))
        return true;
    if(pointEstDansRectangle(position.x+longueur/2,position.y-largeur/2,saLongueur,saLargeur,sonX,sonY))
        return true;
    if(pointEstDansRectangle(position.x+longueur/2,position.y+largeur/2,saLongueur,saLargeur,sonX,sonY))
        return true;
    if(pointEstDansRectangle(sonX-saLongueur/2,sonY-saLargeur/2,longueur,largeur,position.x,position.y))
        return true;
    if(pointEstDansRectangle(sonX-saLongueur/2,sonY+saLargeur/2,longueur,largeur,position.x,position.y))
        return true;
    if(pointEstDansRectangle(sonX+saLongueur/2,sonY-saLargeur/2,longueur,largeur,position.x,position.y))
        return true;
    if(pointEstDansRectangle(sonX+saLongueur/2,sonY+saLargeur/2,longueur,largeur,position.x,position.y))
        return true;
    return false;
}
