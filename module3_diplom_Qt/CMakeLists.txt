cmake_minimum_required(VERSION 3.5)

project(module3_diplom_Qt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(RaceDynamicLib SHARED
    src/air_mt.cpp
    src/boots.cpp
    src/broom.cpp
    src/camel.cpp
    src/camel_fast.cpp
    src/carpet.cpp
    src/centaurus.cpp
    src/eagle.cpp
    src/ground_mt.cpp
    src/mt.cpp
    src/mt_profile.cpp
    src/race_air.cpp
    src/race.cpp
    src/race_ground.cpp
)

target_include_directories(RaceDynamicLib PRIVATE include)

add_executable(RaceExe main.cpp)

target_link_libraries(RaceExe RaceDynamicLib)
