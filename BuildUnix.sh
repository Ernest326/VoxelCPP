#!/bin/bash
mkdir -p build
cd build
cmake -S ../ -B . -D GLFW_BUILD_DOCS=OFF
make && ./VoxelCPP
cd ..