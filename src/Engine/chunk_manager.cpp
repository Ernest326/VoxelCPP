#include "chunk_manager.hpp"

ChunkManager::ChunkManager() {
    //CAUSE CRASH!!
    //chunks.emplace(std::make_tuple(0, 0, 1), std::move(Chunk(0,0,1)));
    chunks.insert({std::make_tuple(0, 0, 1), Chunk(0,0,1)});
}

ChunkManager::~ChunkManager() {

}

glm::vec3 ChunkManager::getNearestChunkPos(glm::vec3 real_pos) {

    int x = round(real_pos.x/16);
    int y = round((real_pos.y-8)/16);
    int z = round(real_pos.z/16);

    return glm::vec3(x, y, z);
}

void ChunkManager::setupChunks() {
    
    int last = MAX_LOAD;
    if(m_setupQueue.size()<last) {
        last=m_setupQueue.size()-1;
    }

    for(int i=0; i<last; i++) {
        m_setupQueue[m_setupQueue.size()-1]->setup();
        m_setupQueue.pop_back();
    }
}


void ChunkManager::loadNewChunks(glm::vec3 position) {

    glm::vec3 pos = getNearestChunkPos(position);

    for(int x=-LOAD_DISTANCE; x<=LOAD_DISTANCE; ++x) {
        for(int y=-LOAD_DISTANCE; y<=LOAD_DISTANCE; ++y) {
            for(int z=-LOAD_DISTANCE; z<=LOAD_DISTANCE; ++z) {

                std::tuple chunk_pos = {pos.x+x,pos.y+y,pos.z+z};

                if(!chunks.count(chunk_pos)) {
                    //chunks.emplace(chunk_pos, Chunk(x,y,z));
                    //m_setupQueue.push_back(&chunks.at(chunk_pos));
                } else {
                    std::cout << pos.x+x << " , " << pos.y+y << pos.z+z << std::endl;
                }
            }
        }
    }
}

void ChunkManager::updateChunks() {
    for (auto& [key, chunk]: chunks) { 
        if (chunk.isDirty) {
            chunk.isDirty=false;
            m_setupQueue.push_back(&chunk);
        }
    }
}

void ChunkManager::unloadChunks(glm::vec3 position) {

    glm::vec3 pos = getNearestChunkPos(position);

    for (auto& [key, chunk]: chunks) {
        glm::vec3 chunk_pos = chunk.getPosition();
        chunk_pos -= pos;
        chunk_pos = glm::abs(chunk_pos);

        if (chunk_pos.x > UNLOAD_DISTANCE || chunk_pos.y > UNLOAD_DISTANCE || chunk_pos.z > UNLOAD_DISTANCE) {
            m_setupQueue.erase(std::remove(m_setupQueue.begin(), m_setupQueue.end(), &chunk), m_setupQueue.end());
            m_renderQueue.erase(std::remove(m_renderQueue.begin(), m_renderQueue.end(), &chunk), m_renderQueue.end());
            chunks.erase(key);
        }
    }

}

void ChunkManager::renderChunks(glm::vec3 position) {

    glm::vec3 pos = getNearestChunkPos(position);

    if(m_renderQueue.size() > 0) {
        for(int i=0; i<m_renderQueue.size(); i++) {

            glm::vec3 chunk_pos = m_renderQueue[i]->getPosition();
            chunk_pos -= pos;
            chunk_pos = glm::abs(chunk_pos);

            if(chunk_pos.x<DRAW_DISTANCE && chunk_pos.y<DRAW_DISTANCE && chunk_pos.z<DRAW_DISTANCE) {
                m_renderQueue[i]->DrawChunk();
            }
        }
    }
}

void ChunkManager::chunkUpdate(glm::vec3 position) {
    //loadNewChunks(position);
    //updateChunks();
    //setupChunks();
}

void ChunkManager::chunkRender(glm::vec3 position) {
    //unloadChunks(position);
    //renderChunks(position);
}