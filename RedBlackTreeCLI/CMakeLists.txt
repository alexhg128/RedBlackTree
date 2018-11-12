cmake_minimum_required(VERSION 3.12)
project(RedBlackTreeCLI)

set(CMAKE_CXX_STANDARD 14)

add_executable(RedBlackTreeCLI main.cpp Structures/RedBlackTree.cpp Structures/RedBlackTree.h CLI/CLI.cpp CLI/CLI.h)