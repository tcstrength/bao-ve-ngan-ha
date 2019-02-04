#include "Sprite.h"

Sprite::Sprite(Context& context, const char* animPath)
:   m_context(context)
,   m_anim(AnimationManager::instance()->load(animPath))
,   m_position(glm::vec2(0.f, 0.f))
,   m_color(1.f)
,   m_scale(1.f)
,   m_radian(0.f)
{
    update();
}

void Sprite::update()
{
    m_matrix = m_context.transformer.transform
    (
        m_position,
        m_anim->getFrameSize() * glm::vec2(m_scale),
        m_radian
    );
}

void Sprite::draw()
{
    m_context.shader.loadTo(m_matrix, m_color);
    m_anim->run(m_animData);
    m_anim->draw(m_animData);
}

glm::vec2 Sprite::getGlobalSize() const
{
    return m_anim->getFrameSize() * m_scale;
}

glm::vec2 Sprite::getLocalSize() const
{
    return m_anim->getFrameSize();
}

glm::vec2 Sprite::getPosition() const
{
    return m_position;
}

void Sprite::setPosition(const glm::vec2& position)
{
    m_position = position;
    update();
}

float Sprite::getScale() const
{
    return m_scale;
}

void Sprite::setScale(float scale)
{
    m_scale = scale;
    update();
}

float Sprite::getRadian() const
{
    return m_radian;
}

void Sprite::setRadian(float radian)
{
    m_radian = radian;
    update();
}

void Sprite::setAnim(std::string animName)
{
    setAnim(m_anim->getAnimIndexByName(animName));
}

void Sprite::setAnim(uint index)
{
    m_animData.animIndex = index;
}

glm::vec4 Sprite::getColor() const
{
    return m_color;
}

void Sprite::setColor(const glm::vec4& color)
{
    m_color = color;
}
