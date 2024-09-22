#include "voxel.hpp"

Voxel::Voxel() {
    position = glm::vec3(0,0,0);
}

Voxel::Voxel(glm::vec3 position) {
    this->position = position;
}

Voxel::Voxel(glm::vec3 position, unsigned short block_type) {
    this->position = position;
    this->block_type = block_type;
}