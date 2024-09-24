#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS    1024
#define MAX_BUTTONS 32

class Window {

private:
    GLFWwindow* m_window;

    char* m_title;
    int m_width, m_height;

    bool m_key[MAX_KEYS];
    bool m_key_pressed[MAX_KEYS];
    bool m_button[MAX_BUTTONS];
    bool m_vsync;

public:
    Window(char* title, int width, int height, bool vsync=false);
    ~Window();

    bool closed() { return glfwWindowShouldClose(m_window); }

    void clear() const;
    void update();

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    bool isKeyHeld(unsigned int key) const;
    bool isKeyPressed(unsigned int key) const;
    bool isButtonPressed(unsigned int button) const;

    GLFWwindow* &getWindow() { return m_window; }

    double last_x, last_y;
    double mouse_x, mouse_y;
    double offset_x, offset_y;

private:
    bool init();
    bool firstMouse = true;

    friend void window_size_callback(GLFWwindow* window, int x, int y);
    friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
    friend void mouse_callback(GLFWwindow* window, double xpos, double ypos);

};