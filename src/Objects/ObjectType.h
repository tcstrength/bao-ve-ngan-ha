#ifndef OBJECTTYPE_H
#define OBJECTTYPE_H

#include "../Managers/TextureManager.h"
#include "Attributes.h"

struct ObjectType
{
    ObjectType(uint _id);

    uint         id;
    Attributes   attr;
};

#endif // OBJECTTYPE_H
