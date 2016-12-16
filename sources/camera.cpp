#include "camera.hpp"

Camera::Camera(){
    CameraMatrix=glm::mat4(1.0);
    ProjectionMatrix=glm::mat4(1.0);
    VPMatrix=CameraMatrix*ProjectionMatrix;
}

glm::mat4 Camera::getVPMatrix(){
    return VPMatrix;
}

