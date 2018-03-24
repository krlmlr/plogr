cmake_minimum_required(VERSION 3.6)
project(plogr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(R_LIBRARY "~/R-library")
set(R_INCLUDE "/usr/share/R/include")

include_directories(${R_INCLUDE})
include_directories(inst/include)
include_directories(src)

add_definitions(-D__CLION__)

file(GLOB SOURCE_FILES src/*.cpp src/*.c)
add_library(plogr ${SOURCE_FILES})

add_custom_target(
    Rinstall
    # Using MAKEFLAGS=-j$(nproc) didn't work
    COMMAND MAKEFLAGS=-j8 nice R CMD INSTALL --libs-only --no-test-load ${plogr_SOURCE_DIR}
)
