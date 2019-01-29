#ifndef Hero_H
#define Hero_H

#include "GameObject.h"
#include "Missile.h"
#include "../Managers/ObjectTypeManager.h"

class Hero : public GameObject
{
public:
    Hero(Environment& env);

    void tick();

    void attack();

private:

    void handleKeys();
};

#endif // Hero_H
