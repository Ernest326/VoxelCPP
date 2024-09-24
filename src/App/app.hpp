#pragma once

#include <iostream>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <imgui-docking/imgui/imgui.h>
#include <imgui-docking/imgui/backends/imgui_impl_glfw.h>
#include <imgui-docking/imgui/backends/imgui_impl_opengl3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "window.hpp"
#include "../Engine/buffers/buffers.hpp"
#include "../Engine/shader.hpp"
#include "../Engine/texture2d.hpp"
#include "../Engine/spectator_camera.hpp"

#define STB_IMAGE_IMPLEMENTATION

class App {

public:
    static constexpr int WIDTH=800;
    static constexpr int HEIGHT=800;

    App();
    ~App();

    void run();

private:

    float deltaTime, lastFrame;
    void calculateDeltaTime() {
        deltaTime = lastFrame-glfwGetTime();
        lastFrame = glfwGetTime();
    }

    void drawFrame();
    bool initGL();
    Window window{"Voxel Engine", WIDTH, HEIGHT};

    friend void mouse_callback(GLFWwindow* window, double xpos, double ypos);

};
