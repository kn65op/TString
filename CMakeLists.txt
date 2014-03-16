cmake_minimum_required (VERSION 2.8) 

#variables
set(SRC_DIR "Code")
set(DEBUG_BIN_DIR "Debug")
set(RELEASE_BIN_DIR "Release")

#project
project (tstring)

#externial libs

#compiler options
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -fprofile-arcs -ftest-coverage")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

#tests
set(COVERAGE_COMMAND "gcov")

set(CTEST_MEMORYCHECK_COMMAND "valgrind")
set(CTEST_MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --quiet
--tool=memcheck --leak-check=yes --show-reachable=yes
--num-callers=100 --verbose --demangle=yes")

#includes
include_directories(${SRC_DIR})

#files
file(GLOB EXAMPLE_FILES ${SRC_DIR}/*.cpp)
file(GLOB UNIQUE_NAMER_FILES ${SRC_DIR}/UniqueNamer/src/*.cpp)


#executables
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	add_definitions(--coverage)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${DEBUG_BIN_DIR}/")
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${DEBUG_BIN_DIR}/")
elseif (${CMAKE_BUILD_TYPE} STREQUAL "Release")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${RELEASE_BIN_DIR})
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${RELEASE_BIN_DIR})
endif (${CMAKE_BUILD_TYPE} STREQUAL "Debug")

add_library(${PROJECT_NAME} ${UNIQUE_NAMER_FILES})

#test
add_subdirectory(Test)
