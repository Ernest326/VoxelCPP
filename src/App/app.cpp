#include "app.hpp"

App::~App() {}

App::App() {
}

void App::run() {

    //ImGUI init
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; 

    ImGui_ImplGlfw_InitForOpenGL(window.getWindow(), true);
	ImGui_ImplOpenGL3_Init();

    bool focused = true;
    bool wireframe=false;

    //Main camera
    SpectatorCamera cam(glm::vec3(0, 0, 5));

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

        //ImGUI frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        calculateDeltaTime();

        //ImGUI
        ImGui::Begin("Debug");
        ImGui::Text("FPS: %d",(int)(1.0f/deltaTime));
        ImGui::Text("Position: %.2f, %.2f, %.2f", cam.position.x, cam.position.y, cam.position.z);
        ImGui::End();

        //Process Spectator Camera Input
        if(window.isKeyHeld(GLFW_KEY_W)) {
            cam.processKeyboard(SpectatorCamera::FORWARD, deltaTime);
        }
        if(window.isKeyHeld(GLFW_KEY_A)) {
            cam.processKeyboard(SpectatorCamera::LEFT, deltaTime);
        }
        if(window.isKeyHeld(GLFW_KEY_S)) {
            cam.processKeyboard(SpectatorCamera::BACKWARD, deltaTime);
        }
        if(window.isKeyHeld(GLFW_KEY_D)) {
            cam.processKeyboard(SpectatorCamera::RIGHT, deltaTime);
        }

        //Other input
        if(window.isKeyPressed(GLFW_KEY_Q)) {
            glfwSetWindowShouldClose(window.getWindow(), true);
        }

        if(window.isKeyPressed(GLFW_KEY_Z)) {
            wireframe=!wireframe;
            if(wireframe) {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            } else {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            }
        }
        if(window.isKeyPressed(GLFW_KEY_F)) {
            focused=!focused;
            if(focused) {
                glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            } else {
                glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
        }

        //Camera Rotation
        if(focused) {
            cam.processMouse(window.offset_x, window.offset_y);
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
        model = glm::rotate(model, glm::radians(10.0f*deltaTime), glm::vec3(1.0f, 0.3f, 0.5f));

        //ImGUI update
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        //Update screen + input
        window.update();

    }
    //Clear ImGUI
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    
}