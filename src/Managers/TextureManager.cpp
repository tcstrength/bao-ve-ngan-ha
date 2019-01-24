#include "TextureManager.h"

TextureManager* TextureManager::instance()
{
    static TextureManager tm;
    return &tm;
}

sf::Texture& TextureManager::get(const char* fileName)
{
    std::string strPath = std::string("textures/") + fileName;
    const char* cstPath = strPath.c_str();

//    LOG_DEBUG(cstPath);

    auto it = m_textureMap.find(cstPath);

    if (it == m_textureMap.end())
    {
        sf::Texture texture;
        texture.loadFromFile(cstPath);
        m_textureMap[cstPath] = texture;
    }

    return m_textureMap[cstPath];
}

TextureManager::TextureManager()
{
    LOG_DEBUG("TextureManager loading...");
}
