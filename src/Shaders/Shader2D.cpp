#include "Shader2D.h"

Shader2D::Shader2D()
{
}

void Shader2D::load()
{
    Shader::load("shaders/shader.vs", "shaders/shader.fs");
    m_modelProjectionUniform = getUniform("modelProjection");
    m_colorUniform = getUniform("color0");
}

void Shader2D::loadTo(const glm::mat4 & modelProjection, const glm::vec4& color)
{
    glUniformMatrix4fv(m_modelProjectionUniform, 1, GL_FALSE, glm::value_ptr(modelProjection));
    glUniform4f(m_colorUniform, color.x, color.y, color.z, color.w);

}
