#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera{
    glm::mat4 VPMatrix;
    glm::mat4 CameraMatrix;
    glm::mat4 ProjectionMatrix;
public:
    Camera();
    glm::mat4 getVPMatrix();
};

#endif
