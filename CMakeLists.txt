cmake_minimum_required(VERSION 4.0)

project(Algor)

file(GLOB_RECURSE ALGOR_SOURCES
    CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c" 
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_library(algor ${ALGOR_SOURCES})

add_subdirectory(test)
