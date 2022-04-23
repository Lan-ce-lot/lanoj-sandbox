cmake_minimum_required(VERSION 3.16)
project(Lanoj_Sandbox)
LINK_LIBRARIES("pthread")
LINK_LIBRARIES("seccomp")
set(CMAKE_CXX_STANDARD 14)

add_executable(
        Lanoj_Sandbox
        main.cpp
        src/common/common.cpp
        src/common/common.h
        src/time/time.cpp
        src/time/time.h
        src/system/system.cpp
        src/system/system.h
        src/child/child.cpp
        src/child/child.h
        src/judge/judge.cpp
        src/judge/judge.h
        src/guard/guard.cpp
        src/guard/guard.h
        )