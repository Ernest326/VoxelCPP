#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "buffers/buffers.hpp"
#include "shader.hpp";

class Voxel {

private:
    glm::vec3 position;
    unsigned short block_type;

public:
    Voxel();
    Voxel(glm::vec3 position);
    Voxel(glm::vec3 position, unsigned short block_type);

    void Draw();
    void Translate(glm::vec3 pos) { position=pos; }

    glm::vec3 getPosition() const { return position; }
    int getType() const { return block_type; }

};