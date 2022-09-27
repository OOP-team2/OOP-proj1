cmake_minimum_required(VERSION 3.23)
project(OOP_proj1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_proj1
        Ingredient.cpp
        main.cpp
        PlanManager.cpp
        PlanManager.h Plan.cpp Plan.h Date.cpp Date.h)
