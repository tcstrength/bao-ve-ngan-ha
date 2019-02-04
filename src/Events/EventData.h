#ifndef EVENTDATA_H
#define EVENTDATA_H

#include <glm/glm.hpp>
#include "EventType.h"

struct EventData
{
    glm::vec2 mousePos;
    int key;
    int button;
};

#endif // EVENTDATA_H
