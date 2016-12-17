#include "camera.hpp"

Camera::Camera(){
    shader=nullptr;
    setPerspective(0.78539816339,1.0,0.1,100.0);
}

Shader* Camera::getShaderPtr(){
    return shader;
}

void Camera::setFOV(float f)
{
    fov=f;
    ProjectionMatrix=glm::perspective(fov,ratio,Znear,Zfar);
}

void Camera::setRatio(float r)
{
    ratio=r;
    ProjectionMatrix=glm::perspective(fov,ratio,Znear,Zfar);
}

void Camera::setZ(float zn,float zf)
{
    Znear=zn;
    Zfar=zf;
    ProjectionMatrix=glm::perspective(fov,ratio,Znear,Zfar);
}

void Camera::setPerspective(float f, float r, float zn, float zf)
{
    fov=f;
    ratio=r;
    Znear=zn;
    Zfar=zf;
    ProjectionMatrix=glm::perspective(fov,ratio,Znear,Zfar);
}

glm::mat4 Camera::getVPMatrix(){
    return ProjectionMatrix*getModelMatrix();
}

