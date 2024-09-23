#include "camera.hpp"

Camera::Camera(glm::vec3 pos, glm::vec3 up, float pitch, float yaw) {

    this->position = pos;
    this->worldUp = up;
    this->pitch = pitch;
    this->yaw = yaw;

    updateCameraVectors();
    
}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, position+front, worldUp);
}

void Camera::updateCameraVectors() {

    float x = cos(glm::radians(yaw))*cos(glm::radians(pitch));
    float y = sin(glm::radians(pitch));
    float z = sin(glm::radians(yaw))*cos(glm::radians(pitch));

    front = glm::normalize(glm::vec3(x,y,z));
    right = glm::cross(front, worldUp);
    up = glm::cross(right, front);

}

