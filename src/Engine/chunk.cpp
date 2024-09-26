#include "chunk.hpp"

Chunk::Chunk(int x, int y) {

    this->x = x;
    this->y = y;

    m_voxels = new Voxel **[CHUNK_SIZE];

    for (int i = 0; i < CHUNK_SIZE; i++) {
        m_voxels[i] = new Voxel *[CHUNK_SIZE];
        for (int j = 0; j < CHUNK_SIZE; j++) {
            m_voxels[i][j] = new Voxel[CHUNK_SIZE];
        }
    }

    m_chunkVAO = GenerateBuffer();

}

Chunk::~Chunk() {

    for (int i = 0; i < CHUNK_SIZE; ++i) {
        for (int j = 0; j < CHUNK_SIZE; ++j) {
            delete[] m_voxels[i][j];
        }
        delete[] m_voxels[i];
    }
    delete[] m_voxels;

}

void Chunk::DrawChunk() {

    m_chunkVAO.bind();
    glDrawArrays(GL_TRIANGLES, 0, m_cubecount*36);
    m_chunkVAO.unbind();
}

VertexArray Chunk::GenerateBuffer() {

    m_cubecount=0;
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z=0; z < CHUNK_SIZE; z++) {
                if(m_voxels[x][y][z].getActive()) {
                    AddCube(x, y, z);
                    m_cubecount++;
                }
            }
        }
    }

    GLfloat* verts = &m_vertexinfo[0];

    VertexArray VAO;
    VAO.addBuffer(new Buffer(verts, sizeof(verts), 3), 0, 5, 0);
    VAO.addBuffer(new Buffer(verts, sizeof(verts), 2), 1, 5, 3);

    m_vertexinfo.clear();
    return VAO;

}

void Chunk::AddCube(int x, int y, int z) {

    int x_off = CHUNK_SIZE*this->x + -CHUNK_SIZE/2+x + 0.5;
    int y_off = CHUNK_SIZE*this->y + -CHUNK_SIZE+y + 0.5;
    int z_off = CHUNK_SIZE*this->z + -CHUNK_SIZE/2+z + 0.5;

    GLfloat verts[] = {
        -0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  0.0f, 0.0f,
		 0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  1.0f, 0.0f,
		 0.5f + x_off,  0.5f + y_off, -0.5f + z_off,  1.0f, 1.0f,
		 0.5f + x_off,  0.5f + y_off, -0.5f + z_off,  1.0f, 1.0f,
		-0.5f + x_off,  0.5f + y_off, -0.5f + z_off,  0.0f, 1.0f,
		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  0.0f, 0.0f,

		-0.5f + x_off, -0.5f + y_off,  0.5f + z_off,  0.0f, 0.0f,
		 0.5f + x_off, -0.5f + y_off,  0.5f + z_off,  1.0f, 0.0f,
		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  1.0f, 1.0f,
		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  1.0f, 1.0f,
		-0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  0.0f, 1.0f,
		-0.5f + x_off, -0.5f + y_off,  0.5f + z_off,  0.0f, 0.0f,

		-0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  1.0f, 0.0f,
		-0.5f + x_off,  0.5f + y_off, -0.5f + z_off,  1.0f, 1.0f,
		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  0.0f, 1.0f,
		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  0.0f, 1.0f,
		-0.5f + x_off, -0.5f + y_off,  0.5f + z_off,  0.0f, 0.0f,
		-0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  1.0f, 0.0f,

		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  1.0f, 0.0f,
		 0.5f + x_off,  0.5f + y_off, -0.5f + z_off,  1.0f, 1.0f,
		 0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  0.0f, 1.0f,
		 0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  0.0f, 1.0f,
		 0.5f + x_off, -0.5f + y_off,  0.5f + z_off,  0.0f, 0.0f,
		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  1.0f, 0.0f,

		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  0.0f, 1.0f,
		 0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  1.0f, 1.0f,
		 0.5f + x_off, -0.5f + y_off,  0.5f + z_off,  1.0f, 0.0f,
		 0.5f + x_off, -0.5f + y_off,  0.5f + z_off,  1.0f, 0.0f,
		-0.5f + x_off, -0.5f + y_off,  0.5f + z_off,  0.0f, 0.0f,
		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off,  0.0f, 1.0f,

		-0.5f + x_off,  0.5f + y_off, -0.5f + z_off,  0.0f, 1.0f,
		 0.5f + x_off,  0.5f + y_off, -0.5f + z_off,  1.0f, 1.0f,
		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  1.0f, 0.0f,
		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  1.0f, 0.0f,
		-0.5f + x_off,  0.5f + y_off,  0.5f + z_off,  0.0f, 0.0f,
		-0.5f + x_off,  0.5f + y_off, -0.5f + z_off,  0.0f, 1.0f
    };

    for(int i=0; i<sizeof(verts); i++) {
        m_vertexinfo.push_back(verts[i]);
    }

}