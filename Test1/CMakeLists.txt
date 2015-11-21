project(Test1)

include_directories(${ALMAGEST_EXTERNAL_DIR}/shapelib-1.3.0)

set(TEST1_SOURCES main.cpp)

add_executable(test1 ${TEST1_SOURCES})

target_link_libraries(test1 shapelib)