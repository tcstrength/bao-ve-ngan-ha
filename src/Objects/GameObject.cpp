#include "GameObject.h"

GameObject::GameObject(Context & context)
:   m_context(context)
,   m_centered(true)
{

}

Attributes &GameObject::getAttr()
{
    static Attributes attr;
    return attr;
}

void GameObject::beingHit(DamageType dmgType, int dmg)
{

}

void GameObject::setPosition(const sf::Vector2f & position)
{
    m_position = position;
    update();
}

const sf::Vector2f &GameObject::getPosition() const
{
    return m_position;
}

bool GameObject::overlap(GameObject * other)
{
    bool left   = getCenterPoint().x        < other->getCenterPoint().x + other->getSize().x;
    bool right  = other->getCenterPoint().x < getCenterPoint().x + getSize().x;
    bool top    = getCenterPoint().y        < other->getCenterPoint().y + other->getSize().y;
    bool bottom = other->getCenterPoint().y < getCenterPoint().y + getSize().y;

    return left && right && top && bottom;
}

void GameObject::center(bool centered)
{
    m_centered = centered;
}

sf::Vector2f GameObject::getCenterPoint()
{
    sf::Vector2f pos = getPosition();

    if (m_centered)
    {
        sf::Vector2f size = getSize();

        pos.x = pos.x - size.x / 2;
        pos.y = pos.y - size.y / 2;
    }

    return pos;
}
