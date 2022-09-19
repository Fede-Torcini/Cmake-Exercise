cmake_minimum_required(VERSION 3.24.1)

project(CmakeTuto)

file(GLOB_RECURSE SRC src/*.cpp)

add_executable(CmakeTuto ${SRC})

include_directories(include)