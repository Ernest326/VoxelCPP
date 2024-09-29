#pragma once
#include "chunk.hpp"

class ChunkManager {

private:
    std::vector<Chunk> m_loadlist;
    std::vector<Chunk> m_renderlist;
};