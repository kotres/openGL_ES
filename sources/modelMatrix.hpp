#ifndef MODELMATRIX_HPP
#define MODELMATRIX_HPP

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

// utilise pour tous ce qui concerne prosition, rotation et translation
// est utilise par ObjetScene et Camera en ce moment

class ModelMatrix
{
protected:
    glm::mat4 translationMatrix;
    glm::mat4 rotationMatrix;
    glm::mat4 scaleMatrix;
    glm::vec3 position;
    float rotationX,rotationY;
public:
    glm::vec3 axeRotation;
    ModelMatrix();
    void translate(glm::vec3 tr);
    void translateD(glm::vec3 dtr);
    void translateD(glm::vec3 dtr,float angle);
    void rotate(float angleRadian);
    void rotate(float gamma, float beta);
    void rotateD(float angleRadian);
    void scale(glm::vec3 s);
    void scaleD(glm::vec3 ds);
    glm::mat4 getModelMatrix();
    glm::mat4 getRotationMatrix();
};

#endif
