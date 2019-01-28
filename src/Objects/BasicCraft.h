#ifndef BASICCRAFT_H
#define BASICCRAFT_H

#include "Missile.h"

class BasicCraft : public GameObject
{
public:
    BasicCraft(Environment& environment);

    void attack();

    void tick();

private:
    void AIRun();

    GameObject* m_target;
};

#endif // BASICCRAFT_H
