#pragma once
#include <iostream>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.hpp"

class App {

public:
    static constexpr int WIDTH=800;
    static constexpr int HEIGHT=800;

    App();
    ~App();

    void run();

private:
    void drawFrame();
    bool initGL();

    Window window{"Voxel Engine", WIDTH, HEIGHT};

};
