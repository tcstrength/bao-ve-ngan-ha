#include "Parser.h"

void Parser::load(const char *fileName)
{
    m_ids.clear();
    m_keys.clear();
    m_buffers.clear();

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
}

float Parser::loadFloat(uint id, const char * key)
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

int Parser::loadInt(uint id, const char * key)
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

std::string Parser::loadString(uint id, const char * key)
{
    if (isExist(id, key) == false)
        return "Unknown";

    return m_keys[id][key];
}

glm::vec4 Parser::loadVec4(uint id, const char * key)
{
    auto vec4 = glm::vec4(1.f);

    if (isExist(id, key))
    {
        auto value = m_keys[id][key];
        auto count = std::count(value.begin(), value.end(), ',');

        switch(count)
        {
            case 1:
                vec4 = glm::vec4(loadFloat(id, key));
                break;
            case 2:
                std::sscanf(value.c_str(), "%f,%f", &vec4.x, &vec4.y);
                break;
            case 3:
                std::sscanf(value.c_str(), "%f,%f,%f", &vec4.x, &vec4.y, &vec4.z);
                break;
            case 4:
                std::sscanf(value.c_str(), "%f,%f,%f,%f", &vec4.x, &vec4.y, &vec4.z, &vec4.w);
                break;
        }
    }

    return vec4;
}

std::vector<uint> Parser::getIndices()
{
    return m_ids;
}

void Parser::optimize(const char *fileName)
{
    std::fstream is(fileName);
    std::string buffer;

    if (is.is_open() == false)
    {
        LOG_ERROR("File not found " << fileName);
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

bool Parser::isNumber(std::string str)
{
    for (uint i = 0; i < str.length(); ++i)
    {
        if (str[i] != '.' && (str[i] > '9' || str[i] < '0'))
            return false;
    }

    return true;
}

bool Parser::isExist(uint id, const char * key)
{
    if (m_keys.find(id) == m_keys.end())
        return false;

    if (m_keys[id].find(key) == m_keys[id].end())
        return false;

    return true;
}
