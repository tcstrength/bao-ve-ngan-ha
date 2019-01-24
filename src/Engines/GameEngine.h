#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../Config.h"
#include "../Context.h"
#include "../Managers/TextureManager.h"
#include "../Managers/ObjectTypeManager.h"
#include "../Objects/Group.h"
#include "../Objects/Object.h"

class GameEngine
{
public:
    GameEngine(const Config& config);

    ~GameEngine();

    void init();

    int  run();
private:
    void handleEvents();

    void update();

    void render();

    Context m_context;
    const Config& m_config;
    Group m_group;
    sf::Text m_fpsText;
};

#endif // GAMEENGINE_H
