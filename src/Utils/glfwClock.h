#ifndef GLFWCLOCK_H
#define GLFWCLOCK_H

#include <GLFW/glfw3.h>

class glfwClock
{
public:
    glfwClock();

    void restart();

    float getTime();
private:
    float m_startTime;
};

#endif // GLFWCLOCK_H
