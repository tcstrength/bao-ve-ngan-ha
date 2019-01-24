#ifndef MISSILE_H
#define MISSILE_H

#include "../Context.h"
#include "GameObject.h"
#include "Group.h"

class Missile : public GameObject
{
public:
    Missile(Context& context, Group& group, GameObject& owner);

    void tick();

    void render();

    bool isDeath();

    sf::Vector2f getPosition() const;

    void setPosition(const sf::Vector2f & position);

    sf::Vector2f getSize() const;

private:
    void update();

    Group&       m_group;
    sf::Sprite   m_sprite;
    float        m_speed;
    int          m_damage;
    DamageType   m_type;
    int          m_direction;
    GameObject&  m_owner;
};

#endif // MISSILE_H
