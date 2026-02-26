cmake_minimum_required(VERSION 3.10.0)
project(classes02 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
  add_compile_options(/W3 /EHsc)
else()
  add_compile_options(-Wall -Wextra -pedantic)
endif()

add_executable(cat
  cat.cpp
  cat_main.cpp
)

add_executable(library
  library.cpp
  library_main.cpp
)
