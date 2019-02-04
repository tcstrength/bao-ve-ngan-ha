#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <glm/glm.hpp>
#include "../Utils/Log.h"

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

class Parser
{
public:
    void load(const char* fileName);

    float loadFloat(uint id, const char* key);

    int loadInt(uint id, const char* key);

    std::string loadString(uint id, const char* key);

    glm::vec4 loadVec4(uint id, const char* key);

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
