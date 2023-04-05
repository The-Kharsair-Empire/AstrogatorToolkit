cmake_minimum_required(VERSION 3.15)
project(AstrogatorToolkit)

file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# set(Astrodynamics Astrodynamics)
# set(GroundTrack GroundTrack)
add_subdirectory(${CMAKE_SOURCE_DIR}/Astrodynamics ${CMAKE_SOURCE_DIR}/build/Astrodynamics)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/matplotplusplus ${CMAKE_SOURCE_DIR}/build/external/matplotplusplus) # this is where cmake know to pull the binary
add_subdirectory(${CMAKE_SOURCE_DIR}/GroundTrack ${CMAKE_SOURCE_DIR}/build/GroundTrack)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_SOURCE_DIR}/external/matplotplusplus/sources
    PUBLIC ${CMAKE_SOURCE_DIR}/Astrodynamics/include
    PUBLIC ${CMAKE_SOURCE_DIR}/GroundTrack/include
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC matplot 
    PUBLIC Astrodynamics 
    PUBLIC GroundTrack
)


