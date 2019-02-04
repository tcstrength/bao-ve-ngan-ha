#ifndef EVENTSIGNAL_H
#define EVENTSIGNAL_H

#include <functional>
#include "EventData.h"
#include "EventType.h"

class EventSignal
{
public:
    virtual ~EventSignal();

    virtual void callback(EventType type, const EventData& data) = 0;
private:
};

#endif // EVENTSIGNAL_H
