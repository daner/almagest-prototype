project(Demo CXX)

find_package(OpenCV REQUIRED)

include_directories(${ALMAGEST_EXTERNAL_DIR}/shapelib-1.3.0)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${ALMAGEST_EXTERNAL_DIR}/glfw/include)
include_directories(${ALMAGEST_EXTERNAL_DIR}/glm/include)
include_directories(${ALMAGEST_EXTERNAL_DIR}/glew/include)

file(GLOB_RECURSE DEMO_SOURCES  *.cpp)
file(GLOB_RECURSE DEMO_HEADERS  *.h)


add_definitions(-DGLEW_STATIC)

add_executable(demo ${DEMO_SOURCES} ${DEMO_HEADERS})

target_link_libraries(demo glfw glew ${OpenCV_LIBS})