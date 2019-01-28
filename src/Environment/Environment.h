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

    bool del(uint id);

    EnvironmentObject* get(uint id);

    EnvironmentObject* overlap(EnvironmentObject* obj);

    void tick();

    void render();

    Context& getContext();
private:
    Context& m_context;
    Indexer m_index;
    std::map<uint,EnvironmentObject*> m_objects;
};

#endif // ENVIRONMENT_H
