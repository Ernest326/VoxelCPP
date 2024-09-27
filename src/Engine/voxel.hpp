#pragma once

//KEEPING THIS CLASS AS OPTIMIZED AS POSSIBLE, WITH AS FEW MEMBERS AS I CAN (Treat more like a data structure than an object)
//LET OTHER CLASSES DO THE WORK SUCH AS DRAWING AND STORING DATA

class Voxel {
public:
    enum BLOCKTYPE {
        GRASS,
        DIRT,
        STONE,
        SAND
    };
private:
    BLOCKTYPE m_block_type;
    bool m_active=true;
public:
    Voxel(BLOCKTYPE block=GRASS) { m_block_type=block; }
    BLOCKTYPE getBlockType() { return m_block_type; }
    void setActive() { m_active=true; }
    bool getActive() { return m_active; }
};