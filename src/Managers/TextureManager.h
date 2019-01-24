#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

#include "../Utils/Log.h"

class TextureManager
{
public:
    static
    TextureManager* instance();

    sf::Texture&    get(const char* fileName = "unknown.png");

private:
    TextureManager();

    std::map<std::string, sf::Texture> m_textureMap;
};
#endif // TEXTUREMANAGER_H
