#ifndef SPECIALEFFECT_H
#define SPECIALEFFECT_H

#include "../Environment/Environment.h"
#include "../Environment/EnvironmentObject.h"

class SpecialEffect : public EnvironmentObject
{
public:
    SpecialEffect(Environment& env, const char* texture, sf::Vector2f position, sf::Color color, float scale = 1.f);

    void tick();

    void update();

    void render(sf::RenderWindow& window);

    bool isDead();

    sf::Vector2f getSize();

private:
    Environment& m_env;
    uint         m_index;
    sf::Sprite   m_efx;
};

#endif // SPECIALEFFECT_H
