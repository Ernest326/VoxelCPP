#include "app.hpp"
#define STB_IMAGE_IMPLEMENTATION

App::~App() {}

App::App() {
}

void App::run() {



    //Main camera
    SpectatorCamera cam(glm::vec3(0, 0, -5));

    Shader test_shader("shaders/test_tex.vert", "shaders/test_tex.frag");
    Texture2D tex_grass("res/grass.png", GL_REPEAT, GL_NEAREST);

    //3D projection matrices
    glm::mat4 projection = glm::mat4(1.0);
    glm::mat4 cam_view = glm::mat4(1.0);
    glm::mat4 model = glm::mat4(1.0);
    
    cam_view = glm::translate(cam_view, glm::vec3(0.0f, 0.0f, -5.0f));
    projection = glm::perspective(glm::radians(45.0f), (float)window.getWidth()/(float)window.getHeight(), 0.1f, 100.0f);

    //Cube
	GLfloat cube_vertices[] =
	{
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

    VertexArray VAO;
    VAO.addBuffer(new Buffer(cube_vertices, sizeof(cube_vertices), 3), 0, 5, 0);
    VAO.addBuffer(new Buffer(cube_vertices, sizeof(cube_vertices), 2), 1, 5, 3);

    //Disable mouse so you can look around
	glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //Enable OpenGL stuff
    glEnable(GL_DEPTH_TEST);

    while(!window.closed()) {

        //Clear screen
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        window.clear();

        calculateDeltaTime();
        
        //Process Spectator Camera Input
        if(window.isKeyPressed(GLFW_KEY_W)) {
            cam.processKeyboard(SpectatorCamera::FORWARD, deltaTime);
        }
        if(window.isKeyPressed(GLFW_KEY_A)) {
            cam.processKeyboard(SpectatorCamera::LEFT, deltaTime);
        }
        if(window.isKeyPressed(GLFW_KEY_S)) {
            cam.processKeyboard(SpectatorCamera::BACKWARD, deltaTime);
        }
        if(window.isKeyPressed(GLFW_KEY_D)) {
            cam.processKeyboard(SpectatorCamera::RIGHT, deltaTime);
        }
        cam.processMouse(window.offset_x, window.offset_y);

        //Other input
        if(window.isKeyPressed(GLFW_KEY_Q)) {
            glfwSetWindowShouldClose(window.getWindow(), true);
        }
        if(window.isKeyPressed(GLFW_KEY_1)) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        if(window.isKeyPressed(GLFW_KEY_2)) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

        //Draw triangle
        test_shader.enable();
        test_shader.setMatrix4("projection", projection);
        test_shader.setMatrix4("view", cam.getViewMatrix());
        test_shader.setMatrix4("model", model);

        tex_grass.bind();
        VAO.bind();
        glDrawArrays(GL_TRIANGLES, 0, 36);
        VAO.unbind();
        tex_grass.unbind();
        test_shader.disable();

        //ROTATE THAT SHIIII
        model = glm::rotate(model, glm::radians(1.0f), glm::vec3(1.0f, 0.3f, 0.5f));

        //Update screen + input
        window.update();
    }
    glfwTerminate();
    
}