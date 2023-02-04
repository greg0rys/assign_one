cmake_minimum_required(VERSION 3.23)
project(assign_one)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        assign_one
        main.h
        main.cpp
        Bone.cpp
        Bone.h
        ChickenYard.h
        ChickenYard.cpp
        Player.h
        Player.cpp
        Game.h
        Game.cpp
        Field.h
        Field.cpp
        driverA
        driverB driverB/DLL.cpp driverB/DLL.h)
