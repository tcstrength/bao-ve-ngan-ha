#include "GameEngine.h"

GameEngine::GameEngine(const Config& config)
:   m_context(config)
,   m_config(config)
,   m_env(m_context)
{
    m_fpsText.setFont(m_context.font);
    m_fpsText.setFillColor(sf::Color::Yellow);
    m_fpsText.setCharacterSize(24);
    m_fpsText.setPosition(sf::Vector2f(m_config.width - 40, 10));
}

GameEngine::~GameEngine()
{
}

void GameEngine::init()
{
    auto mng = ObjectTypeManager::instance();

    mng->load("hero.objt");
    mng->load("greencraft.objt");
    mng->load("greencraft_large.objt");

    new Hero(m_env);

    for (uint i = 0; i < 1000; ++i)
    {
        sf::Vector2f pos;
        sf::Color color;
        pos.x = randBetween(-10000, 10000);
        pos.y = randBetween(-10000, 10000);

        color.r = rand() % 255;
        color.g = rand() % 255;
        color.b = rand() % 255;

        new SpecialEffect(m_env, "glow.png", pos, color, randf());
    }

    for (uint i = 0; i < 200; ++i)
    {
        new BasicCraft(m_env);
        m_env.last()->setPosition(sf::Vector2f(randBetween(-5000, 5000), randBetween(-5000, 5000)));
    }

    for (uint i = 0; i < 50; ++i)
    {
        new BasicCraft(m_env, 2);
        m_env.last()->setPosition(sf::Vector2f(randBetween(-5000, 5000), randBetween(-5000, 5000)));
    }
}

int GameEngine::run()
{
    sf::Clock counter;

    while (m_context.window.isOpen())
    {
        counter.restart();
        handleEvents();
        tick();
        render();
        m_fpsText.setString(std::to_string(1000000 / counter.getElapsedTime().asMicroseconds()));
    }

    return 0;
}

void GameEngine::render()
{
    m_context.window.clear();

    m_env.render();

    m_context.window.draw(m_fpsText);
    m_context.window.display();
}

void GameEngine::tick()
{
    m_env.tick();
    m_context.camera.tick();
}


void GameEngine::handleEvents()
{
    sf::Event e;

    while (m_context.window.pollEvent(e))
    {
        switch(e.type)
        {
            case sf::Event::Closed:
                m_context.window.close();
                break;

            case sf::Event::KeyPressed:
                if (e.key.code == sf::Keyboard::Escape)
                {
                    m_context.window.close();
                }

                break;

            default:
                break;
        }
    }
}
