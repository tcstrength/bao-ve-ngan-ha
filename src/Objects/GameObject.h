#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Environment/Environment.h"
#include "Attributes.h"

class GameObject : public EnvironmentObject
{
public:
    GameObject(Environment& environment, Team team, float scale = 1.f, sf::Vector2f pos = sf::Vector2f(100.f, 100.f));

    virtual void tick();

    virtual void render(sf::RenderWindow& window);

    virtual void update();

    virtual bool isDead();

    virtual void attack();

            void del();

            void beHit(DamageType type, int dmg);

    const   Attributes& getAttr() const;

            void setAttr(const Attributes& attr);

protected:
            bool canAttack();

            void setColor(const sf::Color& color);

            sf::Color getColor() const;

            sf::Vector2f getSize();

            sf::Vector2f getSpriteSize();

            void correctAttr();

            void updateHpBar();

            void updateHpText();

protected:
    Environment& m_env;
    uint         m_index;
    Attributes   m_attr;
    sf::Sprite   m_sprite;
    sf::Text     m_hpText;
    sf::Sprite   m_hpBar;
    sf::Sprite   m_hpBarBack;
    sf::Clock    m_attackClock;
};

#endif // GAMEOBJECT_H
