#include "glfwClock.h"

glfwClock::glfwClock()
{
    m_startTime = glfwGetTime();
}

void glfwClock::restart()
{
    m_startTime = glfwGetTime();
}

float glfwClock::getTime()
{
    return glfwGetTime() - m_startTime;
}
