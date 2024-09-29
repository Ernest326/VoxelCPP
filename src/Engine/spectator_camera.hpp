#pragma once
#include "camera.hpp"

class SpectatorCamera : public Camera {
    
private:
    float speed = 3.0f;
    float sensitivity = 0.5f;

public:
    SpectatorCamera(glm::vec3 pos=glm::vec3(0,0,0), glm::vec3 up=glm::vec3(0,1,0), float pitch=0.0f, float yaw=-90.0f, float fov=90.0f, bool orthographic=false, float near = 0.01f, float far = 1000.0f) : Camera(pos, up, pitch, yaw, fov, orthographic, near, far) {}

    enum CAMERA_MOVEMENT {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    void processKeyboard(CAMERA_MOVEMENT direction, float deltaTime);
    void processMouse(float x, float y);

};