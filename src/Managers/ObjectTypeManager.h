#ifndef OBJECTTYPEMANAGER_H
#define OBJECTTYPEMANAGER_H

#include "../Utils/Indexer.h"
#include "../Objects/ObjectType.h"
class ObjectTypeManager
{
public:
    static
    ObjectTypeManager* instance();

    void add(ObjectType* objectType);

    ObjectType& make(uint id);

    ObjectType& get(uint id);

    bool load(const char* fileName);

    void show();
private:
    ObjectTypeManager();

    std::map<uint, ObjectType*> m_objectTypes;
};

#endif // OBJECTTYPEMANAGER_H
