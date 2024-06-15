cmake_minimum_required(VERSION 3.9.0)
project(ReactNativeMmkv)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)

# Compile sources
add_library(
        react-native-kytea
        SHARED
        ../cpp/test.cpp
)

# Add headers search paths
#target_include_directories(react-native-mmkv PUBLIC ../MMKV/Core)
#target_include_directories(react-native-mmkv PUBLIC ../cpp)

# Add MMKV core dependency
#add_subdirectory(../MMKV/Core core)


target_link_libraries(
        react-native-kytea
        android                     # <-- Android JNI core
        react_codegen_KyteaSpec    # <-- Generated Specs from CodeGen
)