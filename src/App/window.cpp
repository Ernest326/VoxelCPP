#include "window.hpp"

void window_size_callback(GLFWwindow* window, int x, int y);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

Window::~Window()
{
}

Window::Window(char* title, int width, int height, bool vsync)
{
	this->m_title = title;
	this->m_width = width;
	this->m_height = height;
    this->m_vsync = vsync;

    if(!init()) {
        std::runtime_error("ERROR: Window creation failed!");
    }

}

bool Window::init()
{

    if (!glfwInit()) {
		std::cout << "ERROR: Failed to initialize GLFW!" << std::endl;
		return false;
	}

    m_window = glfwCreateWindow(m_width, m_height, m_title, GL_FALSE, GL_FALSE);

	if (!m_window) {
		std::cout << "ERROR: Failed to create window!" << std::endl;
		return false;
	}

    //Minimum OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwMakeContextCurrent(m_window);
    glfwSetWindowUserPointer(m_window, this);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "ERROR: Failed to initialize GLAD!" << std::endl;
        return false;
    }

	glfwSetWindowSizeCallback(m_window, window_size_callback);
	glfwSetKeyCallback(m_window, key_callback);
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
	glfwSetCursorPosCallback(m_window, mouse_callback);

    if (m_vsync) {
        glfwSwapInterval(1);
    }
    std::cout << "VSYNC ENABLED: " << m_vsync << std::endl;

	for (int i = 0; i < MAX_KEYS; i++) {
		m_key[i] = false;
	}

	for (int i = 0; i < MAX_KEYS; i++) {
		m_key_pressed[i] = false;
	}

	for (int i = 0; i < MAX_BUTTONS; i++) {
		m_button[i] = false;
	}

	return true;
}

void Window::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() {
    glfwSwapBuffers(m_window);
	offset_x=0;
	offset_y=0;
	for(int i=0; i<MAX_KEYS; i++){
		m_key_pressed[i]=false;
	}
    glfwPollEvents();
}


bool Window::isKeyHeld(unsigned int key) const
{
	if (key >= MAX_KEYS) {
		return false;
	}
	return m_key[key];
}

bool Window::isKeyPressed(unsigned int key) const
{
	if (key >= MAX_KEYS) {
		return false;
	}
	return m_key_pressed[key];
}

bool Window::isButtonPressed(unsigned int button) const
{
	if (button >= MAX_BUTTONS) {
		return false;
	}
	return m_button[button];
}

void window_size_callback(GLFWwindow* window, int x, int y) {
	glViewport(0, 0, x, y);

	Window* win = (Window*)glfwGetWindowUserPointer(window);

	win->m_width = x;
	win->m_height = y;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_key[key] = action != GLFW_RELEASE;
	win->m_key_pressed[key] = action == GLFW_PRESS;
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_button[button] = action != GLFW_RELEASE;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	Window* win = (Window*)glfwGetWindowUserPointer(window);

	win->mouse_x = xpos;
	win->mouse_y = ypos;

	if (win->firstMouse) {
		win->firstMouse = false;

		win->last_x = xpos;
		win->last_y = ypos;
	}

	win->offset_x = xpos - win->last_x;
	win->offset_y = win->last_y - ypos;

	win->last_x = xpos;
	win->last_y = ypos;
    
}