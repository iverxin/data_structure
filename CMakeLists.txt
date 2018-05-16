#CMake oldest versions required
cmake_minimum_required (VERSION 2.8)

#debug massage
#SET(CMAKE_BUILD_TYPE "Debug")
#SET(CMAKE_CXX_FLAGS_DEBUG “$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall)

# project messages
project(data_structure)

#find all srources in currcent folder 
aux_source_directory(. DIR_SRCS)

#the output target
add_executable(a.out ${DIR_SRCS})

