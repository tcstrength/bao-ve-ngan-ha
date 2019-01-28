#include "Environment.h"

Environment::Environment(Context & context)
:   m_context(context)
{

}

Environment::~Environment()
{
    for (auto obj : m_objects)
    {
        if (obj.second != nullptr)
        {
            delete obj.second;
        }
    }
}

uint Environment::add(EnvironmentObject * obj)
{
    uint index = m_index.allocate();

    m_objects[index] = obj;

    return index;
}

bool Environment::del(uint id)
{
    auto it = m_objects.find(id);

    if (it != m_objects.end())
    {
        delete it->second;
        m_index.deallocate(id);
        m_objects.erase(it);
        return true;
    }

    return false;
}

EnvironmentObject *Environment::get(uint id)
{
    auto it = m_objects.find(id);

    if (it != m_objects.end())
    {
        return it->second;
    }

    return nullptr;
}

EnvironmentObject *Environment::overlap(EnvironmentObject * obj)
{
    if (obj != nullptr)
    {
        for (auto it : m_objects)
        {
            if (it.second == obj)
            {
                continue;
            }
            else if (obj->overlap(it.second))
            {
                return it.second;
            }
        }
    }

    return nullptr;
}

void Environment::tick()
{
    for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
    {
        it->second->tick();
    }
}

void Environment::render()
{
    for (auto it : m_objects)
    {
        it.second->render(m_context.window);
    }
}

Context &Environment::getContext()
{
    return m_context;
}
