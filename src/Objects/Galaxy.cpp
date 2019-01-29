#include "Galaxy.h"

Galaxy::Galaxy(Environment & env)
:   m_env(env)
,   m_index(m_env.add(this))
{

}

void Galaxy::loadOBJT(const char * objtFile)
{
    std::string realPath = std::string("galaxies/") + objtFile;
    OBJTParser parser;
    parser.load(realPath.c_str());

    int numGreenCraft = parser.loadInt(0, "greencraft");
    int numGreenCraftLarge = parser.loadInt(0, "greencraft_large");
    m_radius = parser.loadInt(0, "radius");
    m_name = parser.loadString(0, "name");

    m_border.setRadius(m_radius);
    m_border.setPointCount(100);
    m_border.setFillColor(sf::Color(0, 0, 0, 0));
    m_border.setOutlineColor(sf::Color::Red);
    m_border.setOutlineThickness(5);
    m_border.setOrigin(m_radius, m_radius);
    m_border.setPosition(m_position);

    for (int i = 0; i < numGreenCraft; ++i)
    {
        sf::Vector2f pos = polarProjection(m_position, randBetween(-m_radius + 100, m_radius - 100), randf() * PI);
        m_objects.push_back(new BasicCraft(m_env));
        m_env.last()->setPosition(pos);
    }

    for (int i = 0; i < numGreenCraftLarge; ++i)
    {
        sf::Vector2f pos = polarProjection(m_position, randBetween(-m_radius + 100, m_radius - 100), randf() * PI);
        m_objects.push_back(new BasicCraft(m_env, 2));
        m_env.last()->setPosition(pos);
    }

    for (int i = 0; i < 500; ++i)
    {
        sf::Vector2f pos = polarProjection(m_position, randBetween(-m_radius + 100, m_radius - 100), randf() * PI);
        new SpecialEffect(m_env, "glow.png", pos, sf::Color(rand() % 255, rand() % 255, rand() % 255), randf());
        m_env.last()->setPosition(pos);
    }
}

void Galaxy::tick()
{
//    for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
//    {
//        if ((*it) != nullptr && distanceBetween(m_position, (*it)->getPosition()) > m_radius)
//        {
//            (*it)->beHit(nullptr, DamageType::NUCLEAR, 1000);
//            (*it) = nullptr;
//        }
//    }
}

void Galaxy::render(sf::RenderWindow & window)
{
    sf::Vector2f pos = m_border.getPosition();
    m_border.setPosition(m_env.getCamera().transform(pos));
    window.draw(m_border);
    m_border.setPosition(pos);
}

void Galaxy::update()
{

}

bool Galaxy::isDead()
{
    return false;
}

sf::Vector2f Galaxy::getSize()
{
    return sf::Vector2f(0, 0);
}

float Galaxy::getRadius()
{
    return m_radius;
}
