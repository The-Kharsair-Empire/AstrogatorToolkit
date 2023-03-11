cmake_minimum_required(VERSION 3.15)
project(AstrogatorToolkit)

file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/matplotplusplus ${CMAKE_SOURCE_DIR}/build/external/matplotplusplus) # this is where cmake know to pull the binary
add_subdirectory(${CMAKE_SOURCE_DIR}/AstrodynamicsToolkit ${CMAKE_SOURCE_DIR}/build/AstrodynamicsToolkit)
add_subdirectory(${CMAKE_SOURCE_DIR}/TrackingStationToolkit ${CMAKE_SOURCE_DIR}/build/TrackingStationToolkit)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_SOURCE_DIR}/external/matplotplusplus/sources
    PUBLIC ${CMAKE_SOURCE_DIR}/AstrodynamicsToolkit/include
    PUBLIC ${CMAKE_SOURCE_DIR}/TrackingStationToolkit/include
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC matplot 
    PUBLIC AstrodynamicsToolkit 
    PUBLIC TrackingStationToolkit
)


