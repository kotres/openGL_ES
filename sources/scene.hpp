#ifndef SCENE_HPP
#define SCENE_HPP

#include "camera.hpp"
#include "objet3D.hpp"
#include "objetScene.hpp"
#include "texture.hpp"
#include <vector>
#include <set>

class Scene{
    unsigned int cameraUtilisee;
public:
    void loadMap();
    Scene();
    std::vector<Objet3D> objets3D;
    std::vector<Texture> textures;
    std::vector<Camera> cameras;
    std::vector<ObjetScene> objetsScene;
    Shader shader;
    void utiliserCamera(unsigned int i);
    Camera& getCamera();
    void dessiner();
};

#endif
