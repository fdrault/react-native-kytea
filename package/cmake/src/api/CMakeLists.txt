set(CURRENT_PATH "${KYTEA_SOURCE_DIR}/src/api")

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
