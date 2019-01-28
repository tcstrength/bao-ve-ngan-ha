#include "BasicCraft.h"
BasicCraft::BasicCraft(Environment & environment)
:   GameObject (environment, ObjectTypeManager::instance()->get(1))
{
}

void BasicCraft::attack()
{
    if (canAttack())
    {
        auto msl = new Missile(m_env, this);
        msl->setPosition(getPosition());
        GameObject::attack();
    }
}

void BasicCraft::tick()
{
    attack();
    AIRun();
    GameObject::tick();
}

void BasicCraft::AIRun()
{
    m_target = nullptr;

    for (auto obj : m_env.pick(getPosition(), 500))
    {
        auto gobj = static_cast<GameObject*>(obj);
        if (gobj->getAttr().team != m_attr.team)
        {
            m_target = gobj;
            break;
        }
    }

    if (m_target != nullptr)
    {
        sf::Vector2f pos = m_target->getPosition();
        sf::Vector2f myPos = getPosition();
        float rad = static_cast<float>(atan2(pos.y - myPos.y, pos.x - myPos.x));
        m_attr.angle = 90 + (rad / (PI / 180));
        update();
    }
}
