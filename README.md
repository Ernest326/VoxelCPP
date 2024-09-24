# VoxelCPP
A simple Voxel Engine project I built for fun and learning, and also as a way for me to practice problem-solving skills, memory managment and optimisations  
> (I am probably going to go insane trying to implement voxels and having it optimized)

Project uses OpenGL and GLFW, with glad as the wrangler  
Other libraries included are:  
glm - Used for math/projection stuff  
stb_image - Loading images for textures  
imgui - GUI implementation for debugging  


## Compilation:
Download [CMake](https://cmake.org/) and run the build script for your platform

For GNU on Windows, you'll have to download mingw either through [mysys2](https://www.msys2.org/) or directly from the [mingw site](https://www.mingw-w64.org/)  
You can also have Visual Studio downloaded and run the "BuildWindows.bat" script in order to compile a project and build from there  
On Unix-like operating systems, you may need to install ninja in order to build  

So far just tested on a Fedora Linux machine and Windows 11 machine without any problems :D


## TODO:
- Chunk loading
    - Find a way to check how many voxels we are rendering, then maybe try to draw using glDrawArraysInstanced()
- Work on Voxel class
    - Generate buffers, regenerate buffers to optimize, block types, etc.
- LOADSssss of optimizing (culling, lowering tris as much as possible, entity optimization)


## Future plans:
- Procedular terrain generation (Thinking of using a seeded simplex noise implementation with multiple octaves)
- Breaking/Placing blocks
- Physics implementations
- Water?
- Just make fucking minecraft at this point lol