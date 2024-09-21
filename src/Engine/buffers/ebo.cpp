#include "ebo.hpp"

IndexBuffer::IndexBuffer(GLushort *data, GLsizei count)
{
    this->m_count = count;

    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer() {
    for(int i=0; i<m_Buffers.size(); i++) {
        delete m_Buffers[i];
    }
}

void IndexBuffer::addBuffer(Buffer* buffer, GLuint index, GLsizei stride, int offset) {
    bind();
    buffer->bind();
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, stride*sizeof(float), (void*)(offset*sizeof(float)));
    buffer->unbind();
    unbind();
}

void IndexBuffer::addBuffer(Buffer* buffer, GLuint index) {
    bind();
    buffer->bind();
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
    buffer->unbind();
    unbind();
}

void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
}

void IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}