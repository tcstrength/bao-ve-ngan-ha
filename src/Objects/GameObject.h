#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Context.h"
#include "Attributes.h"

class GameObject
{
public:
    GameObject(Context& context);

    virtual ~GameObject() {  }

    virtual void render() = 0;

    virtual void tick() = 0;

    virtual sf::Vector2f getSize() const = 0;

    virtual Attributes& getAttr();

    virtual void beingHit(DamageType dmgType, int dmg);

    virtual void setPosition(const sf::Vector2f& position);

    const   sf::Vector2f& getPosition() const;

            bool overlap(GameObject* object);

            void center(bool centered = true);
protected:
    virtual void update() = 0;

            sf::Vector2f getCenterPoint();

    Context&     m_context;
    sf::Vector2f m_position;
    bool         m_centered;
};

#endif // GAMEOBJECT_H
