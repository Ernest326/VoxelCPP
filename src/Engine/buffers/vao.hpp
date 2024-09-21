#pragma once
#include <vector>
#include <glad/glad.h>
#include "buffer.hpp"
#include "ebo.hpp"

class VertexArray {

private:
    GLuint m_ArrayID;
    std::vector<Buffer*> m_Buffers;

public:
    VertexArray();
    ~VertexArray();

    void addBuffer(Buffer* buffer, GLuint index, GLsizei stride, int offset);
    void addBuffer(Buffer* buffer, GLuint index);

    void bind() const;
    void unbind() const;

};