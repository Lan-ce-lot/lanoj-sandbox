#cmake_minimum_required(VERSION 3.17)
cmake_minimum_required(VERSION 3.16)
project(Lanoj_Sandbox)
LINK_LIBRARIES("pthread")
LINK_LIBRARIES("seccomp")
set(CMAKE_CXX_STANDARD 14)

add_executable(Lanoj_Sandbox


        main.cpp)