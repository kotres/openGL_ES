#ifndef SCENE_HPP
#define SCENE_HPP

#include "camera.hpp"
#include "objet3D.hpp"
#include "objetScene.hpp"
#include <vector>

class Scene{
    unsigned int cameraUtilisee;
public:
    Scene();
    std::vector<Objet3D> objets3D;
    std::vector<Camera> cameras;
    std::vector<ObjetScene> objetsScene;
    Shader shader;
    void utiliserCamera(unsigned int i);
    Camera& getCamera();
    void dessiner();
};

#endif
