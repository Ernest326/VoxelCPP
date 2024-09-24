#include "spectator_camera.hpp"

void SpectatorCamera::processKeyboard(CAMERA_MOVEMENT direction, float deltaTime) {

    float v = speed*deltaTime;

    if(direction==FORWARD) {
        position+=v*front;
    }
    if(direction==BACKWARD) {
        position+=v*-front;
    }
    if(direction==RIGHT) {
        position+=v*right;
    }
    if(direction==LEFT) {
        position+=v*-right;
    }

    if(direction==UP) {
        position+=v*worldUp;
    }
    if(direction==DOWN) {
        position+=v*-worldUp;
    }

    updateCameraVectors();
    
}

void SpectatorCamera::processMouse(float x, float y) {

    x*=sensitivity;
    y*=sensitivity;

    pitch -= y;
    yaw += x;

    updateCameraVectors();

}