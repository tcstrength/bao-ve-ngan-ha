#include "Camera.h"

Camera::Camera(const Config& config)
:   m_config(config)
,   m_position(config.width / 2, config.height / 2)
{

}

void Camera::setPosition(sf::Vector2f position)
{
    m_lastPosition = m_position;
    m_position = position;
}

bool Camera::isChanged()
{
    return m_position != m_lastPosition;
}

const sf::Vector2f &Camera::getPosition()
{
    return m_position;
}

void Camera::move(int dist, float rad)
{
    LOG_DEBUG("Move");
    auto pos = getPosition();
    pos.x = pos.x + dist * std::cos(rad);
    pos.y = pos.y + dist * std::sin(rad);
    setPosition(pos);
}

sf::Vector2f Camera::transform(sf::Vector2f position)
{
    sf::Vector2f topLeft;
    topLeft.x = m_position.x - m_config.width / 2;
    topLeft.y = m_position.y - m_config.height / 2;
    return position - topLeft;
}
