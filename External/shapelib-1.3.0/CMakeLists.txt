project(Shapelib C)

option(SHAPELIB_BUILD_TOOLS "Build shapelib tools" OFF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /nologo /Ox /MD /DSHAPELIB_DLLEXPORT /D_CRT_SECURE_NO_WARNINGS /wd4267 /wd4018")

set(SHAPELIB_HEADERS shapefil.h)	
set(SHAPELIB_SOURCES shpopen.c shptree.c dbfopen.c safileio.c)

add_library(shapelib STATIC ${SHAPELIB_SOURCES} ${SHAPELIB_HEADERS})
set_target_properties(shapelib PROPERTIES FOLDER "External")

if(SHAPELIB_BUILD_TOOLS)
	add_executable(shpcreate shpcreate.c)
	target_link_libraries(shpcreate shapelib)

	add_executable(shpadd shpadd.c)
	target_link_libraries(shpadd shapelib)

	add_executable(shpdump shpdump.c)
	target_link_libraries(shpdump shapelib)

	add_executable(shprewind shprewind.c)
	target_link_libraries(shprewind shapelib)

	add_executable(dbfcreate dbfcreate.c)
	target_link_libraries(dbfcreate shapelib)

	add_executable(dbfadd dbfadd.c)
	target_link_libraries(dbfadd shapelib)

	add_executable(dbfdump dbfdump.c)
	target_link_libraries(dbfdump shapelib)

	add_executable(shptest shptest.c)
	target_link_libraries(shptest shapelib)

	add_executable(shputils shputils.c)
	target_link_libraries(shputils shapelib)

	add_executable(shptreedump shptreedump.c)
	target_link_libraries(shptreedump shapelib)

	set_target_properties(shpcreate shpadd shpdump shprewind dbfcreate dbfadd dbfdump shputils shptreedump shptest PROPERTIES FOLDER "External//Shapelib Tools")	
endif()