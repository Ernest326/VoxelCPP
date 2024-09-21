#include "app.hpp"

App::~App() {}

App::App() {
}

void App::run() {

    Shader test_shader("shaders/test.vert", "shaders/test.frag");

    //Basic test triangle
    float vertices[]={
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    float colors[]={
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    //Triangle buffer data
    VertexArray VAO;
    VAO.addBuffer(new Buffer(vertices, sizeof(vertices), 3), 0);
    VAO.addBuffer(new Buffer(colors, sizeof(vertices), 3), 1);

    while(!window.closed()) {

        //Clear screen
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        window.clear();

        //Draw triangle
        test_shader.enable();
        VAO.bind();
        glDrawArrays(GL_TRIANGLES, 0, 36);
        VAO.unbind();
        test_shader.disable();

        //Update screen + input
        window.update();
    }

    glfwTerminate();
}
