#include "ObjectTypeManager.h"


ObjectTypeManager *ObjectTypeManager::instance()
{
    static ObjectTypeManager mng;
    return &mng;
}

ObjectType &ObjectTypeManager::make(uint id)
{
    add(new ObjectType(id));
    return get(id);
}

void ObjectTypeManager::add(ObjectType* objectType)
{
    auto it = m_objectTypes.find(objectType->id);

    if (it == m_objectTypes.end())
    {
        m_objectTypes[objectType->id] = objectType;
    }
    else
    {
        LOG_DEBUG("object type has conflicted id = " << objectType->id);
    }
}

ObjectType& ObjectTypeManager::get(uint id)
{
    auto it = m_objectTypes.find(id);
    return *it->second;
}

bool ObjectTypeManager::load(const char * fileName)
{
    std::string path = std::string("types/") + fileName;
    std::ifstream inStr(path);
    std::string buffer;
    ObjectType* type = nullptr;
    int id = -1;

    while (std::getline(inStr, buffer))
    {
//        LOG_DEBUG(buffer);

        if (buffer[0] == '#')
            continue;

        if (buffer.rfind("[Id") != std::string::npos)
        {
            id = std::stoi(buffer.substr(buffer.rfind("=") + 1, buffer.size() - 5));
//            LOG_DEBUG(id);
            type = &make(static_cast<uint>(id));
        }
        else if (buffer.rfind("scale") != std::string::npos && type != nullptr)
        {
            type->attr.scale = std::stof(buffer.substr(buffer.rfind("=") + 1));
//            LOG_DEBUG(type->attr.scale);
        }
        else if (buffer.rfind("angle") != std::string::npos && type != nullptr)
        {
            type->attr.angle = std::stof(buffer.substr(buffer.rfind("=") + 1));
//            LOG_DEBUG(type->attr.angle);
        }
        else if (buffer.rfind("damage=") != std::string::npos && type != nullptr)
        {
            type->attr.damage = std::stoi(buffer.substr(buffer.rfind("=") + 1));
//            LOG_DEBUG(type->attr.damage);
        }
        else if (buffer.rfind("texture") != std::string::npos && type != nullptr)
        {
            type->attr.texture = buffer.substr(buffer.rfind("=") + 1);
//            LOG_DEBUG(type->attr.texture);
        }
        else if (buffer.rfind("missile=") != std::string::npos && type != nullptr)
        {
            type->attr.missile = buffer.substr(buffer.rfind("=") + 1);
        }
        else if (buffer.rfind("damageType") != std::string::npos && type != nullptr)
        {
            std::string dmg = buffer.substr(buffer.rfind("=") + 1);
            if (dmg == "NUCLEAR")
            {
                type->attr.dmgType = DamageType::NUCLEAR;
            }
            else if (dmg == "FIRE")
            {
                type->attr.dmgType = DamageType::FIRE;
            }
        }
        else if (buffer.rfind("attackSpeed") != std::string::npos && type != nullptr)
        {
//            LOG_DEBUG(buffer.substr(buffer.rfind("=") + 1));
            type->attr.attackSpeed = std::stof(buffer.substr(buffer.rfind("=") + 1));
        }
        else if (buffer.rfind("missileSpeed") != std::string::npos && type != nullptr)
        {
//            LOG_DEBUG(buffer.substr(buffer.rfind("=") + 1));
            type->attr.missileSpeed = std::stof(buffer.substr(buffer.rfind("=") + 1));
        }
        else if (buffer.rfind("missileCount") != std::string::npos && type != nullptr)
        {
            type->attr.missileCount = std::stoi(buffer.substr(buffer.rfind("=") + 1));
        }
        else if (buffer.rfind("hitpoints") != std::string::npos && type != nullptr)
        {
//            LOG_DEBUG(buffer.substr(buffer.rfind("=") + 1));
            type->attr.hitpoints = std::stoi(buffer.substr(buffer.rfind("=") + 1));
            type->attr.maxHitpoints = type->attr.hitpoints;
        }
        else if (buffer.rfind("decay") != std::string::npos && type != nullptr)
        {
//            LOG_DEBUG(buffer.substr(buffer.rfind("=") + 1));
            //type->attr.decay = std::stof(buffer.substr(buffer.rfind("=") + 1));
        }
        else if (buffer.rfind("team") != std::string::npos && type != nullptr)
        {
//            LOG_DEBUG(buffer.substr(buffer.rfind("=") + 1));
            std::string player = buffer.substr(buffer.rfind("=") + 1);
            if (player == "PLAYER")
                type->attr.team = Team::PLAYER;
            else if (player == "COMPUTER")
                type->attr.team = Team::COMPUTER;
        }
    }

    return true;
}

void ObjectTypeManager::show()
{
    for (auto type : m_objectTypes)
    {
        LOG_DEBUG("");
        LOG_DEBUG("ID: " << type.second->id);
        LOG_DEBUG("SCALE: " << type.second->attr.scale);
        LOG_DEBUG("ANGLE: " << type.second->attr.angle);
        LOG_DEBUG("TEXTURE: " << type.second->attr.texture);
        LOG_DEBUG("MISSILE: " << type.second->attr.missile);
        LOG_DEBUG("DAMAGE: " << type.second->attr.damage);
    }
}

ObjectTypeManager::ObjectTypeManager()
{

}
