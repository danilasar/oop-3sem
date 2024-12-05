cmake_minimum_required(VERSION 3.26)
project(240907_oop_realnums)

set(CMAKE_CXX_STANDARD 23)

add_executable(240907_oop_realnums main.cpp
        real/real.h real/real.cpp
        real/arithmetic.cpp
        real/comparators.cpp
        real/arithmetic_int.cpp
        real/utils.cpp
        list.h
        errors/error.cpp
        errors/error.h
        errors/memory_error.cpp
        errors/memory_error.h
        errors/file_error.cpp
        errors/file_error.h)
