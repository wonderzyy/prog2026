cmake_minimum_required(VERSION 3.16)
project(tv_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(tv_lab
    main.cpp
    tv.cpp
    tv2.cpp
)

target_include_directories(tv_lab PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
