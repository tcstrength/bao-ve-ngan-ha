#ifndef ANIMATION_H
#define ANIMATION_H

#include "Mesh.h"
#include "../Resources/TextureManager.h"
#include "../Utils/glfwClock.h"
#include "../Utils/Indexer.h"
#include "../Parsers/Parser.h"

class Animation : public NonCopyable
{
public:
    struct ChildAnimation
    {
        std::string name;
        std::vector<Mesh*> frames;
        float delay;
    };

    struct UserData
    {
        uint animIndex = 0;
        uint currentFrame = 0;
        glfwClock clock;
    };

    Animation(const char* animationPath);

    ~Animation();

    void run(UserData& userData);

    void draw(const UserData& userData);

    void enable(bool enabled = true);

    glm::vec2 getFrameSize();

    uint getAnimIndexByName(const std::string& name);

private:

    void setupAnim(Parser& parser);

    void setupFrames(ChildAnimation& frames, std::string name, uint row, float delay, uint numFrames);

    std::vector<Vertex> crop(glm::vec2 imageSize, glm::vec4 rect);

    Texture*            m_texture;
    glm::vec2           m_table;
    std::vector<ChildAnimation>
                        m_animations;
    bool                m_enabled;
};

#endif // ANIMATION_H
