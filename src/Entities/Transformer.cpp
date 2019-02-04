#include "Transformer.h"

Transformer::Transformer(Config& config)
{
    update(config.width, config.height);
}

void Transformer::update(const float& width, const float& height)
{
    m_projection = glm::ortho(-width / 2, width / 2,
                              height / 2, -height / 2,
                              -1.0f, 1.0f);
}

const glm::mat4& Transformer::transform(const glm::vec2& position, const glm::vec2 &size, const float &rad)
{
    static glm::mat4 Imatrix(1.f);
    static glm::mat4 model;

    model = glm::translate(Imatrix, glm::vec3(position, 0.0f));
    model = glm::rotate(model, rad - Misc::deg2Rad(90.f), glm::vec3(0.f, 0.f, 1.f));
    model = glm::scale(model, glm::vec3(size, 1.f));
    model = m_projection * model;

    return model;
}
