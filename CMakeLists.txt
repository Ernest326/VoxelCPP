#CMake version - a lot of packages complain about being deprecated for versionm <3.5 so yee :P
cmake_minimum_required(VERSION 3.14.0)

#Include .env paths
include(./.env.cmake OPTIONAL RESULT_VARIABLE LOCAL_ENV)
message(STATUS "Local .env.cmake: ${LOCAL_ENV}")

#Basic CMake Stuff
set(NAME VoxelCPP)

message(STATUS "using ${CMAKE_GENERATOR}")
#Check if using MinGW compiler
if (CMAKE_GENERATOR STREQUAL "MinGW Makefiles")
    if (NOT MINGW_PATH) 
      message(FATAL_ERROR "MINGW_PATH not set in .env.cmake")
    endif()
    set(USE_MINGW "True")
    set(CMAKE_C_COMPILER ${MINGW_PATH}/bin/gcc.exe)
    set(CMAKE_CXX_COMPILER  ${MINGW_PATH}/bin/g++.exe)
endif()

project(${NAME} VERSION 1.0)

#Disable unecessary stuff
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

#Add libraries
add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/stb_image)

#Add all src files
include_directories(thirdparty)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

#Set main.cpp as executable
add_executable(${PROJECT_NAME} ${SOURCES})

#Version setting + build folder setting
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

#Includes
target_include_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}/src
  thirdparty/glfw/include
  thirdparty/glm
  thirdparty/glad/include
  thirdparty/stb_image/include
  include
)

#Copy shaders/res folder to build
file(COPY src/shaders DESTINATION ./)
file(COPY src/res DESTINATION ./)

#Building
if (WIN32)
  message(STATUS "CREATING BUILD FOR WINDOWS")

  if (USE_MINGW)
  target_include_directories(${PROJECT_NAME} PUBLIC
    ${MINGW_PATH}/include
  )
  target_link_directories(${PROJECT_NAME} PUBLIC
    ${MINGW_PATH}/lib
  )
  endif()

  target_link_libraries(${PROJECT_NAME} glfw glad stb_image shell32 user32 opengl32 winmm gdi32)
  target_link_directories(${PROJECT_NAME} PUBLIC
    ${GLFW_LIB}
  )

elseif (UNIX)
    message(STATUS "CREATING BUILD FOR UNIX")
    target_link_libraries(${PROJECT_NAME} glfw glad stb_image dl)
elseif (APPLE)
    message(STATUS "CREATING BUILD FOR MAC")
    target_link_libraries(${PROJECT_NAME} glfw glad stb_image dl)
endif()