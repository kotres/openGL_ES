#include "scene.hpp"

Scene::Scene()
{
    Camera cam;
    cameras.push_back(cam);
    cameraUtilisee=0;
    this->shader=shader;
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
        objets3D.at(objsc.objet3D).dessiner(getCamera().getVPMatrix()*objsc.getModelMatrix(),shader);
    }
    glDisable(GL_TEXTURE_2D);
}

Camera &Scene::getCamera()
{
    return cameras.at(cameraUtilisee);
}


void Scene::loadMap()
{
    //Objet3D obj3D("objets/TV/TV.obj");
    this->objets3D.push_back(Objet3D("objets/TV/TV.obj"));
    //Texture tex("textures/texture.bmp");
    this->textures.push_back(Texture("textures/texture.bmp"));
    //ObjetScene objSc(0,0);
    for(int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            ObjetScene objsc(0,0,2.0,2.0);
            objsc.translate(glm::vec3((float)-10*j-1.0,(float)-10*i-1.0,-1.0));
            this->objetsScene.push_back(objsc);
        }
    }
    joueur=ObjetScene(0,0,2.0,2.0);
    joueur.scale(glm::vec3(0.5));
    this->objets3D.push_back(Objet3D("objets/grass.obj"));
    this->textures.push_back(Texture("textures/grass.bmp"));
    ObjetScene objsc(1,1);
    this->objetsScene.push_back(objsc);
}

void Scene::detecterCollision()
{
    int k=0;
    for(auto objsc:objetsScene){
        if(joueur.enCollision(objsc))
            std::cout<<"collision avec "<<k<<std::endl;
        k++;
    }
}

void Scene::miseAJour()
{
    detecterCollision();
    dessiner();
}
