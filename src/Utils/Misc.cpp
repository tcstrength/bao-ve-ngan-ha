#include "Misc.h"

float randf()
{
    bool neg = rand() % 2;
    if (neg)
    {
        return -1 * static_cast<float>(rand()) / RAND_MAX;
    }

    return static_cast<float>(rand()) / RAND_MAX;
}

float sfDeg2Deg(float sfAngle)
{
    return sfAngle - 90;
}

float deg2sfDeg(float angle)
{
    return angle + 90;
}

float rad2Deg(float rad)
{
    return rad / RAD_UNIT;
}

float deg2Rad(float deg)
{
    return deg * RAD_UNIT;
}

sf::Vector2f polarProjection(const sf::Vector2f & pos, const float & dist, const float & rad)
{
    sf::Vector2f result;
    result.x = pos.x + dist * std::cos(rad);
    result.y = pos.y + dist * std::sin(rad);
    return result;
}

float radBetween2Vec(const sf::Vector2f & src, const sf::Vector2f & dst)
{
    return std::atan2(dst.y - src.y, dst.x - src.x);
}

int randBetween(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
