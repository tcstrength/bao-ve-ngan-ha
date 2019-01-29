#include "Missile.h"

Missile::Missile(Environment& env, GameObject* owner)
:   m_env(env)
,   m_index(m_env.mslAdd(this))
,   m_owner(owner)
,   m_distance(0)
,   m_maxDistance(1000)
,   m_speed(owner->getAttr().missileSpeed)
,   m_damage(owner->getAttr().damage)
,   m_dmgType(owner->getAttr().dmgType)
,   m_angle(owner->getAttr().angle)
{
    m_sprite.setTexture(TextureManager::instance()->get(owner->getAttr().missile.c_str()));
    m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,
                       m_sprite.getLocalBounds().height / 2);
    m_sprite.rotate(m_angle);
}

void Missile::tick()
{
    if (m_distance > m_maxDistance)
    {
        del();
        return;
    }

    static int step = 5;

    int carry = m_speed % step;
    int count = m_speed / step;

    for (int i = 0; i < count; ++i)
    {
        move(step);
        if (check())
        {
            del();
            return;
        }
    }

    move(carry);
    if (check())
    {
        del();
    }
}

void Missile::update()
{
    m_sprite.setPosition(m_env.getContext().camera.transform(m_position));
}

void Missile::render(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}

bool Missile::isDead()
{
    return false;
}

sf::Vector2f Missile::getSize()
{
    auto rect = m_sprite.getGlobalBounds();
    return sf::Vector2f(rect.width, rect.height);
}

void Missile::move(int dist)
{
    if (dist > 0)
    {
        m_distance += dist;
        float rad = deg2Rad(sfDeg2Deg(m_angle));
        setPosition(polarProjection(getPosition(), dist, rad));
    }
}

bool Missile::check()
{
    GameObject* obj = static_cast<GameObject*>(m_env.overlap(this));

    if (obj && obj->getAttr().team != m_owner->getAttr().team
            && obj != m_owner
            && obj->getAttr().hitpoints > 0)
    {
        obj->beHit(m_owner, m_dmgType, m_damage);
        return true;
    }

    return false;
}

void Missile::del()
{
    m_env.mslDel(m_index);
}
