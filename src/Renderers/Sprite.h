#ifndef SPRITE_H
#define SPRITE_H

#include "Mesh.h"
#include "../Context.h"
#include "../Resources/AnimationManager.h"

class Sprite : public Drawable
{
public:
    Sprite(Context& context, const char* animPath);

    void update();

    void draw();

    glm::vec2 getGlobalSize() const;

    glm::vec2 getLocalSize() const;

    glm::vec2 getPosition() const;

    void setPosition(const glm::vec2& position);

    float getScale() const;

    void setScale(float scale);

    float getRadian() const;

    void setRadian(float radian);

    void setAnim(std::string animName);

    void setAnim(uint index);

    glm::vec4 getColor() const;

    void setColor(const glm::vec4& color);

private:
    Context&   m_context;
    Animation* m_anim;
    Animation::UserData
               m_animData;
    glm::mat4  m_matrix;
    glm::vec2  m_position;
    glm::vec4  m_color;
    float      m_scale;
    float      m_radian;

};

#endif // SPRITE_H
