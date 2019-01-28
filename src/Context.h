#ifndef CONTEXT_H
#define CONTEXT_H

#include "Managers/TextureManager.h"
#include "Managers/ObjectTypeManager.h"
#include "Entities/Camera.h"
#include "Config.h"

class Context
{
public:
    Context(const Config& cfg);

    const Config&    config;
    sf::RenderWindow window;
    sf::Font         font;
    Camera           camera;
};

#endif // CONTEXT_H
