#include "Environment.h"

Environment::Environment(Context & context)
:   m_context(context)
{

}

Environment::~Environment()
{
    clear(m_objects);
    clear(m_missiles);
    clear(m_spcEfxs);
}

uint Environment::add(EnvironmentObject * obj)
{
    uint index = m_index.allocate();

    m_objects[index] = obj;
    m_lastObject = obj;

    return index;
}

uint Environment::mslAdd(EnvironmentObject * obj)
{
    uint index = m_index.allocate();
    m_missiles[index] = obj;
    return index;
}

uint Environment::efxAdd(EnvironmentObject * obj)
{
    uint index = m_index.allocate();
    m_spcEfxs[index] = obj;
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

bool Environment::mslDel(uint id)
{
    auto it = m_missiles.find(id);

    if (it != m_missiles.end())
    {
        delete it->second;
        m_index.deallocate(id);
        m_missiles.erase(it);
        return true;
    }

    return false;
}

bool Environment::efxDel(uint id)
{
    auto it = m_spcEfxs.find(id);

    if (it != m_missiles.end())
    {
        delete it->second;
        m_index.deallocate(id);
        m_spcEfxs.erase(it);
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

EnvironmentObject *Environment::last()
{
    return m_lastObject;
}

void Environment::tick()
{
    for (auto it = m_spcEfxs.begin(); it != m_spcEfxs.end(); ++it)
    {
        it->second->tick();
    }

    for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
    {
        it->second->tick();
    }

    for (auto it = m_missiles.begin(); it != m_missiles.end(); ++it)
    {
        it->second->tick();
    }
}

void Environment::render()
{
    for (auto it = m_spcEfxs.begin(); it != m_spcEfxs.end(); ++it)
    {
        it->second->render(m_context.window);
    }

    for (auto it : m_objects)
    {
        it.second->render(m_context.window);
    }

    for (auto it = m_missiles.begin(); it != m_missiles.end(); ++it)
    {
        it->second->render(m_context.window);
    }
}

Context &Environment::getContext()
{
    return m_context;
}

Camera &Environment::getCamera()
{
    return m_context.camera;
}

std::list<EnvironmentObject *> Environment::pick(sf::Vector2f center, int radius)
{
    std::list<EnvironmentObject*> objects;
    sf::Vector2f pos;
    double dx;
    double dy;

    for (auto it : m_objects)
    {
        pos = it.second->getPosition();
        dx = std::pow(center.x - pos.x, 2);
        dy = std::pow(center.y - pos.y, 2);

        if (std::sqrt(dx + dy) < radius)
        {
            objects.push_back(it.second);
        }
    }

    return objects;
}

std::map<uint, EnvironmentObject *> Environment::getObjects() const
{
    return m_objects;
}

void Environment::clear(std::map<uint, EnvironmentObject *> map)
{
    for (auto it : map)
        delete it.second;

}
