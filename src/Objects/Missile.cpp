#include "Missile.h"

Missile::Missile(Context & context, Group& group, GameObject& owner)
:   GameObject(context)
,   m_group(group)
,   m_speed(owner.getAttr().missileSpeed)
,   m_damage(owner.getAttr().damage)
,   m_type(owner.getAttr().dmgType)
,   m_direction(-1)
,   m_owner(owner)
{
    m_sprite.setTexture(TextureManager::instance()->get(owner.getAttr().missile.c_str()));

    if (m_speed > 50)
    {
        m_speed = 50;
    }

    if (owner.getAttr().player == Player::COMPUTER)
    {
        LOG_DEBUG("WTF");
        m_direction = 1;
    }
}

void Missile::tick()
{
    float step = m_speed;

    if (m_speed > 25)
    {
        step = m_speed / std::sqrt(m_speed);
    }

    for (float i = step; i <= m_speed; i += step)
    {
        auto pos = getPosition();
        pos.y += m_direction * step;
        setPosition(pos);

        for (auto it : m_group.getObjects())
        {
            if (it.second->getAttr().player != m_owner.getAttr().player &&
                it.second->getAttr().hitpoints > 0 &&
                it.second->overlap(this))
            {
                it.second->beingHit(m_type, m_damage);
                setPosition(sf::Vector2f(-100, -100));
                break;
            }
        }
    }
}

void Missile::render()
{
    m_context.window.draw(m_sprite);

//    sf::CircleShape circle(20);
//    circle.setPosition(m_position);
//    m_context.window.draw(circle);
}

sf::Vector2f Missile::getPosition() const
{
    return m_position;
}

void Missile::setPosition(const sf::Vector2f & position)
{
    m_position = position;
    update();
}

sf::Vector2f Missile::getSize() const
{
    auto rect = m_sprite.getGlobalBounds();
    return sf::Vector2f(rect.width, rect.height);
}

void Missile::update()
{
    m_sprite.setPosition(getCenterPoint());
}

bool Missile::isDeath()
{
    return m_position.y <= 0;
}
