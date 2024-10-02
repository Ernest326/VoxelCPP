#pragma once

#include <glad/glad.h>
#include "buffers/buffers.hpp"
#include "shader.hpp"
#include "voxel.hpp"
#include "camera.hpp"

class Chunk {

private:
    int x, y, z;
    const int CHUNK_SIZE = 16;
    VertexArray m_chunkVAO;
    std::vector<GLfloat> m_vertexinfo;
    Voxel * * * m_voxels;

public:
    bool isDirty=false;
    Chunk(int x=0, int y=0, int z=0);
    ~Chunk();
    void DrawChunk();
    glm::vec3 getPosition() { return glm::vec3(this->x, this->y, this->z); }
private:
    void AddCube(int x, int y, int z, Voxel::BLOCKTYPE block);
    VertexArray GenerateBuffer();
};