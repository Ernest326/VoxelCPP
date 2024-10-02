#pragma once
#include "chunk.hpp"
#include <unordered_map>
#include <tuple>

//Maximum number of draw calls per frame
#define MAX_DRAW=6;

//Distance stuff
#define LOAD_DISTANCE=4;
#define DRAW_DISTANCE=3;
#define UNLOAD_DISTANCE=8;

//Hash function for tuple, since std::tuple doesnt have a default hash function and unordered_map requires a std::hash for mapping stuff
//Found this on a stack overflow thread :)
struct tuple_hash {
    template <typename T>
    std::size_t operator()(const std::tuple<T, T, T>& t) const {
        // Hash combine technique
        std::size_t seed = 0;
        seed ^= std::hash<T>()(std::get<0>(t)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<T>()(std::get<1>(t)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<T>()(std::get<2>(t)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

class ChunkManager {

private:
    std::unordered_map<std::tuple<int, int, int>, Chunk, tuple_hash> chunks;
    std::vector<Chunk*> m_renderQueue;
    std::vector<Chunk*> m_updateQueue;
    std::vector<Chunk*> m_unloadQueue;

    void loadNewChunks(glm::vec3 position);
    void updateChunks(glm::vec3 position);
    void unloadChunks(glm::vec3 position);
    void renderChunks(glm::vec3 position);


public:
    glm::vec3 getNearestChunkPos(glm::vec3 real_pos);
    void chunkUpdate(glm::vec3 position);
    ChunkManager();
    ~ChunkManager();

};