#include "scene.hpp"

void Scene::utiliserCamera(unsigned int i){
    if(i<cameras.size())
        cameraUtilisee=cameras.at(i);
}

void Scene::dessiner()
{
    for(ObjetScene& objsc:objetsScene){
        objsc.dessiner();
    }
}

void Scene::utiliserShader(unsigned int i)
{
    if(i<shaders.size())
        shaderUtilise=shaders.at(i);
}
