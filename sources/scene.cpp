#include "scene.hpp"

Scene::Scene()
{
    Camera cam;
    cameras.push_back(cam);
    cameraUtilisee=0;
    loadMap();
}

void Scene::utiliserCamera(unsigned int i){
    if(i<cameras.size())
        cameraUtilisee=i;
}

void Scene::dessiner()
{
    shader.utiliser();
    glEnable(GL_TEXTURE_2D);
    for(ObjetScene& objsc:objetsScene){
        textures.at(objsc.texture).utiliser();
        objets3D.at(objsc.objet3D).dessiner(getCamera().getVPMatrix()*objsc.getModelMatrix());
    }
    glDisable(GL_TEXTURE_2D);
}

Camera &Scene::getCamera()
{
    return cameras.at(cameraUtilisee);
}

void Scene::loadMap()
{
    std::ifstream fichier("maps/map.map");
    if(!fichier){
        std::cout<<"erreur de chargement du fichier "<<"maps/map.map"<<std::endl;
    }
    else{
        while(fichier){
            std::string ligne;
            getline(fichier, ligne);
            std::cout<<ligne<<std::endl;
        }
        fichier.close();
    }
}
