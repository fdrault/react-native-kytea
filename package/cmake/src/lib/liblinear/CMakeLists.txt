add_subdirectory(blas)

set(CURRENT_PATH "${KYTEA_SOURCE_DIR}/src/lib/liblinear")

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