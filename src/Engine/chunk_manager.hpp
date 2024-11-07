#pragma once
#include "chunk.hpp"
#include <iostream>
#include <tuple>
#include <algorithm>
#include <unordered_map>

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
    //Maximum number of setup calls per frame
    int MAX_LOAD=6;
    int LOAD_DISTANCE=4;
    int UNLOAD_DISTANCE=8;
    int DRAW_DISTANCE=3;

    std::unordered_map<std::tuple<int, int, int>, int, tuple_hash> test;
    std::unordered_map<std::tuple<int, int, int>, Chunk, tuple_hash> chunks;
    std::vector<Chunk*> m_renderQueue;
    std::vector<Chunk*> m_setupQueue;

    void loadNewChunks(glm::vec3 position);
    void unloadChunks(glm::vec3 position);
    void renderChunks(glm::vec3 position);
    void setupChunks();
    void updateChunks();


public:
    glm::vec3 getNearestChunkPos(glm::vec3 real_pos);
    void chunkUpdate(glm::vec3 position);
    void chunkRender(glm::vec3 position);

    ChunkManager();
    ~ChunkManager();
};