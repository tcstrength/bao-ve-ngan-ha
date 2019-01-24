#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include "../Managers/TextureManager.h"

enum Player
{
    PLAYER,
    COMPUTER,
    STRUCTURE,
};

enum DamageType
{
    FIRE,
    NUCLEAR,
    NORMAL,
};

struct Attributes
{
    float        scale = 1.f;
    float        angle = 0.f;
    int          damage = 0.f;
    int          hitpoints = 0;
    int          maxHitpoints = 0;
    float        decay = 1;
    float        attackSpeed = 0.f;
    float        missileSpeed = 4.f;
    int          missileCount = 1;
    sf::Color    color = sf::Color::White;
    std::string  texture = "unknown.png";
    std::string  missile = "unknown.png";
    DamageType   dmgType = DamageType::NORMAL;
    Player       player = Player::STRUCTURE;
};

#endif // ATTRIBUTES_H
