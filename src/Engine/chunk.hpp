#pragma once

#include <glad/glad.h>
#include "buffers/buffers.hpp"
#include "shader.hpp"
#include "voxel.hpp"
#include "camera.hpp"

class Chunk {

private:
    int x, y, z;
    const unsigned short CHUNK_SIZE = 16;
    VertexArray m_chunkVAO;
    std::vector<GLfloat> m_vertexinfo;
    Voxel * * * m_voxels;

    int m_cubecount = 0;

public:
    Chunk(int x=0, int y=0);
    ~Chunk();
    void DrawChunk();
private:
    void AddCube(int x, int y, int z);
    VertexArray GenerateBuffer();

};