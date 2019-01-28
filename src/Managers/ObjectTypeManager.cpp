#include "ObjectTypeManager.h"


ObjectTypeManager *ObjectTypeManager::instance()
{
    static ObjectTypeManager mng;
    return &mng;
}

Attributes &ObjectTypeManager::make(uint id)
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

Attributes & ObjectTypeManager::get(uint id)
{
    auto it = m_objectTypes.find(id);
    return it->second->attr;
}

bool ObjectTypeManager::load(const char * fileName)
{
    std::string realPath("types/");
    realPath += fileName;
    OBJTParser parser;
    parser.load(realPath.c_str());

    auto indices = parser.getIndices();

    for (auto id : indices)
    {
        Attributes attr = make(id);

        attr.team = parser.loadTeam(id, "team");
        attr.texture = parser.loadString(id, "texture");
        attr.color = parser.loadColor(id, "color");
        attr.scale = parser.loadFloat(id, "scale");
        attr.angle = parser.loadFloat(id, "angle");
        attr.speed = parser.loadInt(id, "speed");
        attr.damage = parser.loadInt(id, "damage");
        attr.dmgType = parser.loadDamageType(id, "damageType");
        attr.attackSpeed = parser.loadFloat(id, "attackSpeed");
        attr.autoAttack = parser.loadInt(id, "autoAttack");
        attr.hitpoints = parser.loadInt(id, "hitpoints");
        attr.maxHitpoints = attr.hitpoints;
        attr.decay = parser.loadFloat(id, "decay");
        attr.missile = parser.loadString(id, "missile");
        attr.missileCount = parser.loadInt(id, "missileCount");
        attr.missileSpeed = parser.loadInt(id, "missileSpeed");
        attr.showHP = parser.loadInt(id, "showHP");

        get(id) = attr;
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

ObjectTypeManager::~ObjectTypeManager()
{
    for (auto objT : m_objectTypes)
        delete objT.second;
}
