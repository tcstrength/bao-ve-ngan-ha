#ifndef CAMERA_H
#define CAMERA_H

#include "../Config.h"
#include "../Utils/Misc.h"
#include "../Utils/Log.h"
#include "../Environment/EnvironmentObject.h"

class Camera
{
public:
    Camera(const Config& config);

    void tick();

    void bind(EnvironmentObject* obj);

    void setPosition(sf::Vector2f position);

    const sf::Vector2f& getPosition();

    void move(int dist, float rad);

    bool isChanged();

    sf::Vector2f transform(sf::Vector2f position);

private:
    const Config& m_config;
    sf::Vector2f m_position;
    sf::Vector2f m_lastPosition;
    EnvironmentObject* m_bindObj;
};

#endif // CAMERA_H
