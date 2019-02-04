#ifndef EVENT_H
#define EVENT_H

#include <GLFW/glfw3.h>
#include <map>
#include <bitset>
#include <vector>
#include <iostream>
#include "EventSignal.h"

class Event
{
public:
    static
    void init(GLFWwindow* window);

    static
    Event& instance();

    void reg(EventType type, EventSignal* signal);

private:
    Event();

    void callSignals(EventType type);

    static
    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

    static
    void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

    std::map<uint,std::vector<EventSignal*>> m_signals;
    EventData m_data;
};

#endif // EVENT_H
