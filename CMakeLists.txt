cmake_minimum_required(VERSION 3.3)
project(SuperNumber)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    SuperNumber.cpp
    SuperNumber.hpp
    main.cpp)

add_executable(SuperNumber ${SOURCE_FILES})