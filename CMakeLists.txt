cmake_minimum_required (VERSION 3.0) 

project (Almagest) 

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_PREFIX_PATH "D:/Installs" CACHE PATH "Installs search directory")
set(ALMAGEST_DIR ${PROJECT_SOURCE_DIR})
set(ALMAGEST_EXTERNAL_DIR ${ALMAGEST_DIR}/External)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(External)
add_subdirectory(Demo)