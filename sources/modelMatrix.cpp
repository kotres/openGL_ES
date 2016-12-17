#include "modelMatrix.hpp"

ModelMatrix::ModelMatrix()
{
    scaleMatrix=glm::mat4(1.0);
    rotationMatrix=glm::mat4(1.0);
    translationMatrix=glm::mat4(1.0);
    axeRotation=glm::vec3(0.0,1.0,0.0);
}

void ModelMatrix::rotate(float angleRadian)
{
    rotationMatrix=glm::rotate(glm::mat4(1.0),angleRadian,axeRotation);
}

void ModelMatrix::rotateD(float angleRadian)
{
    rotationMatrix=glm::rotate(rotationMatrix,angleRadian,axeRotation);
}

void ModelMatrix::rotate(float gamma, float beta)
{
    rotationMatrix=glm::rotate(glm::mat4(1.0),gamma,glm::vec3(1,0,0));
    rotationMatrix=glm::rotate(rotationMatrix,beta,glm::vec3(0,1,0));
}

void ModelMatrix::scale(glm::vec3 s)
{
    scaleMatrix=glm::scale(glm::mat4(1.0),s);
}

void ModelMatrix::scaleD(glm::vec3 ds)
{
    scaleMatrix=glm::scale(scaleMatrix,ds);
}

void ModelMatrix::translate(glm::vec3 tr)
{
    translationMatrix=glm::translate(glm::mat4(1.0),tr);
}

void ModelMatrix::translateD(glm::vec3 dtr)
{
    translationMatrix=glm::translate(translationMatrix,dtr);
}


glm::mat4 ModelMatrix::getModelMatrix()
{
    return translationMatrix*rotationMatrix*scaleMatrix;
}
