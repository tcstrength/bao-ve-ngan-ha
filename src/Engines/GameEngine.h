#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../Config.h"
#include "../Context.h"
#include "../Managers/TextureManager.h"
#include "../Managers/ObjectTypeManager.h"
#include "../Environment/Environment.h"
#include "../Objects/GameObject.h"
#include "../Objects/Player.h"

class GameEngine
{
public:
    GameEngine(const Config& config);

    ~GameEngine();

    void init();

    int  run();
private:
    void handleEvents();

    void render();

    void tick();

    Context m_context;
    const Config& m_config;
    sf::Text m_fpsText;
    Environment m_env;
};

#endif // GAMEENGINE_H
