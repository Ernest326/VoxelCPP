#pragma once
#include <vector>
#include <glad/glad.h>
#include "buffer.hpp"

class IndexBuffer {

private:
    GLuint m_bufferID;
    GLuint m_count;
    std::vector<Buffer*> m_Buffers;

public:
    IndexBuffer(GLushort *data, GLsizei count);
    ~IndexBuffer();

    void addBuffer(Buffer* buffer, GLuint index, GLsizei stride, int offset);
    void addBuffer(Buffer* buffer, GLuint index);

    void bind() const;
    void unbind() const;

    inline GLsizei getCount() const { return m_count; }

};