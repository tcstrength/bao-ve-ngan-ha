#include "BasicCraft.h"
BasicCraft::BasicCraft(Environment & environment, uint craftId)
:   GameObject (environment, ObjectTypeManager::instance()->get(craftId))
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

    if (m_target != nullptr && m_target->getAttr().hitpoints > 0)
    {
        sf::Vector2f pos = m_target->getPosition();
        sf::Vector2f myPos = getPosition();
        float oldRad = deg2Rad(sfDeg2Deg(getAngle()));
        float rad = radBetween2Vec(myPos, pos);
        setAngle(deg2sfDeg(rad2Deg(rad)));

        if (std::abs(rad - oldRad) > PI / 8)
        {
            m_attackClock.restart();
        }
        attack();
    }
}









