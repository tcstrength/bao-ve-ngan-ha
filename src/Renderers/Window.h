#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include "../Config.h"
#include "../Shaders/Shader2D.h"
#include "Drawable.h"

class Window {
public:
    Window(Config& config);

    virtual ~Window();

    void close();

    bool isOpen();

    void clear();

    void display();

    void draw(Drawable* drawable);

    glm::vec2 getCenter();

    GLFWwindow* getWindow() const;

private:
    void setupGLFW();

    void setupOpenGL();
private:

    Config&     m_config;
    GLFWwindow* m_window;
    Shader2D    m_shader;
};

#endif // WINDOW_H
