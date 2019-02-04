#include "Texture.h"

Texture::Texture(const char * path, bool linear)
:   m_width(-1)
,   m_height(-1)
{
    LOG_DEBUG("Load " << path);

    u_char* image = SOIL_load_image(path, &m_width, &m_height, nullptr, SOIL_LOAD_RGBA);

    if (image == nullptr)
    {
        LOG_ERROR("Failed to load " << image);
    }

    glGenTextures(1, &m_TO);
    glBindTexture(GL_TEXTURE_2D, m_TO);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    if (linear)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_TO);
    LOG_DEBUG("Texture " << this << " has been deleted");
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, m_TO);
}

int Texture::getWidth() const
{
    return m_width;
}

int Texture::getHeight() const
{
    return m_height;
}

glm::vec2 Texture::getSize() const
{
    return glm::vec2(m_width, m_height);
}
