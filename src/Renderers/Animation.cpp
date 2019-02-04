#include "Animation.h"

Animation::Animation(const char* path)
{
    std::string dir = "sprites/";
    std::string animPath = dir + path;

    LOG_DEBUG("Load " << animPath);

    Parser parser;
    parser.load(animPath.c_str());

    std::string texturePath = dir + parser.loadString(0, "texture");
    m_enabled = parser.loadInt(0, "animation");
    m_texture = TextureManager::instance()->load(texturePath.c_str());

    m_table.y = parser.loadFloat(0, "rows");
    m_table.x = parser.loadFloat(0, "cols");

    setupAnim(parser);
}

Animation::~Animation()
{
    for (uint i = 0; i < m_animations.size(); ++i)
    {
        for (uint j = 0; j < m_animations[i].frames.size(); ++j)
        {
            delete m_animations[i].frames[j];
        }

        m_animations[i].frames.clear();
    }

    m_animations.clear();
}

void Animation::setupAnim(Parser& parser)
{
    m_animations.resize(static_cast<uint>(m_table.y));

    for (uint i = 1; i <= m_animations.size(); ++i)
    {
        std::string name = parser.loadString(i, "name");
        uint numFrames = static_cast<uint>(parser.loadInt(i, "frames"));
        float delay    = parser.loadFloat(i, "delay");
        uint index     = i - 1;

        setupFrames(m_animations[index], name, index, delay, numFrames);
    }
}

void Animation::setupFrames(ChildAnimation& frames, std::string name, uint row, float delay, uint numFrames)
{
    static std::vector<GLuint> indices =
    {
        0, 1, 2,
        2, 3, 0
    };

    glm::vec2 texSize = m_texture->getSize();
    glm::vec2 size = m_texture->getSize() / m_table;

    frames.name = name;
    frames.frames.resize(numFrames, nullptr);
    frames.delay = delay;

    for (uint col = 0; col < frames.frames.size(); ++col)
    {
        glm::vec2 offset(col * size.x, row * size.y);
        std::vector<Vertex> vertices = crop(texSize, glm::vec4(offset, size));
        frames.frames[col] = new Mesh();
        frames.frames[col]->load(vertices, indices);
    }
}

void Animation::run(UserData& userData)
{
    ChildAnimation& frames = m_animations[userData.animIndex];

    if (m_enabled && userData.clock.getTime() >= frames.delay)
    {
        if (++userData.currentFrame >= frames.frames.size())
        {
            userData.currentFrame = 0;
        }

        if (userData.animIndex >= m_animations.size())
        {
            userData.animIndex = 0;
        }

        userData.clock.restart();
    }
}

void Animation::draw(const UserData& userData)
{
    /// bind texture first
    m_texture->bind();
    ChildAnimation& frames = m_animations[userData.animIndex];
    /// tell the mesh draws itself
    frames.frames[userData.currentFrame]->draw();
}

void Animation::enable(bool enabled)
{
    m_enabled = enabled;
}

glm::vec2 Animation::getFrameSize()
{
    return m_texture->getSize() / m_table;
}

uint Animation::getAnimIndexByName(const std::string& name)
{
    for (uint i = 0; i < m_animations.size(); ++i)
    {
        if (m_animations[i].name == name)
        {
            return i;
        }
    }

    return 0;
}

std::vector<Vertex> Animation::crop(glm::vec2 imageSize, glm::vec4 rect)
{
    glm::vec2 offset   = glm::vec2(rect.x, rect.y) / imageSize;
    glm::vec2 size     = glm::vec2(rect.z, rect.w) / imageSize;
    glm::vec2 topLeft  = glm::vec2(offset.x         , offset.y + size.y);
    glm::vec2 topRight = glm::vec2(offset.x + size.x, offset.y + size.y);
    glm::vec2 botRight = glm::vec2(offset.x + size.x, offset.y);
    glm::vec2 botLeft  = glm::vec2(offset.x         , offset.y);

#define WTF(a) LOG_DEBUG(a.x << ", " << a.y)
    WTF(topLeft);
    WTF(topRight);
    WTF(botRight);
    WTF(botLeft);
#undef WTF

    std::vector<Vertex> vertices =
    {
         Vertex({glm::vec2(-1.0f,  1.0f),   topLeft}),   // top left
         Vertex({glm::vec2( 1.0f,  1.0f),   topRight}),   // top right
         Vertex({glm::vec2( 1.0f, -1.0f),   botRight}),   // bottom right
         Vertex({glm::vec2(-1.0f, -1.0f),   botLeft}),   // bottom left
    };

    return vertices;
}
