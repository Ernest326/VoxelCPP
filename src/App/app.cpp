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

    ChunkManager chunkManager;

    //Main camera
    SpectatorCamera cam(glm::vec3(0, 2, 5));

    Shader cube_shader("shaders/voxel.vert", "shaders/voxel.frag");
    Texture2D chunk_tex("res/tilesheet.png", GL_REPEAT, GL_NEAREST);

    Chunk test_chunk;
    test_chunk.setup();
    //Chunk test_chunk_2(1, 0, 0);

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
        chunkManager.update(chunkManager.getNearestChunkPos(cam.position));

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
         //Camera Rotation
        if(focused) {
            cam.processMouse(window.offset_x, window.offset_y);
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

        //chunkManager.chunkUpdate(cam.position);

        //Draw chunk
        /*
        cube_shader.enable();
        cube_shader.setMatrix4("projection", cam.getProjectionMatrix(WIDTH, HEIGHT));
        cube_shader.setMatrix4("view", cam.getViewMatrix());
        cube_shader.setMatrix4("model", glm::mat4(1.0));

        chunk_tex.bind();
        test_chunk.DrawChunk();
        test_chunk_2.DrawChunk();
        chunk_tex.unbind();
        
        cube_shader.disable();
        */

        cube_shader.enable();
        cube_shader.setMatrix4("projection", cam.getProjectionMatrix(WIDTH, HEIGHT));
        cube_shader.setMatrix4("view", cam.getViewMatrix());
        cube_shader.setMatrix4("model", glm::mat4(1.0));
        chunk_tex.bind();
        //test_chunk.DrawChunk();
        chunkManager.draw(cam.position);
        chunk_tex.unbind();
        cube_shader.disable();

        glm::vec3 chunk_pos = chunkManager.getNearestChunkPos(cam.position);
        //ImGUI
        ImGui::Begin("Debug");
        ImGui::Text("FPS: %d",(int)(1.0f/deltaTime));
        ImGui::Text("Position: %.2f, %.2f, %.2f", cam.position.x, cam.position.y, cam.position.z);
        ImGui::Text("Chunk Position: %.0f, %.0f, %.0f", chunk_pos.x, chunk_pos.y, chunk_pos.z);
        ImGui::End();

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