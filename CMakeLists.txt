cmake_minimum_required(VERSION 3.23)
project(Assignment_one_tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Assignment_one_tests
        driver.h
        driver.cpp
        Bone.cpp
        Bone.h
        ChickenYard.h
        ChickenYard.cpp
        Player.h
        Player.cpp redo/Player.h redo/Bone.h redo/ChickenYard.h redo/main.h redo/Player.cpp redo/ChickenYard.cpp redo/Bone.cpp)
