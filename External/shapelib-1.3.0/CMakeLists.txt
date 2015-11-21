project(Shapelib)

set(CMAKE_CXX_FLAGS "/nologo /MD /DSHAPELIB_DLLEXPORT /D_CRT_SECURE_NO_WARNINGS")
	
set(SHAPELIB_SOURCES shpopen.c shptree.c dbfopen.c safileio.c)
set(SHAPELIB_HEADERS shapefil.h)

add_definitions(${CMAKE_CXX_FLAGS})

add_library(shapelib STATIC ${SHAPELIB_SOURCES} ${SHAPELIB_HEADERS})
set_target_properties(shapelib PROPERTIES FOLDER "External")