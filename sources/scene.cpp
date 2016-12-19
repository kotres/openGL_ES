#include "scene.hpp"

Scene::Scene()
{
    Camera cam;
    cameras.push_back(cam);
    cameraUtilisee=0;
    shaderUtilise=0;
}

void Scene::utiliserCamera(unsigned int i){
    if(i<cameras.size())
        cameraUtilisee=i;
}

void Scene::dessiner()
{
    for(ObjetScene& objsc:objetsScene){
        objets3D.at(objsc.objet3D).dessiner(shaders.at(shaderUtilise),cameras.at(cameraUtilisee).getVPMatrix()*objsc.getModelMatrix());
    }
}

void Scene::utiliserShader(unsigned int i)
{
    if(i<shaders.size())
        shaderUtilise=i;
}

Camera &Scene::getCamera()
{
    return cameras.at(cameraUtilisee);
}
