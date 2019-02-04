#include "TextureManager.h"

Texture*TextureManager::load(const char* fileName)
{
    auto it = m_textures.find(fileName);

    if (it == m_textures.end())
    {
        m_textures[fileName] = new Texture(fileName);
    }

    return m_textures[fileName];
}

TextureManager*TextureManager::instance()
{
    static TextureManager mng;
    return &mng;
}

TextureManager::TextureManager()
{
    LOG_DEBUG("Open TextureManager");
}

TextureManager::~TextureManager()
{
    for (auto it = m_textures.begin(); it != m_textures.end(); ++it)
    {
        delete it->second;
    }

    m_textures.clear();

    LOG_DEBUG("Closed TextureManager");
}
