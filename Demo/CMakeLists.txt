project(Demo CXX)

find_package(OpenGL REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${ALMAGEST_EXTERNAL_DIR}/glfw/include)
include_directories(${ALMAGEST_EXTERNAL_DIR}/glm/include)
include_directories(${ALMAGEST_EXTERNAL_DIR}/glew/include)

file(GLOB DEMO_SOURCES  Sources/*.cpp)
file(GLOB DEMO_HEADERS  Sources/*.h)

file(GLOB_RECURSE VERTEX_SHADERS *.vert)
file(GLOB_RECURSE FRAGMENT_SHADERS *.frag)

file(GLOB OGL_SOURCES Sources/OGL/*.cpp)
file(GLOB OGL_HEADERS Sources/OGL/*.h)

source_group(Shaders FILES ${VERTEX_SHADERS} ${FRAGMENT_SHADERS})
source_group(Sources FILES ${DEMO_SOURCES} ${DEMO_HEADERS})
source_group(Sources\\OGL FILES ${OGL_SOURCES} ${OGL_HEADERS})

add_definitions("/MP")
add_definitions(-DGLEW_STATIC)
add_definitions(-D__WIN32__)

add_executable(demo ${DEMO_SOURCES} ${DEMO_HEADERS} ${VERTEX_SHADERS} ${FRAGMENT_SHADERS} ${OGL_SOURCES} ${OGL_HEADERS})

add_custom_target(COPY ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources $<TARGET_FILE_DIR:demo>/Resources)

target_link_libraries(demo glfw glew ${OpenCV_LIBS})