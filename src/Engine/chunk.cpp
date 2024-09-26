#include "chunk.hpp"

Chunk::Chunk(int x, int y, int z) {

    this->x = x;
    this->y = y;
    this->z = z;

    m_voxels = new Voxel **[CHUNK_SIZE];

    for (int i = 0; i < CHUNK_SIZE; i++) {
        m_voxels[i] = new Voxel *[CHUNK_SIZE];
        for (int j = 0; j < CHUNK_SIZE; j++) {
            m_voxels[i][j] = new Voxel[CHUNK_SIZE];
        }
    }

    this->m_chunkVAO = GenerateBuffer();

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

    this->m_chunkVAO.bind();
    glDrawArrays(GL_TRIANGLES, 0, m_cubecount*36);
    this->m_chunkVAO.unbind();
}

VertexArray Chunk::GenerateBuffer() {

    m_cubecount=0;
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                if(m_voxels[x][y][z].getActive()) {
                    AddCube(x, y, z);
                    m_cubecount++;
                }
            }
        }
    }

    VertexArray VAO;
    VAO.addBuffer(new Buffer(&m_vertexinfo[0], m_vertexinfo.size()*sizeof(GLfloat), 3), 0, 5, 0);
    VAO.addBuffer(new Buffer(&m_vertexinfo[0], m_vertexinfo.size()*sizeof(GLfloat), 2), 1, 5, 3);

    m_vertexinfo.clear();
    return VAO;

}

void Chunk::AddCube(int x, int y, int z) {

    float x_off = x + CHUNK_SIZE*this->x + (float)(-CHUNK_SIZE)/2 + 0.5f;
    float y_off = y + CHUNK_SIZE*this->y + (float)(-CHUNK_SIZE)   + 0.5f;
    float z_off = z + CHUNK_SIZE*this->z + (float)(-CHUNK_SIZE)/2 + 0.5f;

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

    for(int i=0; i<sizeof(verts)/sizeof(GLfloat); i++) {
        m_vertexinfo.push_back(verts[i]);
    }

}