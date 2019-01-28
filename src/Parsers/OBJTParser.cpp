#include "OBJTParser.h"

void OBJTParser::load(const char *fileName)
{
    optimize(fileName);
    for (uint i = 0; i < m_buffers.size(); ++i)
    {
        std::string key;
        std::string value;
        if (m_buffers[i][0] == '[')
        {
            m_ids.push_back(static_cast<uint>(std::stoul(m_buffers[i].substr(1, m_buffers[i].length() - 1))));
        }
        else
        {
            auto id = m_ids.back();
            auto equal = m_buffers[i].find('=');
            key = m_buffers[i].substr(0, equal);
            value = m_buffers[i].substr(equal + 1);
            m_keys[id][key] = value;
        }
    }

    for (auto key : m_keys)
        for (auto value : m_keys[key.first])
        {
            LOG_DEBUG(value.first << "=" << value.second);
        }
}

float OBJTParser::loadFloat(uint id, const char * key)
{
    if (isExist(id, key) == false)
        return 0;

    std::string number = m_keys[id][key];
    if (isNumber(number) == false)
    {
        return 0;
    }

    return std::stof(number);
}

int OBJTParser::loadInt(uint id, const char * key)
{
    if (isExist(id, key) == false)
        return 0;

    std::string number = m_keys[id][key];
    if (isNumber(number) == false)
    {
        return 0;
    }

    return std::stoi(number);
}

DamageType OBJTParser::loadDamageType(uint id, const char * key)
{
    if (isExist(id, key) == false)
        return DamageType::NORMAL;

    std::string str = loadString(id, key);
    if (str == "FIRE")
        return DamageType::FIRE;
    else if (str == "NUCLEAR")
        return DamageType::NUCLEAR;

    return DamageType::NORMAL;
}

Team OBJTParser::loadTeam(uint id, const char *key)
{
    if (isExist(id, key) == false)
        return Team::ELSE;

    std::string str = loadString(id, key);

    if (str == "ALLY")
        return Team::ALLY;
    else if (str == "ENEMY")
        return Team::ENEMY;

    return Team::ELSE;
}

std::string OBJTParser::loadString(uint id, const char * key)
{
    if (isExist(id, key) == false)
        return "Unknown";

    return m_keys[id][key];
}

sf::Color OBJTParser::loadColor(uint id, const char * key)
{

    if (isExist(id, key) == false)
        return sf::Color::White;

    auto color = sf::Color::White;
    auto value = m_keys[id][key];
    auto count = std::count(value.begin(), value.end(), ',');

    if (count < 3)
        return color;

    if (count == 3)
        std::sscanf(value.c_str(), "%d,%d,%d", &color.r, &color.g, &color.b);
    else if (count == 4)
        std::sscanf(value.c_str(), "%d,%d,%d", &color.r, &color.g, &color.b, &color.a);

    return color;
}

std::vector<uint> OBJTParser::getIndices()
{
    return m_ids;
}

void OBJTParser::optimize(const char *fileName)
{
    std::fstream is(fileName);
    std::string buffer;

    if (is.is_open() == false)
    {
        LOG_DEBUG("File not found " << fileName);
        return;
    }

    while (std::getline(is, buffer))
    {
        if (buffer[0] == '#')
            continue;

        if (buffer[0] == '[')
        {
            m_buffers.push_back(buffer);
            continue;
        }

        auto equalPos = buffer.find('=');
        if (equalPos != std::string::npos)
        {
            uint pre = static_cast<uint>(equalPos - 1);

            while (buffer[pre] == ' ')
            {
                buffer.erase(buffer.begin() + pre--);
            }

            uint pos = pre + 2;
            while (buffer[pos] == ' ')
            {
                buffer.erase(buffer.begin() + pos);
            }

            m_buffers.push_back(buffer);
        }
    }

    is.close();
}

bool OBJTParser::isNumber(std::string str)
{
    for (uint i = 0; i < str.length(); ++i)
    {
        if (str[i] != '.' && (str[i] > '9' || str[i] < '0'))
            return false;
    }

    return true;
}

bool OBJTParser::isExist(uint id, const char * key)
{
    if (m_keys.find(id) == m_keys.end())
        return false;

    if (m_keys[id].find(key) == m_keys[id].end())
        return false;

    return true;
}
