#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Config.h"
#include "../Utils/Misc.h"

class Transformer
{
public:
    Transformer(Config& config);

    void update(const float& width, const float& height);

    const glm::mat4& transform(const glm::vec2& position,
                               const glm::vec2& size,
                               const float& rad);

private:
    glm::mat4 m_projection;
};

#endif // TRANSFORMER_H
