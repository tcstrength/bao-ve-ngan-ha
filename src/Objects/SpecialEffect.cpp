#include "SpecialEffect.h"

SpecialEffect::SpecialEffect(Environment & env, const char * texture, sf::Vector2f position, sf::Color color, float scale)
:   m_env(env)
,   m_index(env.efxAdd(this))
{
    m_efx.setTexture(TextureManager::instance()->get(texture));
    m_efx.setColor(color);
    m_efx.setScale(scale, scale);
    setPosition(position);
}

void SpecialEffect::tick()
{
    m_efx.setPosition(m_env.getCamera().transform(getPosition()));
}

void SpecialEffect::update()
{
}

void SpecialEffect::render(sf::RenderWindow & window)
{
    window.draw(m_efx);
}

bool SpecialEffect::isDead()
{
    return false;
}

sf::Vector2f SpecialEffect::getSize()
{
    return sf::Vector2f(0, 0);
}
