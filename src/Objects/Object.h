#ifndef OBJECT_H
#define OBJECT_H

#include "ObjectType.h"
#include "Missile.h"
#include "FloatingText.h"
#include "GameObject.h"
#include "../Context.h"

class Object : public GameObject
{
public:
    Object(Context& context, ObjectType& type);

    virtual ~Object();

    void tick();

    void render();

    /////////////////////////////////////////
    /// \brief attack attack others
    ///
    void attack(Group& group);

    /////////////////////////////////////////
    /// \brief beingHit hit this object and cause dmg
    ///                 auto make floating text when hit
    /// \param dmgType
    /// \param dmg
    ///
    void beingHit(DamageType dmgType, int dmg);

    void setPosition(const sf::Vector2f& position);

    sf::Vector2f getSize() const;

    Attributes& getAttr();

private:
    void update();

    void updateHpBar();

    void updateHpText();

    Attributes   m_attr;
    sf::Sprite   m_sprite;
    sf::Text     m_hpText;
    sf::Sprite   m_hpBar;
    sf::Sprite   m_hpBarBack;
    sf::Clock    m_clock;
    sf::Clock    m_attackClock;
    std::list<FloatingText*> m_floatTexts;
    std::list<Missile*> m_missiles;
};

#endif // OBJECT_H
