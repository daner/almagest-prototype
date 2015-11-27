project(Demo CXX)

find_package(OpenGL REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${ALMAGEST_EXTERNAL_DIR}/glfw/include)
include_directories(${ALMAGEST_EXTERNAL_DIR}/glm/include)
include_directories(${ALMAGEST_EXTERNAL_DIR}/glew/include)

file(GLOB_RECURSE DEMO_SOURCES  *.cpp)
file(GLOB_RECURSE DEMO_HEADERS  *.h)

file(GLOB_RECURSE VERTEX_SHADERS *.vert)
file(GLOB_RECURSE FRAGMENT_SHADERS *.frag)

source_group(Shaders FILES ${VERTEX_SHADERS} ${FRAGMENT_SHADERS})
source_group(Sources FILES ${DEMO_SOURCES})
source_group(Headers FILES ${DEMO_HEADERS})

add_definitions("/MP")
add_definitions(-DGLEW_STATIC)
add_definitions(-D__WIN32__)

add_executable(demo ${DEMO_SOURCES} ${DEMO_HEADERS} ${VERTEX_SHADERS} ${FRAGMENT_SHADERS})

add_custom_target(COPY ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources $<TARGET_FILE_DIR:demo>/Resources)

target_link_libraries(demo glfw glew ${OpenCV_LIBS})