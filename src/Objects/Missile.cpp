#include "Missile.h"

Missile::Missile(Environment& env, const Attributes& attr)
:   GameObject (env, attr.team)
,   m_distance(0)
,   m_maxDistance(attr.damage * attr.missileSpeed * 20)
{
    m_attr = attr;
    m_attr.scale = 1.f;
    m_attr.maxHitpoints = 0;
    m_attr.showHP = false;
    m_sprite.setTexture(TextureManager::instance()->get(m_attr.missile.c_str()));
}

void Missile::tick()
{
    if (m_distance > m_maxDistance)
    {
        del();
        return;
    }

    static int step = 5;

    int carry = m_attr.missileSpeed % step;
    int count = m_attr.missileSpeed / step;

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

void Missile::move(int dist)
{
    if (dist > 0)
    {
        m_distance += dist;
        sf::Vector2f nextPos = getPosition();
        float rad = (m_attr.angle - 90) * static_cast<float>(PI / 180);
        nextPos.x = nextPos.x + dist * std::cos(rad);
        nextPos.y = nextPos.y + dist * std::sin(rad);
        setPosition(nextPos);
    }

    LOG_DEBUG(this << ", " << m_distance);
}

bool Missile::check()
{
    GameObject* obj = static_cast<GameObject*>(m_env.overlap(this));

    if (obj && obj->getAttr().team != this->getAttr().team)
    {
        obj->beHit(m_attr.dmgType, m_attr.damage);
        return true;
    }

    return false;
}
