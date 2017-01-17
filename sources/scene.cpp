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
            ObjetScene objsc(0,0);
            objsc.translate(glm::vec3(0.0,(float)i+1.0,(float)j+1.0));
            this->objetsScene.push_back(objsc);
        }
    }
    this->objets3D.push_back(Objet3D("objets/grass.obj"));
    this->textures.push_back(Texture("textures/grass.bmp"));
    ObjetScene objsc(1,1);
    this->objetsScene.push_back(objsc);
}

/*void Scene::loadMap()
{
    std::ifstream fichier("maps/map.map");
    if(!fichier){
        std::cout<<"erreur de chargement du fichier "<<"maps/map.map"<<std::endl;
    }
    else{
        while(fichier){
            //std::set<std::string> nomsTexture;
            std::string strin;
            fichier>>strin;
            if(strin=="{"){
                std::vector<glm::vec3> points;
                std::vector<glm::vec3> listeNormales;
                std::vector<glm::vec2> listTextures;
                std::vector<glm::vec3> normales;
                std::vector<glm::vec2> textures;
                std::string nomTexture;
                while(strin!="}"&&fichier){
                    fichier>>strin;
                    if(strin=="p"){
                        glm::vec3 point;
                        fichier>>point.x;
                        fichier>>point.y;
                        fichier>>point.z;
                        points.push_back(point);
                        //std::cout<<point.x<<" "<<point.y<<" "<<point.z<<std::endl;
                    }
                    if(strin=="n"){
                        glm::vec3 normale;
                        fichier>>normale.x;
                        fichier>>normale.y;
                        fichier>>normale.z;
                        listeNormales.push_back(normale);
                        //std::cout<<normale.x<<" "<<normale.y<<" "<<normale.z<<std::endl;
                    }
                    if(strin=="t"){
                        glm::vec2 texture;
                        fichier>>texture.x;
                        fichier>>texture.y;
                        listTextures.push_back(texture);
                        //std::cout<<texture.x<<" "<<texture.y<<std::endl;
                    }
                    if(strin=="i"){
                        unsigned int indice;
                        fichier>>indice;
                        //std::cout<<indice<<std::endl;
                        normales.push_back(listeNormales.at(indice));
                        fichier>>indice;
                        //std::cout<<indice<<std::endl;
                        textures.push_back(listTextures.at(indice));
                    }
                    if(strin=="texture"){
                        fichier>>nomTexture;
                        std::cout<<nomTexture;
                    }
                }
                //ObjetScene objsc;
                std::vector<GLfloat>vertices;
                for(auto point:points){
                    vertices.push_back(point.x);
                    vertices.push_back(point.y);
                    vertices.push_back(point.z);
                }
                unsigned int normalOffset=vertices.size();
                for(auto normale:normales){
                    vertices.push_back(normale.x);
                    vertices.push_back(normale.y);
                    vertices.push_back(normale.z);
                }
                unsigned int textureOffset=vertices.size();
                for(auto texPoint:textures){
                    vertices.push_back(texPoint.x);
                    vertices.push_back(texPoint.y);
                }
                std::vector<unsigned int> indices={0,1,2,
                                                   2,3,1,
                                                   0,4,5,
                                                   5,1,0,
                                                   4,5,6,
                                                   6,7,5,
                                                   1,3,7};
                for(auto ver:vertices){
                    std::cout<<ver<<" ";
                }
                std::cout<<std::endl;
                //Objet3D obj3D(vertices,normalOffset,textureOffset,indices);
                //objets3D.push_back(Objet3D(vertices,normalOffset,textureOffset,indices));
                //std::cout<<objets3D.size()<<std::endl;
                //objsc.objet3D=0;
                //objsc.texture=0;
                objetsScene.push_back(ObjetScene(0,0));
                objetsScene.at(0).translate(glm::vec3(0.0,5.0,-25.0));
            }
        }
        fichier.close();
    }
}*/
