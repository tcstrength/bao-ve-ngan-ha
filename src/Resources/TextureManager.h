#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "../Renderers/Texture.h"
#include <map>

class TextureManager
{
public:
    Texture* load(const char* fileName);

    static TextureManager* instance();
private:
    std::map<std::string, Texture*> m_textures;

    TextureManager();

    ~TextureManager();
};

#endif // TEXTUREMANAGER_H
