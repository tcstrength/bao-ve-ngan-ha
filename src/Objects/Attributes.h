#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include "../Managers/TextureManager.h"

enum Team
{
    ALLY,
    ENEMY,
    ELSE,
};

enum DamageType
{
    FIRE,
    NUCLEAR,
    NORMAL,
};

struct Attributes
{
    Team         team = Team::ENEMY;
    std::string  texture = "hero.png";
    sf::Color    color = sf::Color::White;
    float        scale = 1.f;
    float        angle = 0.f;
    int          speed = 0.f;
    int          damage = 0.f;
    DamageType   dmgType = DamageType::NORMAL;
    int          hitpoints = 100;
    int          maxHitpoints = 100;
    float        attackSpeed = 3.f;
    std::string  missile = "hero_missile.png";
    int          missileSpeed = 0.f;
    int          missileCount = 0;
    bool         showHP = true;
    float        decay = 0.f;
    bool         autoAttack = false;
    int          exp = 0;
};

#endif // ATTRIBUTES_H
