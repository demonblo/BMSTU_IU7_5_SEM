cmake_minimum_required(VERSION 3.5)

project(lab_1)

set(SOURCES
	main.cpp
	levenstein.cpp
	../matrix.hpp
	../profile.hpp
)

set(HEADERS
	levenstein.h
)

add_executable(app ${SOURCES} ${HEADERS})

set_target_properties(
	app PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS "-Wall;-Werror;-O0"
)

	