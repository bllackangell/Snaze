cmake_minimum_required(VERSION 3.14)
project(Snaze)

set(CMAKE_CXX_STANDARD 11)

include_directories( include )

add_executable(Snaze src/snaze.cpp)