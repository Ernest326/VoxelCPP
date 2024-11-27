#include "chunk_manager.hpp"

ChunkManager::ChunkManager() {
    //CAUSE CRASH!!
    //chunks.emplace(std::make_tuple(0, 0, 1), std::move(Chunk(0,0,1)));
    chunks.insert({std::make_tuple(0, 0, 1), std::make_shared<Chunk(0,0,1)>});
    chunks.at(std::make_tuple(0, 0, 1)).setup();
}

ChunkManager::~ChunkManager() {

}

void update(glm::vec3 playerPos) {

}

void render() {
    
}

glm::vec3 ChunkManager::getNearestChunkPos(glm::vec3 real_pos) {

    int x = round(real_pos.x/16);
    int y = round((real_pos.y-8)/16);
    int z = round(real_pos.z/16);

    return glm::vec3(x, y, z);
}