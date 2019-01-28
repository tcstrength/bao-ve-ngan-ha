#ifndef CAMERA_H
#define CAMERA_H

#include "../Config.h"
#include "../Utils/Misc.h"
#include "../Utils/Log.h"
#include <cmath>
#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera(const Config& config);

    void setPosition(sf::Vector2f position);

    const sf::Vector2f& getPosition();

    void move(int dist, float rad);

    bool isChanged();

    sf::Vector2f transform(sf::Vector2f position);
private:
    const Config& m_config;
    sf::Vector2f m_position;
    sf::Vector2f m_lastPosition;
};

#endif // CAMERA_H
