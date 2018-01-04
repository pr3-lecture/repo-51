# cmake_minimum_required(VERSION <specify CMake version here>)
project(crypter)

set(CMAKE_CXX_STANDARD 11)

add_executable(crypter
        crypto.c
        crypto.h)
