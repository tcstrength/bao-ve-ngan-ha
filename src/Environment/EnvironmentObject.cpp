#include "EnvironmentObject.h"

EnvironmentObject::EnvironmentObject()
:   m_maxDecayTime(2.f)
,   m_decayTime(m_maxDecayTime)
,   m_position(100.f, 100.f)
{

}

EnvironmentObject::~EnvironmentObject()
{
//    LOG_DEBUG("Object has been deleted " << this);
}

void EnvironmentObject::tick()
{
    if (isDead())
    {
        m_decayTime = m_decayTime - m_clock.getElapsedTime().asSeconds();

        if (m_decayTime > 0.f)
        {
            auto color = getColor();
            color.a = static_cast<sf::Uint8>(m_decayTime / m_maxDecayTime * 255.f);
            setColor(color);
        }
    }

    m_clock.restart();
}

bool EnvironmentObject::overlap(EnvironmentObject * other)
{
    bool left   = getCenteredPosition().x        < other->getCenteredPosition().x + other->getSize().x;
    bool right  = other->getCenteredPosition().x < getCenteredPosition().x + getSize().x;
    bool top    = getCenteredPosition().y        < other->getCenteredPosition().y + other->getSize().y;
    bool bottom = other->getCenteredPosition().y < getCenteredPosition().y + getSize().y;

    return left && right && top && bottom;
}

float EnvironmentObject::getDecayTime() const
{
    return m_decayTime;
}

void EnvironmentObject::setDecayTime(float decayTime)
{
    m_decayTime = decayTime;
}

sf::Vector2f EnvironmentObject::getCenteredPosition()
{
    static sf::Vector2f center;
    center.x = m_position.x - getSize().x / 2;
    center.y = m_position.y - getSize().y / 2;
    return center;
}

sf::Vector2f EnvironmentObject::getPosition() const
{
    return m_position;
}

void EnvironmentObject::setPosition(const sf::Vector2f & position)
{
    m_position = position;
    update();
}
