#include "scene.hpp"

Scene::Scene()
{
    Camera cam;
    cameras.push_back(cam);
    cameraUtilisee=0;
}

void Scene::utiliserCamera(unsigned int i){
    if(i<cameras.size())
        cameraUtilisee=i;
}

void Scene::dessiner()
{
    for(ObjetScene& objsc:objetsScene){
        objets3D.at(objsc.objet3D).dessiner(shader,cameras.at(cameraUtilisee).getVPMatrix()*objsc.getModelMatrix());
    }
}

Camera &Scene::getCamera()
{
    return cameras.at(cameraUtilisee);
}
