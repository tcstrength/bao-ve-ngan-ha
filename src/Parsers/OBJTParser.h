#ifndef OBJTPARSER_H
#define OBJTPARSER_H

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "../Utils/Log.h"
#include "../Objects/ObjectType.h"

/*
# This is comment
# Next line is ID of object type
[0]
scale        = 5.0
angle        = 0.0
damage       = 15
damageType   = NORMAL
attackSpeed  = 0.25
hitpoints    = 500
decay        = 1
missileSpeed = 15.0
missileCount = 3
missile      = hero_missile.png
texture      = hero.png
player       = PLAYER
*/

class OBJTParser
{
public:
    void load(const char* fileName);

    float loadFloat(uint id, const char* key);

    int loadInt(uint id, const char* key);

    DamageType loadDamageType(uint id, const char* key);

    Team loadTeam(uint id, const char* key);

    std::string loadString(uint id, const char* key);

    sf::Color loadColor(uint id, const char* key);

    std::vector<uint> getIndices();

private:
    void optimize(const char* fileName);

    bool isNumber(std::string str);

    bool isExist(uint id, const char* key);

    std::vector<std::string> m_buffers;
    std::vector<uint> m_ids;
    std::map<uint, std::map<std::string, std::string>> m_keys;
};

#endif // OBJTPARSER_H
