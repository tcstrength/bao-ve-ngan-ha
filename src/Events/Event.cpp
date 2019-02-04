#include "Event.h"

Event::Event()
{

}

void Event::callSignals(EventType type)
{
    std::vector<EventSignal*>& signals = m_signals[type];
    for (uint i = 0; i < signals.size(); ++i)
    {
        signals[i]->callback(type, m_data);
    }
}

void Event::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    instance().m_data.key = key;

    switch(action)
    {
        case GLFW_PRESS:
            instance().callSignals(EventType::KEY_PRESS);
            break;

        case GLFW_RELEASE:
            instance().callSignals(EventType::KEY_RELEASE);
            break;
    }
}

void Event::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    instance().m_data.button = button;

    switch (action)
    {
        case GLFW_PRESS:
            instance().callSignals(EventType::MOUSE_PRESS);
            break;

        case GLFW_RELEASE:
            instance().callSignals(EventType::MOUSE_RELEASE);
            break;
    }
}

void Event::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    instance().callSignals(EventType::MOUSE_MOTION);
    instance().m_data.mousePos = glm::vec2(xpos, ypos);
}

void Event::init(GLFWwindow* window)
{
    glfwSetCursorPosCallback(window, cursorPosCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
}

void Event::reg(EventType type, EventSignal *signal)
{
    m_signals[type].push_back(signal);
}

Event& Event::instance()
{
    static Event event;
    return event;
}
