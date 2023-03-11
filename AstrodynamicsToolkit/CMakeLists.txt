cmake_minimum_required(VERSION 3.15)
project(AstrodynamicsToolkit)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} 
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)
