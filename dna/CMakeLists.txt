cmake_minimum_required(VERSION 3.14)
project(dna)

set(CMAKE_CXX_STANDARD 98)

add_executable(dna main.cpp
        DnaSequence.cpp
        DnaSequence.h
        )