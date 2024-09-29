#include "camera.hpp"

Camera::Camera(glm::vec3 pos, glm::vec3 up, float pitch, float yaw, float fov, bool orthographic, float near, float far) {

    this->position = pos;
    this->worldUp = up;
    this->pitch = pitch;
    this->yaw = yaw;
    this->fov = fov;
    this->orthographic = orthographic;
    this->near = near;
    this->far = far;

    updateCameraVectors();

}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, position+front, worldUp);
}

glm::mat4 Camera::getProjectionMatrix(float width, float height) {
    if(this->orthographic) {
        return glm::ortho(0.0f, width, height, 0.0f, -1.0f, 1.0f);
    } else {
        return glm::perspective(glm::radians(this->fov/2), width/height, near, far);
    }
}

void Camera::updateCameraVectors() {

    front.x = cos(glm::radians(yaw))*cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw))*cos(glm::radians(pitch));

    right = glm::cross(front, worldUp);
    up = glm::cross(right, front);
}