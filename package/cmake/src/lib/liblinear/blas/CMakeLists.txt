# Mirror path between cmake and kytea path
file(RELATIVE_PATH relative_path ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_LIST_DIR})
set(CURRENT_PATH "${KYTEA_SOURCE_DIR}/src/lib/liblinear/blas")

# Define the sources
set(libblas_sources
    ${CURRENT_PATH}/blas.h
    ${CURRENT_PATH}/blasp.h
    ${CURRENT_PATH}/dnrm2.c
    ${CURRENT_PATH}/daxpy.c
    ${CURRENT_PATH}/ddot.c
    ${CURRENT_PATH}/dscal.c
)

# Create the library
add_library(libblas ${libblas_sources})