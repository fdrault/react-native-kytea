
# Mirror path between cmake and kytea path
set(CURRENT_PATH "${KYTEA_SOURCE_DIR}/src/bin")

# Define the sources
set(kytea_executable_sources
    ${CURRENT_PATH}/run-kytea.cpp
)

set(train_kytea_executable_sources
    ${CURRENT_PATH}/train-kytea.cpp
)

# Include native header files
include_directories(
    ${KYTEA_SOURCE_DIR}/src/include
)

# Create the executables
add_executable(kytea ${kytea_executable_sources})
add_executable(train-kytea ${train_kytea_executable_sources})

# Link against libkytea
target_link_libraries(kytea PUBLIC libkytea)
target_link_libraries(train-kytea PUBLIC libkytea)
