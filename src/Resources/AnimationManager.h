#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include "../Renderers/Animation.h"

class AnimationManager
{
public:

    static AnimationManager* instance();

    Animation* load(const char* animationPath);

private:
    AnimationManager();

    ~AnimationManager();
    std::map<std::string, Animation*> m_animations;
};

#endif // ANIMATIONMANAGER_H
