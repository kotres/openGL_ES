#ifndef MODELMATRIX_HPP
#define MODELMATRIX_HPP

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

class ModelMatrix
{
    glm::mat4 translationMatrix;
    glm::mat4 rotationMatrix;
    glm::vec3 axeRotation;
    glm::mat4 scaleMatrix;
public:
    ModelMatrix();
    void translate(glm::vec3 tr);
    void translateD(glm::vec3 dtr);
    void rotate(float angleRadian);
    void rotate(float gamma, float beta);
    void rotateD(float angleRadian);
    void scale(glm::vec3 s);
    void scaleD(glm::vec3 ds);
    glm::mat4 getModelMatrix();
};

#endif
