#ifndef SCENE_HPP
#define SCENE_HPP

#include "camera.hpp"
#include "objet3D.hpp"
#include "objetScene.hpp"
#include "texture.hpp"
#include <vector>
#include <set>

//classe scene qui contient tout ce qui est utilise pour le rendement a l'ecran qui n'est pas GUI
//contient aussi la physique

class Scene{
    unsigned int cameraUtilisee;
    void detecterCollision();
public:
    void loadMap();
    Scene();
    std::vector<Objet3D> objets3D;
    std::vector<Texture> textures;
    std::vector<Camera> cameras;
    ObjetScene joueur;
    std::vector<ObjetScene> objetsScene;
    Shader shader;
    void utiliserCamera(unsigned int i);
    Camera& getCamera();
    void dessiner();
    void miseAJour();
};

#endif
