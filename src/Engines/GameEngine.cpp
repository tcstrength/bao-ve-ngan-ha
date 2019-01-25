#include "GameEngine.h"

GameEngine::GameEngine(const Config& config)
:   m_context(config)
,   m_config(config)
{
    m_fpsText.setFont(m_context.font);
    m_fpsText.setFillColor(sf::Color::Yellow);
    m_fpsText.setCharacterSize(24);
    m_fpsText.setPosition(sf::Vector2f(m_config.width - 40, 10));
}

GameEngine::~GameEngine()
{
    m_group.destroyObjects();
}

void GameEngine::init()
{
    auto mng = ObjectTypeManager::instance();

    mng->load("hero.objt");
    mng->load("greencraft.objt");
    mng->load("greencraft_boss.objt");
    auto hero = mng->get(0);
    auto greencraft = mng->get(1);
    auto greencraftBoss = mng->get(2);

    m_group.add(new Object(m_context, hero));


    int numGreencraft = 5;
    int greenCraftHeight = 100;
    for (int i = 0; i < numGreencraft; ++i)
    {
        auto spacing = static_cast<float>(m_config.width) / (numGreencraft + 1);
        m_group.add(new Object(m_context, greencraft));
        m_group.last()->setPosition(sf::Vector2f(spacing * (i + 1), greenCraftHeight));
    }

    numGreencraft = 10;
    greenCraftHeight = 200;
    for (int i = 0; i < numGreencraft; ++i)
    {
        auto spacing = static_cast<float>(m_config.width) / (numGreencraft + 1);
        m_group.add(new Object(m_context, greencraft));
        m_group.last()->setPosition(sf::Vector2f(spacing * (i + 1), greenCraftHeight));
    }

    numGreencraft = 5;
    greenCraftHeight = 300;
    for (int i = 0; i < numGreencraft; ++i)
    {
        auto spacing = static_cast<float>(m_config.width) / (numGreencraft + 1);
        m_group.add(new Object(m_context, greencraft));
        m_group.last()->setPosition(sf::Vector2f(spacing * (i + 1), greenCraftHeight));
    }

    numGreencraft = 10;
    greenCraftHeight = 400;
    for (int i = 0; i < numGreencraft; ++i)
    {
        auto spacing = static_cast<float>(m_config.width) / (numGreencraft + 1);
        m_group.add(new Object(m_context, greencraft));
        m_group.last()->setPosition(sf::Vector2f(spacing * (i + 1), greenCraftHeight));
    }

    m_group.add(new Object(m_context, greencraftBoss));
    m_group.last()->setPosition(sf::Vector2f(m_config.width / 2, m_config.height / 2));

    mng->show();
}

int GameEngine::run()
{
    sf::Clock counter;

    while (m_context.window.isOpen())
    {
        counter.restart();
        handleEvents();
        update();
        render();
        m_fpsText.setString(std::to_string(1000000 / counter.getElapsedTime().asMicroseconds()));
    }

    return 0;
}

void GameEngine::render()
{
    m_context.window.clear();
    m_group.render();
    m_context.window.draw(m_fpsText);
    m_context.window.display();
}

void GameEngine::update()
{
    m_group.tick();
    m_group.player()->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_context.window)));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        static_cast<Object*>(m_group.player())->attack(m_group);
    }

    for (auto obj : m_group.getObjects())
    {
        if (obj.second->getAttr().player != Player::PLAYER)
            static_cast<Object*>(obj.second)->attack(m_group);
    }
//    static_cast<Object*>(m_group.player())->center();
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
                switch (e.key.code)
                {
                    case sf::Keyboard::Escape:
                        m_context.window.close();
                        break;

                    case sf::Keyboard::Space:
                        static_cast<Object*>(m_group.player())->getAttr().hitpoints += 100;
                        static_cast<Object*>(m_group.player())->getAttr().damage += 100;
                        static_cast<Object*>(m_group.player())->getAttr().attackSpeed -= 0.1f;
                        break;
                }
                break;

//            case sf::Event::MouseButtonPressed:
//                static_cast<Object*>(m_group.player())->attack(m_group);
//                break;

            default:
                break;
        }
    }
}
