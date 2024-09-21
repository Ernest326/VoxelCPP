#pragma once
#include <glad/glad.h>

class IndexBuffer {

private:
    GLuint m_bufferID;
    GLuint m_count;

public:
    IndexBuffer(GLint *data, GLsizei count);

    void bind() const;
    void unbind() const;

    inline GLsizei getCount() const { return m_count; }

};