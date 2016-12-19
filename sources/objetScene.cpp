#include "objetScene.hpp"

void ObjetScene::dessiner()
{
    objet3D->dessiner(camera->getShaderPtr(),camera->getVPMatrix()*getModelMatrix());
}
