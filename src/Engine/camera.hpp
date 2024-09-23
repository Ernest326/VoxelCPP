#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {

public:
    float pitch, yaw;
    glm::vec3 front, right, up;
    glm::vec3 position;
    glm::mat4 projection;

public:
    Camera(glm::vec3 pos=glm::vec3(0,0,0), glm::vec3 up=glm::vec3(0,1,0), float pitch=0.0f, float yaw=-90.0f);
    glm::mat4 getViewMatrix();

protected:
    void updateCameraVectors();
    glm::vec3 worldUp;

};