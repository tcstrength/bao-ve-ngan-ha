#ifndef GALAXY_H
#define GALAXY_H

#include "GameObject.h"
#include "BasicCraft.h"
#include "SpecialEffect.h"

class Galaxy : public EnvironmentObject
{
public:
    Galaxy(Environment& env);

    void loadOBJT(const char* objtFile);

    void tick();

    void render(sf::RenderWindow& window);

    void update();

    bool isDead();

    sf::Vector2f getSize();

    float getRadius();
private:
    Environment& m_env;
    sf::CircleShape m_border;
    std::vector<GameObject*> m_objects;
    float m_radius;
    uint m_index;
    std::string m_name;
};

#endif // GALAXY_H
