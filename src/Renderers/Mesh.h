#ifndef MESH_H
#define MESH_H

#include <vector>
#include <GL/glew.h>
#include "Vertex.h"
#include "Drawable.h"

class Mesh :
public Drawable
{
public:
    Mesh();

    virtual ~Mesh();

    void load(std::vector<Vertex> vertices, std::vector<GLuint> indices);

    void clear();

    void update();

    void draw();

private:
    GLuint m_numIndices;
    GLuint m_VAO;
    GLuint m_VBO;
    GLuint m_IBO;
};

#endif // MESH_H
