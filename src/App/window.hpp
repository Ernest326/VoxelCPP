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
    bool m_button[MAX_BUTTONS];
    bool m_vsync;

public:
    Window(char* title, int width, int height, bool vsync=false);
    ~Window();

    bool closed() { return glfwWindowShouldClose(m_window); }

    void clear() const;
    void update() const;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    bool isKeyPressed(unsigned int key) const;
    bool isButtonPressed(unsigned int button) const;

    GLFWwindow* &getWindow() { return m_window; }

    double lastx;
    double lasty;
    double mousex;
    double mousey;

private:
    bool init();
    bool firstMouse = true;

    friend static void window_size_callback(GLFWwindow* window, int x, int y);
    friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
    friend static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

};