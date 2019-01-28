#include "Context.h"

Context::Context(const Config& cfg)
:   config(cfg)
,   camera(cfg)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    if (config.fullscreen)
    {
        window.create(sf::VideoMode::getDesktopMode(), config.title, sf::Style::Default, settings);
    }
    else
    {
        window.create(sf::VideoMode(config.width, config.height), config.title, sf::Style::Default, settings);
    }

    if (config.frameRate != 0)
    {
        window.setFramerateLimit(config.frameRate);
    }

    window.setVerticalSyncEnabled(config.vsync);
    font.loadFromFile("fonts/SFPro.otf");
}
