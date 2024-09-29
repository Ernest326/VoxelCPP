#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {

public:
    float pitch, yaw;
    glm::vec3 front, right, up;
    glm::vec3 position;
    
    float fov;
    float near, far;
    bool orthographic;

public:
    Camera(glm::vec3 pos=glm::vec3(0,0,0), glm::vec3 up=glm::vec3(0,1,0), float pitch=0.0f, float yaw=-90.0f, float fov=90.0f, bool orthographic=false, float near = 0.01f, float far = 1000.0f);
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix(float width, float height);

protected:
    glm::vec3 worldUp;

public:
    void updateCameraVectors();

};