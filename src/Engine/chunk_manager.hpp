#pragma once
#include "chunk.hpp"
#include <iostream>
#include <memory>
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
    const int VIEW_DISTANCE = 4;
    std::unordered_map<std::tuple<int, int, int>, std::unique_ptr<Chunk>, tuple_hash> chunks;

public:
    glm::vec3 getNearestChunkPos(glm::vec3 real_pos);
    void update(glm::vec3 playerPos);
    void draw(glm::vec3 playerPos);
    ChunkManager();
    ~ChunkManager();
};