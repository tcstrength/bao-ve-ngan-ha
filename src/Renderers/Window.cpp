#include "Window.h"

Window::Window(Config& config)
:   m_config(config)
{
    setupGLFW();
    setupOpenGL();
    m_shader.load();
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::close()
{
    glfwSetWindowShouldClose(m_window, GLFW_TRUE);
}

bool Window::isOpen()
{
    return !glfwWindowShouldClose(m_window);
}

void Window::clear()
{
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    m_shader.bind();
}

void Window::display()
{
    glfwSwapBuffers(m_window);
}

void Window::draw(Drawable* drawable)
{
    drawable->draw();
}

glm::vec2 Window::getCenter()
{
    return glm::vec2(m_config.width / 2, m_config.height / 2);
}

void Window::setupGLFW()
{
    if (!glfwInit()) {
        LOG_ERROR("Failed to initialize GLFW3");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_SAMPLES, 4);

    if (m_config.fullscreen) {
        const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

        m_window = glfwCreateWindow(vidmode->width, vidmode->height, m_config.title, glfwGetPrimaryMonitor(), nullptr);
    }
    else {
        m_window = glfwCreateWindow(m_config.width, m_config.height, m_config.title, nullptr, nullptr);
    }

    if (m_window == nullptr)
    {
        LOG_ERROR("Failed to create window");
    }

    if (m_config.vsync == false)
    {
        glfwSwapInterval(0);
    }

    glfwMakeContextCurrent(m_window);
}

void Window::setupOpenGL()
{
    if (glewInit() != GLEW_OK)
    {
        LOG_ERROR("Failed to initialize GLEW");
    }

    glClearColor(0.3f, 0.5f, 0.4f, 1.0f);
//    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glBlendFunc (GL_ONE, GL_ONE);
}

GLFWwindow* Window::getWindow() const
{
    return m_window;
}
