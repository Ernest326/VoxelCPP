#include "chunk_manager.hpp"

ChunkManager::ChunkManager() {

}

ChunkManager::~ChunkManager() {

}

glm::vec3 ChunkManager::getNearestChunkPos(glm::vec3 real_pos) {

    int x = round(real_pos.x/16);
    int y = round((real_pos.y-8)/16);
    int z = round(real_pos.z/16);

    return glm::vec3(x, y, z);
}


void ChunkManager::loadNewChunks(glm::vec3 position) {

}

void ChunkManager::updateChunks(glm::vec3 position) {

}

void ChunkManager::unloadChunks(glm::vec3 position) {

}

void ChunkManager::renderChunks(glm::vec3 position) {
    
}

void ChunkManager::chunkUpdate(glm::vec3 position) {
    //Do chunk loading shit here
}