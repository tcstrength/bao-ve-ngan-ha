#include "Mesh.h"

Mesh::Mesh()
:   m_VAO(0xFFFFFFFF)
,   m_VBO(0xFFFFFFFF)
,   m_IBO(0xFFFFFFFF)
{

}

Mesh::~Mesh()
{
    clear();
}

void Mesh::load(std::vector<Vertex> vertices, std::vector<GLuint> indices)
{
    clear();
    m_numIndices = indices.size();

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_IBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * m_numIndices, &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));

    glBindVertexArray(0);
}

void Mesh::clear()
{
    if (m_VAO != 0xFFFFFFFF)
    {
        glDeleteBuffers(1, &m_VBO);
        glDeleteBuffers(1, &m_IBO);
        glDeleteVertexArrays(1, &m_VAO);
        LOG_DEBUG("Mesh " << this << " has been cleared");
    }
}

void Mesh::update()
{

}

void Mesh::draw()
{
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_numIndices, GL_UNSIGNED_INT, nullptr);
}
