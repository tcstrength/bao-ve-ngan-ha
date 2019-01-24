#ifndef GROUP_H
#define GROUP_H

#include "GameObject.h"
#include <cmath>

class Group
{
public:
    Group();

    ~Group();

    void tick();

    void render();

    uint add(GameObject* object);

    void remove(uint index);

    Group* pick(sf::Vector2f center, double radius);

    GameObject* last();

    GameObject* player();

    bool hasObject(uint index);

    void clear();

    void destroyObjects();

    std::map<uint, GameObject *> getObjects() const;

private:
    Indexer m_indexer;
    std::map<uint, GameObject*> m_objects;
    GameObject* m_last;
};

#endif // GROUP_H
