#ifndef SHADER2D_H
#define SHADER2D_H

#include "Shader.h"
#include "../Config.h"
#include <glm/gtc/type_ptr.hpp>

class Shader2D : public Shader
{
public:
    Shader2D();

    void load();

    void loadTo(const glm::mat4& modelProjection, const glm::vec4& color);
private:
    glm::mat4 m_projection;
    GLuint m_modelProjectionUniform;
    GLuint m_colorUniform;
};

#endif // SHADER2D_H
