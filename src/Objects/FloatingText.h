#ifndef FLOATINGTEXT_H
#define FLOATINGTEXT_H

#include "../Context.h"
#include "../Utils/Misc.h"
#include "GameObject.h"

class FloatingText : public GameObject
{
public:
    FloatingText(Context& context);

    void tick();

    void render();

    void setPosition(const sf::Vector2f & position);

    void setText(sf::String text);

    bool isDeath();

    sf::Vector2f getSize() const;
protected:
    void update();

private:
    sf::Text     m_text;
    sf::Vector2f m_vel;
};

#endif // FLOATINGTEXT_H
