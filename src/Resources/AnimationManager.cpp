#include "AnimationManager.h"

AnimationManager*AnimationManager::instance()
{
    static AnimationManager mng;
    return &mng;
}

Animation* AnimationManager::load(const char* fileName)
{
    auto it = m_animations.find(fileName);

    if (it == m_animations.end())
    {
        m_animations[fileName] = new Animation(fileName);
    }

    return m_animations[fileName];
}

AnimationManager::AnimationManager()
{
    LOG_DEBUG("Open AnimationManager");
}

AnimationManager::~AnimationManager()
{
    for (auto it = m_animations.begin(); it != m_animations.end(); ++it)
    {
        delete it->second;
    }

    m_animations.clear();

    LOG_DEBUG("Close AnimationManager");
}
