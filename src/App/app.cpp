#include "app.hpp"

App::~App() {}

App::App() {
}

void App::run() {

    while(!window.closed()) {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        window.clear();
        window.update();
    }

    glfwTerminate();
}
