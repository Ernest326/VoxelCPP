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
    glDrawArrays(GL_TRIANGLES, 0, (m_vertexinfo.size()/5));
    this->m_chunkVAO.unbind();
}

VertexArray Chunk::GenerateBuffer() {

    m_vertexinfo.clear();
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                if(m_voxels[x][y][z].getActive()) {
                    AddCube(x, y, z, m_voxels[x][y][z].getBlockType());
                }
            }
        }
    }

    VertexArray VAO;
    VAO.addBuffer(new Buffer(&m_vertexinfo[0], m_vertexinfo.size()*sizeof(GLfloat), 3), 0, 8, 0);
    VAO.addBuffer(new Buffer(&m_vertexinfo[0], m_vertexinfo.size()*sizeof(GLfloat), 3), 1, 8, 3);
    VAO.addBuffer(new Buffer(&m_vertexinfo[0], m_vertexinfo.size()*sizeof(GLfloat), 2), 2, 8, 6);

    return VAO;

}

void Chunk::AddCube(int x, int y, int z, Voxel::BLOCKTYPE block) {

    float x_off = x + CHUNK_SIZE*this->x + (float)(-CHUNK_SIZE)/2 + 0.5f;
    float y_off = y + CHUNK_SIZE*this->y + (float)(-CHUNK_SIZE)   + 0.5f;
    float z_off = z + CHUNK_SIZE*this->z + (float)(-CHUNK_SIZE)/2 + 0.5f;

    x_off += this->x;
    z_off += this->z;


    float tex_size = (1.0/4.0);
    float tex_x = tex_size*block;

    GLfloat back_verts[] = {
        //BACK FACE
        -0.5f + x_off, -0.5f + y_off, -0.5f + z_off, 0.0f, 0.0f, -1.0f, tex_x, 0.0f,
		 0.5f + x_off, -0.5f + y_off, -0.5f + z_off, 0.0f, 0.0f, -1.0f, tex_x+tex_size, 0.0f,
		 0.5f + x_off,  0.5f + y_off, -0.5f + z_off, 0.0f, 0.0f, -1.0f, tex_x+tex_size, 1.0f,
		 0.5f + x_off,  0.5f + y_off, -0.5f + z_off, 0.0f, 0.0f, -1.0f, tex_x+tex_size, 1.0f,
		-0.5f + x_off,  0.5f + y_off, -0.5f + z_off, 0.0f, 0.0f, -1.0f, tex_x, 1.0f,
		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off, 0.0f, 0.0f, -1.0f, tex_x, 0.0f,
    };

    GLfloat front_verts[] = {
        //FRONT FACE
		-0.5f + x_off, -0.5f + y_off, 0.5f + z_off, 0.0f, 0.0f, 1.0f, tex_x, 0.0f,
		 0.5f + x_off, -0.5f + y_off, 0.5f + z_off, 0.0f, 0.0f, 1.0f, tex_x+tex_size, 0.0f,
		 0.5f + x_off,  0.5f + y_off, 0.5f + z_off, 0.0f, 0.0f, 1.0f, tex_x+tex_size, 1.0f,
		 0.5f + x_off,  0.5f + y_off, 0.5f + z_off, 0.0f, 0.0f, 1.0f, tex_x+tex_size, 1.0f,
		-0.5f + x_off,  0.5f + y_off, 0.5f + z_off, 0.0f, 0.0f, 1.0f, tex_x, 1.0f,
		-0.5f + x_off, -0.5f + y_off, 0.5f + z_off, 0.0f, 0.0f, 1.0f, tex_x, 0.0f,
    };

    GLfloat left_verts[] = {
        //LEFT FACE
		-0.5f + x_off,  0.5f + y_off,  0.5f + z_off, -1.0f, 0.0f, 0.0f, tex_x+tex_size, 0.0f,
		-0.5f + x_off,  0.5f + y_off, -0.5f + z_off, -1.0f, 0.0f, 0.0f, tex_x+tex_size, 1.0f,
		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off, -1.0f, 0.0f, 0.0f, tex_x, 1.0f,
		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off, -1.0f, 0.0f, 0.0f, tex_x, 1.0f,
		-0.5f + x_off, -0.5f + y_off,  0.5f + z_off, -1.0f, 0.0f, 0.0f, tex_x, 0.0f,
		-0.5f + x_off,  0.5f + y_off,  0.5f + z_off, -1.0f, 0.0f, 0.0f, tex_x+tex_size, 0.0f,
    };

    GLfloat right_verts[] = {
        //RIGHT FACE
		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off, 1.0f, 0.0f, 0.0f, tex_x+tex_size, 0.0f,
		 0.5f + x_off,  0.5f + y_off, -0.5f + z_off, 1.0f, 0.0f, 0.0f, tex_x+tex_size, 1.0f,
		 0.5f + x_off, -0.5f + y_off, -0.5f + z_off, 1.0f, 0.0f, 0.0f, tex_x, 1.0f,
		 0.5f + x_off, -0.5f + y_off, -0.5f + z_off, 1.0f, 0.0f, 0.0f, tex_x, 1.0f,
		 0.5f + x_off, -0.5f + y_off,  0.5f + z_off, 1.0f, 0.0f, 0.0f, tex_x, 0.0f,
		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off, 1.0f, 0.0f, 0.0f, tex_x+tex_size, 0.0f,
    };

    GLfloat bottom_verts[] = {
        //BOTTOM FACE
		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off, 0.0f, -1.0f, 0.0f, tex_x, 1.0f,
		 0.5f + x_off, -0.5f + y_off, -0.5f + z_off, 0.0f, -1.0f, 0.0f, tex_x+tex_size, 1.0f,
		 0.5f + x_off, -0.5f + y_off,  0.5f + z_off, 0.0f, -1.0f, 0.0f, tex_x+tex_size, 0.0f,
		 0.5f + x_off, -0.5f + y_off,  0.5f + z_off, 0.0f, -1.0f, 0.0f, tex_x+tex_size, 0.0f,
		-0.5f + x_off, -0.5f + y_off,  0.5f + z_off, 0.0f, -1.0f, 0.0f, tex_x, 0.0f,
		-0.5f + x_off, -0.5f + y_off, -0.5f + z_off, 0.0f, -1.0f, 0.0f, tex_x, 1.0f,
    };

    GLfloat top_verts[] = {
        //TOP FACE
		-0.5f + x_off,  0.5f + y_off, -0.5f + z_off, 0.0f, 1.0f, 0.0f,  tex_x, 1.0f,
		 0.5f + x_off,  0.5f + y_off, -0.5f + z_off, 0.0f, 1.0f, 0.0f,  tex_x+tex_size, 1.0f,
		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off, 0.0f, 1.0f, 0.0f,  tex_x+tex_size, 0.0f,
		 0.5f + x_off,  0.5f + y_off,  0.5f + z_off, 0.0f, 1.0f, 0.0f,  tex_x+tex_size, 0.0f,
		-0.5f + x_off,  0.5f + y_off,  0.5f + z_off, 0.0f, 1.0f, 0.0f,  tex_x, 0.0f,
		-0.5f + x_off,  0.5f + y_off, -0.5f + z_off, 0.0f, 1.0f, 0.0f,  tex_x, 1.0f
    };

    //LEFT Face
    if(x>0&&!m_voxels[x-1][y][z].getActive() || x==0) {
        for(int i=0; i<sizeof(left_verts)/sizeof(GLfloat); i++) {
            m_vertexinfo.push_back(left_verts[i]);
        }
    }

    //RIGHT Face
    if(x<CHUNK_SIZE-1&&!m_voxels[x+1][y][z].getActive() || x==CHUNK_SIZE-1) {
        for(int i=0; i<sizeof(right_verts)/sizeof(GLfloat); i++) {
            m_vertexinfo.push_back(right_verts[i]);
        }
    }

    //BOTTOM Face
    if(y>0&&!m_voxels[x][y-1][z].getActive() || y==0) {
        for(int i=0; i<sizeof(bottom_verts)/sizeof(GLfloat); i++) {
            m_vertexinfo.push_back(bottom_verts[i]);
        }
    }

    //TOP Face
    if(y<CHUNK_SIZE-1&&!m_voxels[x][y+1][z].getActive() || y==CHUNK_SIZE-1) {
        for(int i=0; i<sizeof(top_verts)/sizeof(GLfloat); i++) {
            m_vertexinfo.push_back(top_verts[i]);
        }
    }

    //BACK Face
    if(z>0&&!m_voxels[x][y][z-1].getActive() || z==0) {
        for(int i=0; i<sizeof(back_verts)/sizeof(GLfloat); i++) {
            m_vertexinfo.push_back(back_verts[i]);
        }
    }

    //FRONT Face
    if(z<CHUNK_SIZE-1&&!m_voxels[x][y][z+1].getActive() || z==CHUNK_SIZE-1) {
        for(int i=0; i<sizeof(front_verts)/sizeof(GLfloat); i++) {
            m_vertexinfo.push_back(front_verts[i]);
        }
    }

}