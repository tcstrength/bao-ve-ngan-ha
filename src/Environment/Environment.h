#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "../Context.h"
#include "EnvironmentObject.h"

class Environment
{
public:
    Environment(Context& context);

    ~Environment();

    uint add(EnvironmentObject* obj);

    uint mslAdd(EnvironmentObject* obj);

    bool del(uint id);

    bool mslDel(uint id);

    EnvironmentObject* get(uint id);

    EnvironmentObject* overlap(EnvironmentObject* obj);

    EnvironmentObject* last();

    void tick();

    void render();

    Context& getContext();

    Camera& getCamera();

    std::list<EnvironmentObject*> pick(sf::Vector2f center, int radius);

    std::map<uint, EnvironmentObject *> getObjects() const;

private:
    Context& m_context;
    Indexer m_index;
    std::map<uint,EnvironmentObject*> m_objects;
    std::map<uint,EnvironmentObject*> m_missiles;
    EnvironmentObject* m_lastObject;
};

#endif // ENVIRONMENT_H
