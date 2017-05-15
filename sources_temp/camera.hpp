#ifndef CAMERA_HPP
#define CAMERA_HPP

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include "modelMatrix.hpp"
#include "shader.hpp"

// utilise pour creer et gerer la camera

class Camera: public ModelMatrix{
    glm::mat4 ProjectionMatrix;
    float ratio;
    float fov;
    float Znear,Zfar;
public:
    Camera();
    //Shader *shader;
    //Shader* getShaderPtr();
    void setRatio(float r);
    void setFOV(float f);
    void setZ(float zn,float zf);
    void setPerspective(float f,float r,float zn,float zf);
    glm::mat4 getVPMatrix();
};

#endif
