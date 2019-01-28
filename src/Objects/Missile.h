#ifndef MISSILE_H
#define MISSILE_H

#include "GameObject.h"
#include "../Utils/Misc.h"

class Missile : public EnvironmentObject
{
public:
    Missile(Environment& env, GameObject* owner);

    void tick();

    void update();

    void render(sf::RenderWindow& window);

    bool isDead();

    sf::Vector2f getSize();

    void attack() {}

private:
    void move(int dist);

    bool check();

    void del();

private:
    Environment& m_env;
    uint         m_index;
    GameObject*  m_owner;
    sf::Sprite   m_sprite;
    int          m_distance;
    int          m_maxDistance;
    int          m_speed;
    int          m_damage;
    DamageType   m_dmgType;
    float        m_angle;
};

#endif // MISSILE_H
