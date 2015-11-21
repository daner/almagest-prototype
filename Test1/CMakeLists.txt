project(Test1 CXX)

include_directories(${ALMAGEST_EXTERNAL_DIR}/shapelib-1.3.0)

file(GLOB_RECURSE TEST1_SOURCES  *.cpp)
file(GLOB_RECURSE TEST1_HEADERS  *.h)

add_executable(test1 ${TEST1_SOURCES} ${TEST1_HEADERS})

target_link_libraries(test1 shapelib)