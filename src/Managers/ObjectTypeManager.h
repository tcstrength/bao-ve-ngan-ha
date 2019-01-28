#ifndef OBJECTTYPEMANAGER_H
#define OBJECTTYPEMANAGER_H

#include "../Utils/Indexer.h"
#include "../Objects/ObjectType.h"
#include "../Parsers/OBJTParser.h"

class ObjectTypeManager
{
public:
    static
    ObjectTypeManager* instance();

    Attributes& make(uint id);

    Attributes& get(uint id);

    bool load(const char* fileName);

    void show();
private:
    ObjectTypeManager();

    ~ObjectTypeManager();

    void add(ObjectType* objectType);

    std::map<uint, ObjectType*> m_objectTypes;
};

#endif // OBJECTTYPEMANAGER_H
