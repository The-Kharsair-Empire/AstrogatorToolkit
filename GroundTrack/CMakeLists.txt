cmake_minimum_required(VERSION 3.15)
project(GroundTrack)

find_package(X11 REQUIRED)

file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/../external/olcPixelGameEngine
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC ${X11_LIBRARIES}
    PUBLIC GLX
    PUBLIC GL
)
