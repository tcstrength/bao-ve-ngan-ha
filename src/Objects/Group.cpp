#include "Group.h"

Group::Group()
{

}

Group::~Group()
{

}

void Group::tick()
{
    for (auto it : m_objects)
    {
        if (it.second->getAttr().hitpoints == 0 && it.second->getAttr().decay <= 0 && it.second->getAttr().player == Player::COMPUTER)
        {
            remove(it.first);
        }
        else if (player()->getAttr().player != it.second->getAttr().player
                 && player()->getAttr().hitpoints != 0
                 && player()->overlap(it.second)
                 && it.second->getAttr().hitpoints != 0)
        {
            player()->beingHit(DamageType::NORMAL, 50);
            it.second->beingHit(DamageType::NORMAL, 20);
        }
        else
        {
            it.second->tick();
        }
    }
}

void Group::render()
{
    for (auto it : m_objects)
        it.second->render();
}

uint Group::add(GameObject* object)
{
    uint index = m_indexer.allocate();

    m_objects[index] = object;
    m_last = object;

    return index;
}

void Group::remove(uint index)
{
    auto it = m_objects.find(index);

    if (it != m_objects.end())
    {
        m_objects.erase(it);
        m_indexer.deallocate(index);
    }
}

Group *Group::pick(sf::Vector2f center, double radius)
{
    Group* group = new Group();
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
            group->add(it.second);
        }
    }

    return group;
}

GameObject* Group::last()
{
    return m_last;
}

GameObject *Group::player()
{
    for (auto it : m_objects)
        if (it.second->getAttr().player == Player::PLAYER)
            return it.second;

    return nullptr;
}

bool Group::hasObject(uint index)
{
    auto it = m_objects.find(index);

    return it != m_objects.end();
}

void Group::clear()
{
    m_objects.clear();
}

void Group::destroyObjects()
{
    for (auto it : m_objects)
        delete it.second;
    clear();
}

std::map<uint, GameObject *> Group::getObjects() const
{
    return m_objects;
}
