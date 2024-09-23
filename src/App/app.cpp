#include "app.hpp"
#define STB_IMAGE_IMPLEMENTATION

App::~App() {}

App::App() {
}

void App::run() {

    Shader test_shader("shaders/test_3d.vert", "shaders/test_3d.frag");

    //3D projection matrices
    glm::mat4 projection = glm::mat4(1.0);
    glm::mat4 cam_view = glm::mat4(1.0);
    glm::mat4 model = glm::mat4(1.0);
    
    cam_view = glm::translate(cam_view, glm::vec3(0.0f, 0.0f, -5.0f));
    projection = glm::perspective(glm::radians(45.0f), (float)window.getWidth()/(float)window.getHeight(), 0.1f, 100.0f);

    //Basic test cube
    GLfloat cube_vertices[] = {
        // front
        -0.5, -0.5,  0.5,
         0.5, -0.5,  0.5,
         0.5,  0.5,  0.5,
        -0.5,  0.5,  0.5,
        // back
        -0.5, -0.5, -0.5,
         0.5, -0.5, -0.5,
         0.5,  0.5, -0.5,
        -0.5,  0.5, -0.5
    };

    GLfloat cube_colors[] = {
        // front colors
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 1.0,
        // back colors
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 1.0
    };

    GLushort cube_elements[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

    VertexArray VAO;
    //Cube buffer data
    VAO.addBuffer(new Buffer(cube_vertices, sizeof(cube_vertices), 3), 0);
    VAO.addBuffer(new Buffer(cube_colors, sizeof(cube_colors), 3), 1);
    IndexBuffer EBO(cube_elements, sizeof(cube_elements));

    glEnable(GL_DEPTH_TEST);

    while(!window.closed()) {

        //Clear screen
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        window.clear();

        //Draw triangle
        test_shader.enable();
        test_shader.setMatrix4("projection", projection);
        test_shader.setMatrix4("view", cam_view);
        test_shader.setMatrix4("model", model);

        VAO.bind();
        EBO.bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
        VAO.unbind();
        EBO.unbind();

        test_shader.disable();

        //ROTATE THAT SHIIII
        model = glm::rotate(model, glm::radians(5.0f), glm::vec3(1.0f, 0.3f, 0.5f));

        //Update screen + input
        window.update();
    }
    glfwTerminate();
    
}
