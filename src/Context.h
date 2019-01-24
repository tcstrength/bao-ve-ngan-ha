#ifndef CONTEXT_H
#define CONTEXT_H

#include "Managers/TextureManager.h"
#include "Managers/ObjectTypeManager.h"
#include "Config.h"

class Context
{
public:
    Context(const Config& config);

    sf::RenderWindow window;
    sf::Font         font;
};

#endif // CONTEXT_H
