#include "Config.h"
#include "Context.h"
#include "Renderers/Window.h"
#include "Renderers/Sprite.h"
#include "Events/Event.h"

class Test : public EventSignal
{
public:
    void callback(EventType type, const EventData& data)
    {
        LOG_DEBUG(type << " : " << data.key);
    }
};

int main()
{
    Config config;
    Context context(config);
    Event::init(context.window.getWindow());
    Test test;

    Event::instance().reg(EventType::KEY_PRESS, &test);
    Event::instance().reg(EventType::KEY_RELEASE, &test);

    while (context.window.isOpen())
    {
        context.window.clear();

        context.window.display();
    }

    return 0;
}
