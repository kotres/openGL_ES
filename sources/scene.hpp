#ifndef SCENE_HPP
#define SCENE_HPP

#include "camera.hpp"
#include "objet3D.hpp"
#include "objetScene.hpp"
#include <vector>

class Scene{
    Camera cameraUtilisee;
    Shader shaderUtilise;
public:
    std::vector<Objet3D> objets3D;
    std::vector<Camera> cameras;
    std::vector<ObjetScene> objetsScene;
    std::vector<Shader> shaders;
    void utiliserCamera(unsigned int i);
    void utiliserShader(unsigned int i);
    void dessiner();
};

#endif
