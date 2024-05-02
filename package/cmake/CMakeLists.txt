cmake_minimum_required(VERSION 3.5)
project(Kytea)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

# Define the root directory of Kytea library source files
set(KYTEA_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../kytea")

add_subdirectory(src)
