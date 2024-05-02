add_subdirectory(blas)

# Mirror path between cmake and kytea path
file(RELATIVE_PATH relative_path ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_LIST_DIR})
set(CURRENT_PATH "${KYTEA_SOURCE_DIR}/${relative_path}")

# Define the sources
set(liblinear_sources
    ${CURRENT_PATH}/tron.cpp
    ${CURRENT_PATH}/tron.h
    ${CURRENT_PATH}/linear.cpp
    ${CURRENT_PATH}/linear.h
)

# Create the library
add_library(liblinear ${liblinear_sources})

# Link against blas
target_link_libraries(liblinear PUBLIC libblas)