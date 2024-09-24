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

    front.x = cos(glm::radians(yaw))*cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw))*cos(glm::radians(pitch));

    right = glm::cross(front, worldUp);
    up = glm::cross(right, front);

}

