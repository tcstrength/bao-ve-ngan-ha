#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include "../Utils/Log.h"

class Shader
{
public:
    Shader();

    virtual ~Shader();

    void load(const char* vs, const char* fs);

    void bind();

    GLuint getUniform(const char* uniformName);

private:
    GLuint compileShader(const char* sf, GLuint type);

    GLuint m_shaderProgram;
    GLuint m_vertexShader;
    GLuint m_fragmentShader;
};

#endif // SHADER_H
