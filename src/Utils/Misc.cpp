#include "Misc.h"

float Misc::deg2Rad(float deg)
{
    return deg * RAD_UNIT;
}

float Misc::rad2Deg(float rad)
{
    return rad / RAD_UNIT;
}

int Misc::rand2m(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

float Misc::randf()
{
    return static_cast<float>(randlf());
}

double Misc::randlf()
{
    bool neg = rand() % 2;

    if (neg)
        return -1 * rand() / RAND_MAX;

    return rand() % RAND_MAX;
}

float Misc::distance2Vec(const glm::vec2& p1, const glm::vec2 & p2)
{
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return static_cast<float>(std::sqrt(dx * dx + dy * dy));
}

glm::vec2& Misc::polarProjection(const glm::vec2 & p1, const float & offset, const float & radian)
{
    static glm::vec2 result;
    result.x = p1.x + offset * std::cos(radian);
    result.y = p1.y + offset * std::sin(radian);
    return result;
}
