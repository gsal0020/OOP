cmake_minimum_required(VERSION 3.10.0)
project(cdemo VERSION 0.1.0 LANGUAGES C CXX)
set(SOURCES1 main.cpp)
set(CMAKE_CXX_STANDARD 20)
add_executable(cdemo ${SOURCES1})
include(CTest)
enable_testing()

