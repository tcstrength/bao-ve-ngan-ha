#ifndef TEXTURE_H
#define TEXTURE_H

#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "../Utils/Log.h"

class Texture
{
public:
    //////////////////////////////////////////////
    /// \brief Texture
    /// \param path real path is "textures/<path>"
    /// \param linear
    ///
    Texture(const char* path, bool linear = false);

    ~Texture();

    void bind();

    int getWidth() const;

    int getHeight() const;

    glm::vec2 getSize() const;

private:
    GLuint m_TO;
    int    m_width;
    int    m_height;
};

#endif // TEXTURE_H
