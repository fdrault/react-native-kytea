add_subdirectory(liblinear)

set(CURRENT_PATH "${KYTEA_SOURCE_DIR}/src/lib")

# Define the sources
set(kytea_sources
    ${CURRENT_PATH}/kytea.cpp
    ${CURRENT_PATH}/general-io.cpp
    ${CURRENT_PATH}/corpus-io-prob.cpp
    ${CURRENT_PATH}/corpus-io-eda.cpp
    ${CURRENT_PATH}/corpus-io-full.cpp
    ${CURRENT_PATH}/corpus-io-part.cpp
    ${CURRENT_PATH}/corpus-io-tokenized.cpp
    ${CURRENT_PATH}/corpus-io-raw.cpp
    ${CURRENT_PATH}/corpus-io.cpp
    ${CURRENT_PATH}/model-io.cpp
    ${CURRENT_PATH}/string-util.cpp
    ${CURRENT_PATH}/kytea-model.cpp
    ${CURRENT_PATH}/kytea-config.cpp
    ${CURRENT_PATH}/kytea-lm.cpp
    ${CURRENT_PATH}/feature-io.cpp
    ${CURRENT_PATH}/dictionary.cpp
    ${CURRENT_PATH}/feature-lookup.cpp
    ${CURRENT_PATH}/kytea-util.cpp
    ${CURRENT_PATH}/kytea-string.cpp
    ${CURRENT_PATH}/kytea-struct.cpp
)

# Include native header files
include_directories(
    ${KYTEA_SOURCE_DIR}/src/include
    ${KYTEA_SOURCE_DIR}/src/include/kytea
)

# Define PKGDATADIR
add_compile_definitions(PKGDATADIR="${KYTEA_SOURCE_DIR}/data")

# Create the library
add_library(libkytea ${kytea_sources})

# Link against liblinear
target_link_libraries(libkytea PUBLIC liblinear)
