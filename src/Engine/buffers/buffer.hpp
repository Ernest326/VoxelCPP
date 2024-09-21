#pragma once
#include <glad/glad.h>

class Buffer {

private:
    GLuint m_bufferID;
    GLuint m_componentCount;

public:
    Buffer(GLfloat *data, GLsizei count, GLuint componentCount);

    void bind() const;
    void unbind() const;

    inline GLsizei getComponentCount() const { return m_componentCount; }

};