#include "camera.hpp"

Camera::Camera(){
    ProjectionMatrix=glm::mat4(1.0);
}

glm::mat4 Camera::getVPMatrix(){
    return ProjectionMatrix*getModelMatrix();
}

