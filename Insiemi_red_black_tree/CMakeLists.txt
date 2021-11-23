cmake_minimum_required(VERSION 3.20)
project(Insiemi_red_black_tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Insiemi_red_black_tree
        AbstractBinarySearchTree.h
        main.cpp
        NumSet.cpp
        NumSet.h
        RBTree.cpp
        RBTree.h)
