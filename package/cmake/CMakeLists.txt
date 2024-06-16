cmake_minimum_required(VERSION 3.5)
project(Kytea)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

message("KYTEA_SOURCE_DIR ${KYTEA_SOURCE_DIR}")
# Define the root directory of Kytea library source files
if(NOT DEFINED KYTEA_SOURCE_DIR)
    set(KYTEA_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../kytea")
endif()


add_subdirectory(src)
