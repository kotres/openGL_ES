#include "modelMatrix.hpp"

ModelMatrix::ModelMatrix()
{
    scaleMatrix=glm::mat4(1.0);
    rotationMatrix=glm::mat4(1.0);
    translationMatrix=glm::mat4(1.0);
    axeRotation=glm::vec3(0.0,0.0,0.0);
    rotationX=0.0;
    rotationY=0.0;
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
    rotationX=gamma;
    rotationY=beta;
    rotationMatrix=glm::rotate(glm::mat4(1.0),gamma,glm::vec3(1,0,0));
    rotationMatrix=glm::rotate(rotationMatrix,beta,glm::vec3(0,0,1));
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
    position=tr;
    translationMatrix=glm::translate(glm::mat4(1.0),tr);
}

void ModelMatrix::translateD(glm::vec3 dtr)
{
    position+=dtr;
    translationMatrix=glm::translate(translationMatrix,dtr);
}

void ModelMatrix::translateD(glm::vec3 dtr, float angle){
    position+=dtr;
    /*glm::mat4 rot=glm::rotate(glm::mat4(1.0),angle,axeRotation);
    dtr=glm::vec3(rot*glm::vec4(dtr,0.0));*/
    glm::mat3 rot=glm::mat3(glm::vec3(cos(angle),-sin(angle),0.0f),
                            glm::vec3(sin(angle),cos(angle),0.0f),
                            glm::vec3(0.0f));
    dtr=rot*dtr;
    translationMatrix=glm::translate(translationMatrix,dtr);
}

glm::mat4 ModelMatrix::getModelMatrix()
{
    return translationMatrix*rotationMatrix*scaleMatrix;
}

glm::mat4 ModelMatrix::getRotationMatrix()
{
    return rotationMatrix;
}
