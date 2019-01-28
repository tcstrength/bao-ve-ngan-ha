#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Missile.h"

class Player : public GameObject
{
public:
    Player(Environment& env);

    void tick();

    void attack();

private:
};

#endif // PLAYER_H
