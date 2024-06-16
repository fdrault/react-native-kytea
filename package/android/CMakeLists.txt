cmake_minimum_required(VERSION 3.9.0)
project(ReactNativeKytea)

 message("ReactNativeKytea android/CMakeLists.txt")



set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)

# Define the root directory of Kytea library source files
set(KYTEA_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../kytea")

# Compile sources
add_library(
        react-native-kytea
        SHARED
        ../cpp/NativeKyteaModule.cpp
)

# Add headers search paths
target_include_directories(react-native-kytea PUBLIC ../cpp)
target_include_directories(react-native-kytea PUBLIC ../kytea/src/include)

# Add Kytea dependency
add_subdirectory(../cmake Kytea)


target_link_libraries(
        react-native-kytea
        libkytea
        android                     # <-- Android JNI core
        react_codegen_KyteaSpec    # <-- Generated Specs from CodeGen
)