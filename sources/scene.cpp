#include "scene.hpp"

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
