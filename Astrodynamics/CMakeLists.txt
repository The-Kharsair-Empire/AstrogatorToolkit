cmake_minimum_required(VERSION 3.15)
project(Astrodynamics)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# add_library(${PROJECT_NAME} ${SOURCES})
add_library(${PROJECT_NAME} src/AstrodynamicsTool.cpp  src/OrbitPropagator.cpp)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# target_link_libraries(${PROJECT_NAME}
#     PUBLIC Astrodynamics 
# )
