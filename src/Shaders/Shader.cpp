#include "Shader.h"

Shader::Shader()
{

}

Shader::~Shader()
{
    glDeleteShader(m_vertexShader);
    glDeleteShader(m_fragmentShader);
    glDeleteProgram(m_shaderProgram);
}

void Shader::load(const char * vs, const char * fs)
{
    m_vertexShader = compileShader(vs, GL_VERTEX_SHADER);
    m_fragmentShader = compileShader(fs, GL_FRAGMENT_SHADER);

    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, m_vertexShader);
    glAttachShader(m_shaderProgram, m_fragmentShader);
    glLinkProgram(m_shaderProgram);

    int success = 0;
    char infoLog[512];

    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(m_shaderProgram, 512, nullptr, infoLog);
        LOG_ERROR("Link Program: " << infoLog);
    }
}

void Shader::bind()
{
    glUseProgram(m_shaderProgram);
}

GLuint Shader::getUniform(const char * uniformName)
{
    return glGetUniformLocation(m_shaderProgram, uniformName);
}

GLuint Shader::compileShader(const char * path, GLuint type)
{
    GLuint shader = glCreateShader(type);
    std::string code;
    std::ifstream shfile(path);
    std::stringstream shstream(code);

    if (shfile.is_open() == false)
    {
        LOG_ERROR("File not found: " << path);
    }

    shstream << shfile.rdbuf();
    code = shstream.str();
    shfile.close();

    const GLchar* shaderCode = code.c_str();

    glShaderSource(shader, 1, &shaderCode, nullptr);
    glCompileShader(shader);

    int success = 0;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        LOG_ERROR("Compile Shader: " << std::string(infoLog));
    }

    return shader;
}
