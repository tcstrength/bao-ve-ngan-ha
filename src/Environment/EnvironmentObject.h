#ifndef ENVIRONMENTOBJECT_H
#define ENVIRONMENTOBJECT_H

#include "../Context.h"

class EnvironmentObject
{
public:
    friend class Environment;

    friend class GameObject;

    EnvironmentObject();

    virtual ~EnvironmentObject();

    virtual void tick();

    virtual void update() = 0;

    virtual void render(sf::RenderWindow& window) = 0;

    virtual bool isDead() = 0;

    virtual bool overlap(EnvironmentObject* other);

    virtual sf::Vector2f getSize() = 0;

    virtual void setColor(const sf::Color& color) = 0;

    virtual sf::Color getColor() const = 0;

    sf::Vector2f getPosition() const;

    void setPosition(const sf::Vector2f & position);

protected:
    float getDecayTime() const;

    void setDecayTime(float decayTime);

    //////////////////////////////////////////
    /// imagePos
    ///  -----------------------------
    /// |                            |
    /// |        objPos              |
    /// |____________________________|
    /// \brief getCenteredPosition get image/sprite position after centered
    /// \return a point
    ///
    sf::Vector2f getCenteredPosition();

private:
    float        m_maxDecayTime;
    float        m_decayTime;
    sf::Vector2f m_position;
    sf::Clock    m_clock;
};

#endif // ENVIRONMENTOBJECT_H
