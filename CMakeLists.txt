cmake_minimum_required(VERSION 3.3)
project(randomGraph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graph.cpp Graph.h ErdosRenyi.h ErdosRenyi.cpp Vertex.h Vertex.cpp header.h BarabasiAlbert.cpp BarabasiAlbert.h RandomGeometric.cpp RandomGeometric.h)
add_executable(randomGraph ${SOURCE_FILES})