cmake_minimum_required(VERSION 3.11)
project(TrackingStationToolkit)

set(CMAKE_CXX_STANDARD 23)

add_executable(TrackingStationToolkit main.cpp ../external/olcPixelGameEngine.h)
