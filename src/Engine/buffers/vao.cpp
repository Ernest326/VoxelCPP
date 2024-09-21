#include "vao.hpp"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_ArrayID);
}

VertexArray::~VertexArray() {
    for(int i=0; i<m_Buffers.size(); i++) {
        delete m_Buffers[i];
    }
}

void VertexArray::addBuffer(Buffer* buffer, GLuint index, GLsizei stride, int offset) {
    bind();
    buffer->bind();
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, stride*sizeof(float), (void*)(offset*sizeof(float)));
    buffer->unbind();
    unbind();
}

void VertexArray::addBuffer(Buffer* buffer, GLuint index) {
    bind();
    buffer->bind();
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
    buffer->unbind();
    unbind();
}

void VertexArray::bind() const {
    glBindVertexArray(m_ArrayID);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}