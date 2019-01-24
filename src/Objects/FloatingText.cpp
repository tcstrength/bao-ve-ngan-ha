#include "FloatingText.h"

FloatingText::FloatingText(Context& context)
:   GameObject(context)
,   m_text("Default", m_context.font)
,   m_vel(sf::Vector2f(randf(), randf()))
{
    m_text.setCharacterSize(20);
    m_text.setFillColor(sf::Color(128 + rand() % 128, 255, 128 + rand() % 128));
    m_text.setStyle(sf::Text::Bold);
}

void FloatingText::tick()
{
    auto color = m_text.getFillColor();
    m_position.y -= 2;
    m_position += m_vel;

    color.a -= 1;

    m_text.setFillColor(color);
    m_text.setPosition(m_position);

}

void FloatingText::render()
{
    m_context.window.draw(m_text);
}

void FloatingText::setPosition(const sf::Vector2f & position)
{
    m_position = position;
}

void FloatingText::setText(sf::String text)
{
    m_text.setString(text);
}

bool FloatingText::isDeath()
{
    return m_text.getFillColor().a == 0;
}

sf::Vector2f FloatingText::getSize() const
{
    sf::FloatRect rect = m_text.getGlobalBounds();
    return sf::Vector2f(rect.width, rect.height);
}

void FloatingText::update()
{

}
