#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include "../Managers/TextureManager.h"

enum Team
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
    Team         team = Team::COMPUTER;
    std::string  texture = "hero.png";
    sf::Color    color = sf::Color::White;
    float        scale = 1.f;
    float        angle = 0.f;
    int          damage = 0.f;
    DamageType   dmgType = DamageType::NORMAL;
    int          hitpoints = 100;
    int          maxHitpoints = 100;
    float        attackSpeed = 3.f;
    std::string  missile = "hero_missile.png";
    int          missileSpeed = 0.f;
    int          missileCount = 0;
    bool         showHP = true;
};

#endif // ATTRIBUTES_H
