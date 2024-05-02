# Mirror path between cmake and kytea path
file(RELATIVE_PATH relative_path ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_LIST_DIR})
set(CURRENT_PATH "${KYTEA_SOURCE_DIR}/${relative_path}")

# Define the sources
set(api_executable_sources
    "${CURRENT_PATH}/api-example.cpp"
)

# Include native header files
include_directories(
    ${KYTEA_SOURCE_DIR}/src/include
)

# Create the executables
add_executable(api-example ${api_executable_sources})

# Link against libkytea
target_link_libraries(api-example PUBLIC libkytea)
