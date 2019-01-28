#ifndef MISSILE_H
#define MISSILE_H

#include "GameObject.h"
#include "../Utils/Misc.h"

class Missile : public GameObject
{
public:
    Missile(Environment& env,const Attributes& attr);

    void tick();

private:
    void move(int dist);

    bool check();

private:

    int  m_distance;
    int  m_maxDistance;
};

#endif // MISSILE_H
